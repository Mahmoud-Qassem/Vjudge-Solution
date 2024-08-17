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
vector<int>visited;void dfs(int node)
{
    visited[node]=1;
    e=node;
    for(auto&it:adj[node])
    {
        if(not visited[it.first])
        {
            dfs(it.F);
        }

    }
}
int main()
{
    cyan
    int idx=1;
    T
    {
        cin>>n>>m;
        visited=vector<int>(n+1,0);
        dist=vi (n+5,OO);
        adj=vector<vector<pair<int,int>>>(n+5,vector<pair<int,int>>(0));
        for(int i=0; i<m; ++i)
        {
            int from,to,cost;
            cin>>from>>to>>cost;
//            from--,to--;
            adj[from].push_back({to,cost});
            adj[to].push_back({from,cost});
        }
        cin>>s;
        dfs(s);
        done=vector<bool>(n,0);
        e=s;
        for(int i=1;i<=n;++i)
            if(i!=s&&visited[i])
        dijkstra(s,i);
        for(int i=1;i<=n;++i)
        {
            if(i!=s&&visited[i])
            cout<<dist[i]<<" ";
            else if(i!=s)cout<<-1<<" ";
        }
        cout<<endl;


    }







}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
