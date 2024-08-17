#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<long long>v;
long long n,c=0,k;
long long dp[100005];
long long solve(long long idx)
{
    if(idx==n-1)return 0;

    auto&ret=dp[idx];
    if(~ret)return ret;
    long long best=INT_MAX;


    for(int i=1; i<=2; ++i)
    {
        if(idx+i<n)
            best=min(best,abs(v[idx]-v[idx+i])+solve(idx+i));
    }

    return ret=best;




}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);



    memset(dp,-1,sizeof(dp));
    cin>>n;
    v.resize(n);
    for(auto&it:v)cin>>it;
    cout<<solve(0)<<endl;

}
