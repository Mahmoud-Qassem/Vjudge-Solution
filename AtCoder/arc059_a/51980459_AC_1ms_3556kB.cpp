#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
const int M=1e9+5;
//bool valid(int x,int y) {
//    return (x>=1 and y>=1 and x<=n and y<=m);
//}
int dx[]= {0,0,-1,1,1,1,-1,-1};
int dy[]= {1,-1,0,0,1,-1,-1,1};
int calc(vector<int>v,int x){
    int cost=0;
    for(int i=0;i<v.size();++i){
        cost+=(v[i]-x)*(v[i]-x);
    }
    return cost;
}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto&it:v)cin>>it;
    int ans=INT_MAX;
    for(int i=-1000;i<=1000;++i){
        ans=min(ans,calc(v,i));
    }
    cout<<ans<<endl;




}

