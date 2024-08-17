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
#define OO 1e12
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
    freopen("testCase_input.txt", "r", stdin);
//    freopen("testCase_actualOutput.txt", "w", stdout);

}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n,k;
bool valid(int x)
{
    return ( ((x/k)*(x%k) )==n );
}
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
//-----------------------------------------------
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int32_t main()
{
    Fast();
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto&it:v)cin>>it;

    int mn=INT_MAX;
    for(int i=0; i<(1<<n); ++i)
    {
        bitset<21>bts(i);
        vector<int>xoor;
        for(int j=0; j<n; j++)
        {
            int tmp=v[j];
            while( (j+1<n) and bts[j] == bts[j+1] )
            {
                j++;
                tmp|=v[j];
            }
            xoor.push_back(tmp);
        }
        int lol=0;
        for(auto&it:xoor)lol^=it;
        mn=min(mn,lol);

    }
    cout<<mn<<endl;
}






