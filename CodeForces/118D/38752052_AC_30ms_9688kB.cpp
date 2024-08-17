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
#define clr(v,x) memset(v,x,sizeof(v))
#define S second
#define OO 1e9
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 100000000
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
//
//ll c=0;
////ll dp[200][50];
//
//
//long long  rec(ll s,ll k)
//{
//    if(not k and not s)return 1;
//    if(not k or not s)return 0;
//
//    auto&ret=dp[s][k];
//    if(~ret)return ret;
//
//    ret=0;
//
//    for(int i=1;i<=s;++i)ret=max(ret,i*rec(s-i,k-1));
//
//    return ret;
//
//}
const int MX=100005;
ll dp[101][101][11][11];
ll k,kk,c;
ll rec(ll n,ll m,int k1,int k2)
{
    if(not n and not m)return 1;
    if(not n and m>kk)return 0;
    if(not m and n>k)return 0;

    auto&ret=dp[n][m][k1][k2];
    if(~ret)return ret%mod;
    ret=0;


    if(k1<k and n)
    {
        ret+=rec(n-1,m,k1+1,0)%mod;
    }
    if(k2<kk and m)
    {
        ret+=rec(n,m-1,0,k2+1)%mod;
    }
    return ret%mod;
}



int32_t main()
{
    Fast();
    ll n,m;
    memset(dp,-1,sizeof(dp));
    cin>>n>>m>>k>>kk;
    cout<<rec(n,m,0,0)%mod<<endl;









}
