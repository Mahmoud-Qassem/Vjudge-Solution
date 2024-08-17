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

bool calc(vector<int>x1,vector<int>x2){
    int n=x1.size();
    double a=0;

    for(int i=0;i<n;++i){
        double tmp=abs(x1[i]-x2[i]);
        a+=(tmp*tmp);
    }

    a=sqrt(a);
//    cout<<fixed<<setprecision(5);
    double k=int(a);
//    cout<<k<<" "<<a<<endl;
    return k==a;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,d;
    cin>>n>>d;
    vector<vector<int>>v(n,vector<int>(d));
    for(auto&it:v){
        for(auto&ic:it)
        {
            cin>>ic;
        }
    }
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            cnt+=(calc(v[i],v[j]));
        }
    }
    cout<<cnt<<endl;





}
