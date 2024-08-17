#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int>v;
int dp[100011][2];
bool solve(int kk,bool me=1)
{
    if(kk==0)return !me;

    auto&ret=dp[kk][me];
    if(~ret)return ret;

    bool var=!me;
    for(int i=0;i<n;++i)
    {
        if(v[i]<=kk and solve(kk-v[i],!me)==me)
        {
            var=me;
            break;
        }
    }
    return ret=var;
}
int32_t main ( )
{
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    v=vector<int>(n);
    for(auto&it:v)cin>>it;
    if(solve(k))
    cout<<"First"<<endl;
    else cout<<"Second"<<endl;

}
