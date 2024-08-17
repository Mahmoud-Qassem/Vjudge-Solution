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
const int MX=1005;
int n,m;
vector<vector<char>>v;
bool valid(int x,int y)
{
    return x>=0 and y>=0 and x<n and y<m and v[x][y]=='.';
}
ll dp[MX][MX],c;
ll rec(int x,int y,ll wys=0)
{
//    cout<<++c<<endl;
    if(x==n-1 and y==m-1)
    {
        return 1;
    }
    auto&ret=dp[x][y];
    if(~ret)return ret%mod;
    ret=0;
    if(valid(x+1,y))
    {
        ret+=rec(x+1,y,wys)%mod;
    }
    if(valid(x,y+1))
    {
        ret+=rec(x,y+1,wys)%mod;
    }
    return ret%mod;
}
int32_t main()
{
    Fast();
    cin>>n>>m;
    clr(dp,-1);
    v=vector<vector<char>>(n,vector<char>(m));
    for(auto&it:v)for(auto&ic:it)cin>>ic;
    cout<<rec(0,0)%mod<<endl;










}
