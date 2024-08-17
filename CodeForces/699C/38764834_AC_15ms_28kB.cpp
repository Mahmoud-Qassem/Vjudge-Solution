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
ll n;
long long  dp[111][11];
vector<ll>v;
ll rec(ll idx,ll last)
{
    if(idx==n)return 0LL;
    auto&ret=dp[idx][last];
    if(~ret)return ret;
    ret=0LL;
    if(last!=1 and v[idx]==1)
    {
        ret=max(ret,1+rec(idx+1,1));
    }
    if(last!=2 and v[idx]==2)
    {
        ret=max(ret,1+rec(idx+1,2));
    }
    if(v[idx]==3)
    {
        if(last!=1)
            ret=max(ret,1+rec(idx+1,1));
        if(last!=2)
            ret=max(ret,1+rec(idx+1,2));

    }
    ret=max(ret,rec(idx+1,0LL));
    return ret;
}

int32_t main()
{
    Fast();
    cin>>n;
    v=vector<ll>(n);
    memset(dp,-1,sizeof(dp));
    for(auto&it:v)cin>>it;
    cout<<n-rec(0LL,0LL)<<endl;
























}
