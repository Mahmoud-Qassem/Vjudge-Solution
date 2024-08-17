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
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
bool mxx(string&a,string&b)
{
    if(sz(a)!=sz(b))return sz(a)>sz(b);
    return a>b;
}
int n;
int pp(int x)
{
    int idx=x,sum=0;
    for(int i=0; i<n; ++i)
    {
        sum+=idx++;
    }
    return sum;
}
int main()
{
    cyan
    T
    {
        ll n;
        cin>>n;
        vl v(n);
        vl vv(n-1);
        for(auto&it:v)cin>>it;
        for(auto&it:vv)cin>>it;
        sort(all(v));
        sort(all(vv));
        ll ans=0;
        ll mx=0;
        map<ll,ll>mp;
        for(ll i=0;i<n-1;++i)
        {
            mp[vv[i]-v[i] ]++;
            if(mp[vv[i]-v[i] ]>=mx&&vv[i]-v[i]>0)
            {
                mx=mp[vv[i]-v[i] ];
                ans=vv[i]-v[i];
            }
            mp[vv[i]-v[i+1] ]++;
            if(mp[vv[i]-v[i+1] ]>=mx&&vv[i]-v[i+1]>0)
            {
                mx=mp[vv[i]-v[i+1] ];
                ans=vv[i]-v[i+1];
            }
        }
        cout<<ans<<endl;









    }


}









//    vi v(2005);
//    ll x=-1000;
//    for(ll i=1;i<2005;++i)v[i]=x++;
//    for(ll i=1;i<2005;++i)v[i]+=v[i-1];
//    T
//    {
//
//    ll x;
//    cin>>n>>x;
//    for(ll i=-1000,idx=0;i<=1000-n;++i)
//    {
//        ll tmp=v[i+n+2]-v[i];
//        if((tmp/n)==x)
//        {
//            for(ll j=0;j<n;++j)cout<<i++<<" ";
//            cout<<endl;
//            break;
//        }
//    }
//
//    }
//
//

