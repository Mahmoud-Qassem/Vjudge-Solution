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
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
//vector<vector<pair<ll,ll>>>v;
//ll n,m;
//ll dijkstra(ll s,ll e)
//{
//    vector<ll>dist(n,OO);
//    priority_queue<pair<ll,ll>>q;
//    dist[s]=0;
//    q.push({0,s});
//    while(sz(q))
//    {
//        ll cost=-q.top().first;
//        ll node=q.top().second;
//        q.pop();
//
//        if(cost>dist[node])continue;
//        if(node==e)break;
//        for(auto&child:v[node])
//        {
//            if(dist[child.first]>cost+child.second)
//            {
//               dist[child.first]=cost+child.second;
//               q.push({-dist[child.first],child.first});
//            }
//        }
//    }
//    return dist[e];
//}

vector<vector<int>>v;
void dfs(int node,vector<int>&visited)
{
    visited[node]=1;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(child,visited);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    v=vector<vector<int>>(n);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;from--,to--;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    vector<int>visited(n);
    int CC=0;
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            CC++;
            dfs(i,visited);
        }
    }
    if(CC>1||n<=m)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

}
int32_t main()
{
    Fast();
    int t;
//    cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }











}
