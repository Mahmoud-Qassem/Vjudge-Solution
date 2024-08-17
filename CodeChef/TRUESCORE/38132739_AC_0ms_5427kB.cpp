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
int n,k;
bool valid(int x,int nn)
{
    return (x>=0&&x<nn);
}
int main()
{
    cyan
    T
    {
        int a,b,c,d;cin>>a>>b>>c>>d;
        if(a<=c&&b<=d)cout<<"POSSIBLE"<<endl;
        else cout<<"IMPOSSIBLE"<<endl;
    }






}
