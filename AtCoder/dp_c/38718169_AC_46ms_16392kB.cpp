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
const int MX=1e5+5;
int dp[MX][4],n,cnt;
vector<vector<int>>v;
int rec(int idx,int last)
{
    if(idx==n)return 0;
//    cout<<++cnt<<endl;
    auto&ret=dp[idx][last];
    if(~ret)return ret;
    int m1=0;
    int m2=0;
    int m3=0;
    if(last!=0)
        m1=v[idx][0]+rec(idx+1,0);
    if(last!=1)
        m2=v[idx][1]+rec(idx+1,1);
    if(last!=2)
        m3=v[idx][2]+rec(idx+1,2);

    return ret=max({m1,m2,m3});
}
int32_t main()
{
    Fast();
    cin>>n;
    memset(dp,-1,sizeof(dp));
    v=vector<vector<int>>(n,vector<int>(3));
    for(int i=0;i<n;++i)cin>>v[i][0]>>v[i][1]>>v[i][2];
    cout<<rec(0,3)<<endl;;










}
