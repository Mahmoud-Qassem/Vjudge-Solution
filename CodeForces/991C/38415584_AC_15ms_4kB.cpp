#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef unsigned long long int  ull;
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
#define OO 1e4
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (ll)( sqrt(2*n+0.25)-0.5  )
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
ull  gcd(ull  a, ull b)
{
    if(a<0)a*=-1;
    return (b == 0 ? a : gcd(b, a % b));
}
ull help(ull n,ull k)
{
    ull eat=0;
    while(n)
    {

        if(n<=k)
        {
            eat+=n;
            n=0;
        }
        else
        {
            n-=k;
            eat+=k;
        }
        n-=(n/10);
    }
    return eat;
}




int32_t main()
{
    Fast();
    ull n,k;
    cin>>n;
    k=n;
    ull l=1,r=1e18+1,mid;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(help(n,mid)>=(n+1)/2)
        {
            k=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<k<<endl;










}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
