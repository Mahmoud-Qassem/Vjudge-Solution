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
#define OO INT_MAX
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
//    freopen("distinct.in", "r", stdin);
//    freopen("distinct.in", "w", stdout);
}
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
vi dx= {0,0,-1,1};
vi dy= {1,-1,0,0};
int n;
vector<int>v;
int dp[100005];
int cnt=0;
int solve(int idx)
{
    if(idx==n-1)return 0;
    auto &ret=dp[idx];
    if(~ret)return ret;
    int tmp=OO;
    tmp=min(tmp,abs(v[idx]-v[idx+1])+solve(idx+1) );
    if(idx<n-2)
    tmp=min(tmp,abs(v[idx]-v[idx+2])+solve(idx+2) );
    return ret=tmp;


}
int main()
{
    cyan
    memset(dp,-1,sizeof(dp));
    cin>>n;
    v=vector<int>(n);
    for(auto&it:v)cin>>it;
    cout<<solve(0);
//    cout<<endl;
//    for(int i=0;i<9;++i)cout<<dp[i]<<endl;








}
