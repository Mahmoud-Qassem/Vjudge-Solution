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

bool help(vector<ll>&v,ll mid,ll k)
{
    ll cnt=0;
    for(int i=0;i<sz(v);++i)
    {
        cnt+=(mid/v[i]);
        if(cnt>=k)return true;
    }
    return false;
}
int32_t main()
{
    Fast();
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);for(auto&it:v)cin>>it;
    sort(all(v));
    ll l=1,r=1e18,ans,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(help(v,mid,k))
        {
            ans=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;








}
