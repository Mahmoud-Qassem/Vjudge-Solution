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

string s,t,ans;
const int MX=200;
int dp[MX][MX];
int rec( int i,int j)
{
    if(i>=sz(s) or j>=sz(t))return 0;

    auto&ret=dp[i][j];
    if(~ret)return ret;

    if(s[i]==t[j])return ret=1+rec(i+1,j+1);

    int b=rec(i,j+1);
    int a=rec(i+1,j);

    return ret=max(a,b);
}




int32_t main()
{
    Fast();
//    File();
    int idx=0;
    while(getline(cin,s))
    {
        if(s=="#")break;
        getline(cin,t);
        memset(dp,-1,sizeof(dp));
        cout<<"Case #"<<++idx<<": you can visit at most "<<rec(0,0)<<" cities."<<endl;
    }
}
