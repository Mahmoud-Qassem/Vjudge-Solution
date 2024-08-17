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
int n,m,s,e;
vector<vector< pair<int,int> >>adj;
int dijkstra(int s,int e)
{
    vi dist(n+5,OO);
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
    if(dist[e]==OO)return -1;
    return dist[e];

}


int main()
{
    cyan
    int idx=1;
    T
    {
        cin>>n>>m>>s>>e;
        adj=vector<vector<pair<int,int>>>(n+5,vector<pair<int,int>>(0));
        for(int i=0; i<m; ++i)
        {
            int from,to,cost;
            cin>>from>>to>>cost;
            adj[from].push_back({to,cost});
            adj[to].push_back({from,cost});
        }
        int ans=dijkstra(s,e);
         cout<<"Case #"<<idx<<": ";
        if(ans==-1)
        {
            cout<<"unreachable"<<endl;
        }
        else
            cout<<ans<<endl;
            idx++;

    }













//     dijkstra
//    int x;
//    cin>>x;
//    for(int t=1; t<=x; ++t)
//    {
//        int nodes,edges,friends;
//        cin>>nodes>>edges>>friends;
//        vector<vector<int>>adj(nodes,vector<int>(nodes,OO/3));
//        for(int i=0; i<edges; ++i)
//        {
//            int from,to,cost;
//            cin>>from>>to>>cost;
//            from--,to--;
//            adj[from][to]=adj[to][from]=cost;
//        }
//        for(int i=0;i<nodes;++i)adj[i][i]=0;
//        vi v(friends);
//        for(auto&it:v)cin>>it,it--;
//        sort(all(v));
//        int ans=OO;
//        floyd(adj);
//        do
//        {
//            // get the nw ans from a nw premu
//            int tmp=adj[0][v[0]]+adj[nodes-1][v[friends-1]];
//            for(int i=1; i<friends; ++i)
//            {
//                tmp+= adj[ v[i] ][ v[i-1] ];
//            }
//            ans=min(ans,tmp);
//        }
//        while(next_permutation(all(v)));
//        cout<<"Case "<<t<<": "<<ans<<endl;
//
//
//    }






//    vi dist(nodes),s(nodes);
//    int x,y;
//    cin>>x>>y;
//    for(int i=0; i<nodes; ++i)
//    {
//        adj[i][i]=0;
//        dist[i]=adj[x][i];
//        s[i]=x;
//    }
//    dist[x]=0;
//    map<int,int >in;
//    in[x]=1;
//    while(sz(in)<nodes)
//    {
//        int mn_dist=OO;
//        int node=0;
//        for(int i=0; i<nodes; ++i)
//        {
//            if(in.count(i)==0)
//            {
//                if(dist[i]<mn_dist)
//                {
//                    mn_dist=dist[i];
//                    node=i;
//                }
//            }
//        }
//        in[node]=1;
//        for(int i=0; i<nodes; ++i)
//        {
//            if(in.count(i)==0)
//            {
//                int old_dis=dist[i];
//                dist[i]=min(dist[i],mn_dist+adj[i][node]);
//                if(dist[i]!=old_dis)
//                {
//                    s[i]=node;
//                }
//            }
//
//        }
//    }
//        for(int i=0;i<nodes;++i)cout<<i<<" ";cout<<endl;
//        for(int i=0;i<nodes;++i)cout<<dist[i]<<" ";cout<<endl;
//        for(int i=0;i<nodes;++i)cout<<s[i]<<" ";cout<<endl;

//          cout<<"--------------------------------"<<endl;
////        for(int i=0;i<nodes;++i)
////        {
////            for(int j=0;j<nodes;++j)
////            {
////                cout<<adj[i][j]<<" ";
////            }
////            cout<<endl;
////        }


}
