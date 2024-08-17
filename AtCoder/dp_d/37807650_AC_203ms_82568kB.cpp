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
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO INT_MAX
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
vi dx= {0,0,-1,1};
vi dy= {1,-1,0,0};
int n,limit;
vi w(2005),value(2005);
ll dp[101][100005];
ll knapsack(ll idx,ll remain)
{
    if(idx==n)return 0;

    ll &ret=dp[idx][remain];
    if(~ret)return ret;

    ll leave_it=knapsack(idx+1,remain);
    ll take_it=0;
    if(remain>=w[idx])
        take_it=value[idx]+knapsack(idx+1,remain-w[idx]);
    return ret=max(leave_it,take_it);
}

int main()
{
    cyan
    memset(dp,-1,sizeof(dp));
    cin>>n>>limit;
    for(int i=0;i<n;++i)
    {
        cin>>w[i]>>value[i];
    }
    cout<<knapsack(0,limit);
//    for(int i=0;i<=n;++i)
//    {
//        for(int j=0;j<20;++j)
//        {
//            cout<<i<<" "<<j<<"   "<<dp[i][j]<<endl;
//        }
//    }

















}
