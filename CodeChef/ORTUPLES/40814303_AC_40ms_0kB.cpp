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
long long get_common(long long a,long long b)
{
    bitset<21>ba(a);
    bitset<21>bb(b);

    long long cnt=0;
    for(long long i=0; i<21; ++i)
        cnt+=(ba[i] == bb[i]and bb[i]);
    return 2*cnt;
}
int32_t main()
{
    Fast();
    T
    {
        long long a,b,c,cc=0;
        cin>>a>>b>>c;
        long long ans=1;
        for(int i=0; i<21; ++i)
        {
            int x=1<<i;
            int tmp=bool(x&a) + bool(x&b) + bool(x&c);
            if(tmp==3)ans*=4;
            else if(tmp==1)ans=0;

        }
        cout<<ans<<endl;
    }


}

//2^(common*2)
//0100
//1010
//1110





