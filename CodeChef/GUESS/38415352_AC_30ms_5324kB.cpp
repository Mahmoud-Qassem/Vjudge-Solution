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
int32_t main()
{
    Fast();
    T
    {
        ull n,m;
        cin>>n>>m;
        ull alice_odd,alice_even;
        ull bob_odd,bob_even;
        
        alice_odd=n/2;
        alice_even=n/2;
        alice_odd+=(n&1);
        
        bob_odd=m/2;
        bob_even=m/2;
        bob_odd+=(m&1);
        
        ull total=n*m;
        
        ull help=(alice_even*bob_odd)+(alice_odd*bob_even);
        ull gg=__gcd(total,help);
        cout<<help/gg<<"/"<<total/gg<<endl;



    }

















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
