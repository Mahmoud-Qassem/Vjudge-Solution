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
#define OO 1e12
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
int cnt=1;
vector<int>parent;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node,bool&cycle)
{
    visited[node]=cnt++;
    for(auto&it:v[node])
    {
        if(not visited[it])
        {
            parent[it]=node;
            dfs(v,visited,it,cycle);
        }
        else
        {
            if(it!=parent[node])cycle=1;
        }
    }
}

int32_t main()
{
    Fast();
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n);
    parent=vector<int>(n,-1);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    int ans=0;
    vector<int>visited(n);
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            bool cycle=0;
            dfs(v,visited,i,cycle);
            if(not cycle)ans++;
        }
    }
    cout<<ans<<endl;











}
