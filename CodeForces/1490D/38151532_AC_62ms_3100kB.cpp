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

bool isprime(ll n)
{
    if(n==2)return 1;
    else if(n<2)return 0;
    else if(n==3)return 1;
    else if(n%2==0||n%3==0)return 0;
    for(int i=5; i<=sqrt(n); i+=6)
    {
        if(n%i==0||n%(i+2)==0)return 0;
    }
    return 1;
}
const double EPS=1e-9;

void calc(int&cnt,int mn ,int mx)
{
    while(mn*2<mx)
    {
        mn*=2;
        cnt++;
    }

}
vi depth,v;
void rec(int l,int r, int d)
{
    if(l>r)return;
    if(l==r)
    {
        depth[l]=d;
        return ;
    }
    int idx=max_element(v.begin()+l,v.begin()+r+1)-v.begin();
    depth[idx]=d;
    rec(l,idx-1,d+1);
    rec(idx+1,r,d+1);
}
int   main()
{
    cyan
    T
    {
        int n,tmp;
        cin>>n;
        depth.resize(n);
        v.resize(n);
        for(auto&it:v)cin>>it;
        rec(0,n-1,0);
        for(auto&it:depth)cout<<it<<" ";cout<<endl;



    }






















}


 