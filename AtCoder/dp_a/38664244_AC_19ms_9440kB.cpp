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
//vector<vector<int>>v(20,vector<int>(3));
//ll cnt=0,n;
////vector<vector<int>>mem(20,vector<int>(3,-1));
//
//ll rec(int r,int last)
//{
//    cout<<++cnt<<endl;
//    if(r==n)return 0;
//    int m1=INT_MAX;
//    int m2=INT_MAX;
//    int m3=INT_MAX;
//
//    auto&ret=mem[r][last];
//    if(~ret)return ret;
//
//    if(r==0||last!=0)
//        m1=v[r][0]+rec(r+1,0);
//    if(r==0||last!=1)
//        m2=v[r][1]+rec(r+1,1);
//    if(r==0||last!=2)
//        m3=v[r][2]+rec(r+1,2);
//    return ret=min({m1,m2,m3});
//}
vector<ll>mem(1e5+5,-1);
vector<ll>v;
ll n,cnt=0;
ll recFrog(ll idx)
{
    if(idx == n-1)return 0;

    auto&ret=mem[idx];
    if(~ret)return ret;


    ll m1=INT_MAX;
    ll m2=INT_MAX;

    if(idx+1<n)
        m1=abs(v[idx]-v[idx+1])+recFrog(idx+1);
    if(idx+2<n)
        m2=abs(v[idx]-v[idx+2])+recFrog(idx+2);


    return ret=min(m1,m2);
}
int32_t main()
{
    Fast();
//    cin>>n;
//    for(ll i=0;i<n;++i)
//    {
//        cin>>v[i][0];
//        cin>>v[i][1];
//        cin>>v[i][2];
//    }
//    cout<<rec(0,0);
   cin>>n;
   v=vector<ll>(n);
   for(auto&it:v)cin>>it;
   cout<<recFrog(0)<<endl;







}
