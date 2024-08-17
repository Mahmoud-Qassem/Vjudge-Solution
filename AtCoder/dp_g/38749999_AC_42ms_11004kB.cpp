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
#define clr(v,x) memset(v,x,sizeof(v))
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
#define MX 100005 // 1e5+5
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
vector<vector<int>>v;
int dp[MX];
int rec(int node)
{
    int&mx=dp[node];
    if(~mx)return mx;
    mx=0;
    for(auto&it:v[node])
    {
        mx=max(mx,1+rec(it));
    }
    return mx;
}


int32_t main()
{
    Fast();
    int n,m;
    cin>>n>>m;
    v=vector<vector<int>>(n);
    int root=0;
    clr(dp,-1);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        root=from;
        v[from].push_back(to);
    }
    int mx=0;
    for(int i=0;i<n;++i)
    {
        mx=max(mx,rec(i));
    }
    cout<<mx<<endl;


}
