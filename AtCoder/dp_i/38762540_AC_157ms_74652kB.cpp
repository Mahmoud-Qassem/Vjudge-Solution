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
vector<double>v;int n;
double dp[3009][3009];
double rec(int idx,int head)
{
    if(idx==n)return head>=((n+1)/2);

    auto&ret=dp[idx][head];
    if(ret!=-1)return ret;
    ret=0.0;
    ret+= v[idx]       *rec(idx+1,head+1);
    ret+= (1.0-v[idx]) *rec(idx+1,head);
    return ret;
}



int32_t main()
{
    Fast();
    cin>>n;
    v=vector<double>(n);
    for(int i=0;i<n+9;++i)
    for(int j=0;j<n+9;++j)dp[i][j]=-1;

    for(auto&it:v)cin>>it;
    cout<<fixed<<setprecision(10);
    cout<<rec(0,0)<<endl;









}
