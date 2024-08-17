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
const int MX=2e4+5;
int dp[MX][100],n,k,cnt;
vector<int>v;
bool ans;
int dvv(int x)
{
    return (x%k+k)%k;
}
bool rec(int idx,int sum)
{
    if(idx==n)
    {
        if( (sum%k+k)%k )return 0;
        return 1;
    }
    auto&ret=dp[idx][(sum%k+k)%k];
    if(ret!=-1)return ret;
    bool f=rec(idx+1,sum+v[idx]);
    bool s=rec(idx+1,sum-v[idx]);

    return ret=f||s;
}
int32_t main()
{
    Fast();
//    File();
    T
    {
        memset(dp,-1,sizeof(dp));
        cin>>n>>k;
        v=vector<int>(n);
        for(auto&it:v)cin>>it;
        cout<<(rec(1,v[0])?"Divisible":"Not divisible")<<endl;
//        cout<<ans<<endl;

    }






}
