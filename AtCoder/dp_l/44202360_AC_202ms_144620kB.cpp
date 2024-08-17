#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<long long>v;
const int MX=3001;
long long dp[MX][MX][2];
long long solve(int i=0,int j=n-1,bool f=1)
{
    if(i>j)return 0;
    auto&ret=dp[i][j][f];
    if(ret!=-1)return ret;
    if(f) ret=max({ret,solve(i+1,j,0)+v[i],solve(i,j-1,0)+v[j]});
    else ret=min(solve(i+1,j,1),solve(i,j-1,1));
    return ret;
}
int32_t main ( )
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    v=vector<long long>(n);
    long long sum=0;
    for(auto&it:v)cin>>it,sum+=it;
    cout<<2*solve()-sum<<endl;
}
