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
#define OO 1e12
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
int n,limit;
vi w(1005),value(1005);
ll dp[1009][35];
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

int32_t main()
{
    Fast();
    File();
    T
    {
        cin>>n;
        for(int i=0;i<n;++i)
        {
            cin>>value[i]>>w[i];
        }
        memset(dp,-1,sizeof(dp));
        ll ans=0;
        int m;
        cin>>m;
        while(m--)
        {
            ll lm;cin>>lm;
            limit=lm;
            ans+=knapsack(0,limit);
        }
        cout<<ans<<endl;



    }
















}
