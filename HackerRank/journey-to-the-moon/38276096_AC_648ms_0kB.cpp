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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8 ;
}
//vi dx= {0,0,1,-1,1,1,-1,-1};
//vi dy= {1,-1,0,0,1,-1,1,-1};
bool good(int x)
{
    int xx=0,idx=1;
    while(xx<x)
    {
        xx+=idx++;
        idx%=4;
        if(not idx)idx++;
    }
    return xx==x;
}
ll cnt;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    for(auto&it:v[node])
    {
        if(not visited[it])
        {
            cnt++;
            dfs(v,visited,it);
        }
    }
}
int main()
{
    File();
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    ll ans=0,tmp=0;
    vector<int>visited(n);
    vector<int>vec;
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            cnt=1;
            dfs(v,visited,i);
            vec.push_back(cnt);
            ans+=cnt*tmp;
            tmp+=cnt;
        }
    }
    cout<<ans<<endl;




















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
