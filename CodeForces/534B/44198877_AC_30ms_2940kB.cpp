#include<bits/stdc++.h>
using namespace std;
long long v,vv,t,d;
int dp[500][1500];
int solve(int idx,int speed)
{
    if(speed<=0 or idx>t)return -500000;
    if(speed==vv and idx==t)return speed;

    int&ret=dp[idx][speed];
    if(~ret)return ret;
    ret=INT_MIN;
    for(int j=0;j<=d;++j)
        ret=max({ret,solve(idx+1,speed+j)+speed,solve(idx+1,speed-j)+speed});
    return ret;
}
int32_t main ( )
{
    memset(dp,-1,sizeof(dp));
    cin>>v>>vv>>t>>d;
    cout<<solve(1,v);
}