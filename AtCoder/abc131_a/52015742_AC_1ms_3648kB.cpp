#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
vector<int>value;
vector<bool>visited;
vector<vector<int>>adj;
vector<vector<int>>values;
void myMerge(vector<int>&v1,vector<int>&v2) {
    vector<int> merged(40);
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(),merged.begin());
    sort(allr(merged));
    for(int i=0; i<20; ++i)v1[i]=merged[i];
}
vector<int>dfs(int node) {
    visited[node]=1;
    vector<int>MAX(20,0);
    MAX[0]=value[node];
    for(auto&ne:adj[node]) {
        if(not visited[ne]) {
            vector<int>current=dfs(ne);
            myMerge(MAX,current);
        }
    }
    values[node]=MAX;
    return MAX;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    string s;
    cin>>s;
    bool ok=0;
    int n=s.size();
    for(int i=0;i<n-1;++i){
        if(s[i]==s[i+1])ok=1;
    }
    if(ok)cout<<"Bad"<<endl;
    else cout<<"Good"<<endl;
}
