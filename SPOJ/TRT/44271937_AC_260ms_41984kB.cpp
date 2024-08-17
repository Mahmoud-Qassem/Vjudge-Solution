#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000000000LL
#define clr(v,value) memset(v,value,sizeof(v));
ll n;
const ll MX=2222;
vector<ll>v;
ll dp[MX][MX];
ll solve(ll i,ll j,ll day)
{
    if(i==j)return day*v[i];
    if(i>j)return 0;

    auto&ret=dp[i][j];
    if(~ret)return ret;


    ret=max(ret,solve(i+1,j,day+1)+v[i]*day  );
    ret=max(ret,solve(i,j-1,day+1)+v[j]*day  );

    return ret;





}

int32_t main()
{
    cin>>n;
    clr(dp,-1);
    v=vector<ll>(n);
    for(auto&it:v)cin>>it;
    cout<<solve(0,n-1,1)<<endl;



}
