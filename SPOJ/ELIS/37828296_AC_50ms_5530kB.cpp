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
#define OO INT_MAX
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
vi dx= {0,0,-1,1};
vi dy= {1,-1,0,0};
int n;
vi v(15);
int dp[100][100];
int solve(int idx,int last)
{
    if(idx==n-1)
    {
        if(v[idx]>last)return 1;
        return 0;
    }
    int &ret=dp[idx][last];
    if(~ret)return ret;

    int take_it=solve(idx+1,last);
    int leave_it=0;
    if(v[idx]>last)leave_it=1+solve(idx+1,v[idx]);
    return ret=max(leave_it,take_it);



}
int main()
{
    cyan
    memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;++i)cin>>v[i];
    cout<<solve(0,0);
    cout<<endl;
//    for(int i=0;i<n;++i)
//    {
//        for(int j=0;j<n;++j)
//        {
//            cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
//        }
//    }








}
