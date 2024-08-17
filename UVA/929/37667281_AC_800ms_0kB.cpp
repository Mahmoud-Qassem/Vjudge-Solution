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
#define OO 0x3F3F3F3F
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void floyd(vector<vector<int>>&adj)
{
    int nodes=sz(adj);
    for(int k=0; k<nodes; ++k)
        for(int i=0; i<nodes; ++i)
            for(int j=0; j<nodes; ++j)
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
}
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
int n,m;
vi dx= {0,0,1,-1};
vi dy= {-1,1,0,0};
vector<vector< int >>adj;
int dijkstra()
{
    vector< vector<int> > dist(n,vector<int>(m,OO));
    vector<vector<bool>>visited(n,vector<bool>(m,0));
    visited[0][0]=1;
    priority_queue<pair<int,pair<int,int>> >q;
    q.push({-adj[0][0],{0,0}});
    dist[0][0]=adj[0][0];
    while(!q.empty())
    {
        pair<int,int>k=q.top().S;
        int cost_so_far=-q.top().F;
        visited[k.first][k.S]=1;
        if(cost_so_far>dist[k.F][k.S])continue;
        q.pop();
        for(int i=0; i<4; ++i)
        {
            int xx=k.F+dx[i];
            int yy=k.S+dy[i];
            if(valid(xx,n)&&valid(yy,m)&&visited[xx][yy]==0)
            {
                if(cost_so_far+adj[xx][yy]<dist[xx][yy])
                {
                    dist[xx][yy]=cost_so_far+adj[xx][yy];
                    q.push({-dist[xx][yy] ,{xx,yy}});
                }
            }
        }
    }
    return dist[n-1][m-1];

}


int main()
{
    cyan
    T
    {
        cin>>n>>m;
        adj=vector<vector<int>>(n+5,vector<int>(m+5));
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
                cin>>adj[i][j];
        }
        cout<<dijkstra()<<endl;
    }







}
