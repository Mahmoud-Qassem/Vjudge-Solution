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
#define OO 65498
#define vii vector<vector<int>>
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
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
void floyd(vector<vector<ll>>&v)
{
    ll n=sz(v);
    for(ll k=0;k<n;++k)
        for(ll i=0;i<n;++i)
            for(ll j=0;j<n;++j)
            v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
int32_t main()
{
    Fast();
//    File();

    ll idx=0;
    ll a,b;
    while(cin>>a>>b)
    {
        if(!a&&!b)break;
        idx++;
        vector<pair<ll,ll>>vec;
        map<ll,ll>mp;
        ll x=1;
        mp[a]=x++;
        a=x-1;
        mp[b]=x++;
        b=x-1;
        vec.push_back({a-1,b-1});
        while(cin>>a>>b&&a&&b)
        {
            if(not mp[a]){mp[a]=x++;a=x-1;}
            else a=mp[a];

            if(not mp[b]){mp[b]=x++;b=x-1;}
            else b=mp[b];

            vec.push_back({a-1,b-1});

        }
        x--;
        vector<vector<ll>>v(x,vector<ll>(x,1e8));
        for(ll i=0;i<x;++i)v[i][i]=0;
        for(auto&it:vec)v[it.F][it.S]=1;
        floyd(v);
        double ans=0;
        for(ll i=0;i<x;++i)
            for(ll j=0;j<x;++j)
                ans+=v[i][j];
        cout<<fixed<<setprecision(3);
        cout<<"Case "<<idx<<": average length between pages = ";
        cout<<(ans/((x*(x-1))))<<" clicks"<<endl;

    }










}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
