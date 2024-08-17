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
#define OO 1e9
#define clr(v,x) memset(v,x,sizeof(v))
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
#define MX 100005 // 1e5+5
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
ll n,cc;
vector<vector<ll>>v;
ll dp[MX][3];
ll rec(ll col,ll x)
{
    if(col==n)return 0;
    ll&ret=dp[col][x];
    if(~ret)return ret;
    ret=0;
    if(x!=0)
    {
        ret=max(ret,v[0][col]+rec(col+1,0) );
        ret=max(ret,rec(col+1,x));
    }
    if(x!=1)
    {
        ret=max(ret,v[1][col]+rec(col+1,1) );
        ret=max(ret,rec(col+1,x));
    }
    return ret;


}


int32_t main()
{
    Fast();
    cin>>n;
    clr(dp,-1);
    v=vector<vector<ll>>(2,vector<ll>(n));
    for(auto&it:v)for(auto&ic:it)cin>>ic;
    cout<<rec(0,2)<<endl;










}
