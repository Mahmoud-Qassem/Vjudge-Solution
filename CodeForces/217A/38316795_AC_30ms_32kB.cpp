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
void floyd(vector<vector<int>>&adj)
{
    int nodes=sz(adj);
    for(int k=0; k<nodes; ++k)
        for(int i=0; i<nodes; ++i)
            for(int j=0; j<nodes; ++j)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
}
int n,m,s,e;
vector<vector< pair<int,int> >>adj;
vi dist;
vector<bool>done;
void dijkstra(int s,int e)
{
    priority_queue<pair<int,int>>q;
    q.push({0,s});
    dist[s]=0;
    while(!q.empty())
    {
        int k=q.top().S;
        int so_far_cost=-q.top().F;
        q.pop();
        if(so_far_cost>dist[k])continue;
        for(auto&i:adj[k])
        {
            if(so_far_cost+i.S<dist[i.F])
            {
                dist[i.F]=so_far_cost+i.S;
                q.push({-dist[i.F],i.F});
            }
        }
    }

}
void dfs(vector<vector<int>>&adj,vector<int>&visited,int node)
{
    visited[node]=1;
    for(auto&it:adj[node])
    {
        if(not visited[it])
        {
            dfs(adj,visited,it);
        }

    }
}
int main()
{
    cyan
    int n;
    cin>>n;
    map< pair<int,int>,int>mp;
    vector<pair<int,int>>v(n);
    vector<vector<int>>adj(n);
    for(int i=0;i<n;++i)cin>>v[i].F>>v[i].S,mp[v[i]]=i;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(v[i].F==v[j].F||v[i].S==v[j].S)
            {
                adj[ mp[v[i] ] ].push_back(mp[ v[j] ] );
                adj[ mp[v[j] ]].push_back(mp[ v[i] ] );
            }
        }
    }
    int cnt=0;vector<int>visited(n);
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            cnt++;
            dfs(adj,visited,i);
        }
    }
    cout<<cnt-1<<endl;
















//    ll cnt=0;
//    for(ll i=0;i<n;++i)
//    {
//        for(ll j=i+1;j<n;++j)
//        {
//            double x=abs(v[i].F-v[j].F)+abs(v[i].S-v[j].S);
//            double y=sqrt( pow( (v[i].F-v[j].F),2) +pow( abs(v[i].S-v[j].S),2));
////            cout<<x<<" "<<y<<endl;
//            if(x==y)
//            {
//                cout<<v[i].F<<" "<<v[i].S<<endl;
//                cout<<v[j].F<<" "<<v[j].S<<endl;
//                cout<<endl;
//                cnt++;
//            }
//
////            cout<<x<<" "<<y<<endl;
//
//        }
//    }
//    cout<<cnt<<endl;











}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem











