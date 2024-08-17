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
#define OO 1e18
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
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
bool valid(ll x,ll y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};

vector<int>v;
void sort_and_put(vector<int>idxx)
{
    vector<int>vv;
    for(int i=0;i<sz(idxx);++i)
    {
        vv.push_back(v[idxx[i]]);
    }
    sort(all(vv));
    for(int i=0;i<sz(idxx);++i)
    {
        v[idxx[i]]=vv[i];
    }
}
vector<vector<int>>adj;
void dfs(int node ,vector<int>&visited,int x)
{
    visited[node]=x;
    for(auto&ne:adj[node])
    {
        if(not visited[ne])
        {
            dfs(ne,visited,x);
        }
    }
}
int32_t main()
{
    Fast();
    int n;
    cin>>n;
    v=vector<int>(n);
    for(auto&it:v)cin>>it;
    adj=vector<vector<int>>(n);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            char link;
            cin>>link;
            if(link=='1')adj[i].push_back(j);
        }
    }
    vector<int>visited(n);
    int idx=0;
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            idx++;
            dfs(i,visited,idx);
            vector<int>idxx;
            for(int j=0;j<n;++j)
            {
                if(visited[j]==idx)idxx.push_back(j);
            }
            sort_and_put(idxx);
        }

    }
    for(auto&it:v)cout<<it<<" ";



















}
