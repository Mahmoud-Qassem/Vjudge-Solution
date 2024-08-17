#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const long long MX=100009;
long long n,c=0;
vector<pair<long long,long long>>v;
long long dp[MX][2];
vector<string>path;
long long solve(long long idx,long long right)
{
    if(idx==n-1)return 0;

    long long h=v[idx].second;
    long long ph=v[idx-1].second;
    long long x=v[idx].first;
    long long px=v[idx-1].first;
    long long nx=v[idx+1].first;


    auto&ret=dp[idx][right];
    if(~ret)return ret;



    long long best=0;
    // when it could be fell left
    // if the previous did not fall right and there is enough space
    // or the previous one fell right and there is also enough space
    if( (right!=1 and x-h>px)or(right==1 and  x-h > px+ph) )best=max(best,1+solve(idx+1,0));

    if( x+h < nx )best=max(best,1+solve(idx+1,1));
    best=max(best,solve(idx+1,0));
    return ret=best;

}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(dp,-1,sizeof(dp));


    cin>>n;
    v.resize(n);
    for(auto&it:v)cin>>it.first>>it.second;

    sort(v.begin(),v.end());

    if(n==1){return cout<<1<<endl,0;}
    cout<<solve(1,0)+2;








}
