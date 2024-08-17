#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define here cout<<"here"<<endl;
#define pi 3.141592653589793
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO 1e18
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll n,limit;
vector<ll>w;
vector<ll>value;
ll dp[111][100005];
ll knapsack(int idx,ll remain)
{
    if(idx==n)
    {
        if(remain==0)return 0;
        return OO;
    }
    auto&ret=dp[idx][remain];
    if(~ret)return ret;

    ret=knapsack(idx+1,remain);
    if(remain>=value[idx])
        ret=min(ret, w[idx] + knapsack(idx+1,remain-value[idx])) ;
    return ret;
}

int32_t main()
{
    Fast();
    cin>>n>>limit;
    value=vector<ll>(n);
    w=vector<ll>(n);
    ll x=0;
    memset(dp,-1,sizeof(dp));
    for(ll i=0; i<n; ++i)
    {
        cin>>w[i]>>value[i];
        x+=value[i];
    }
    for(int i=x;i>=0;--i)
    {
        // get the min weight which this value can get
        
        if(knapsack(0,i)<=limit)
        return cout<<i<<endl,0;
    }























}
