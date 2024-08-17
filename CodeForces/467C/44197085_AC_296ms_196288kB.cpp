#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long dp[5001][5001];
vector<long long>v;
long long solve(int idx,int kk)
{
    if(idx>n)return INT_MIN;
    if(kk==0)return 0;

    auto&ret=dp[idx][kk];
    if(~ret)return ret;

    int left=idx,right=m+left-1;
    long long mx=LONG_LONG_MIN;

    if(right<=n)
    mx=solve(right+1,kk-1)+v[right+1]-v[left];
    mx=max(mx,solve(idx+1,kk));
    return ret=mx;

}
int32_t main ( )
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k;
    v=vector<long long>(n+2);
    for(int i=1;i<=n;++i)cin>>v[i];
    for(int i=0;i<=n;++i)v[i]+=v[i-1];
    cout<<solve(0,k);
}
