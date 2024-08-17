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
int n,m;
vector<vector<int>>v;
vector<vector<int>>adj;
int dijkstra(int s,int e)
{
    vi d(n+5,OO);
    priority_queue<pair<int,int> >q;
    q.push({0,s});
    d[s]=0;
    while(!q.empty())
    {
        int k=q.top().S;
        int till_nw_cost=-q.top().F;
        q.pop();
        if(till_nw_cost>d[k])continue;
        for(auto&i:adj[k])
        {
            if(till_nw_cost+v[k][i]<d[i])
            {
                d[i]=till_nw_cost+v[k][i];
                    q.push({-d[i],i});
            }
        }
    }
    return d[e];

}


int main()
{
    cyan
    T
    {
        int idx=0;
        map<string,int>mp;
        cin>>n;
        v=vector<vector<int>>(n,vector<int>(n,OO));
        adj=vector<vector<int>>(n,vector<int>(0));
        for(int h=0; h<n; ++h)v[h][h]=0;
        for(int i=0; i<n; ++i)
        {
            string s;
            cin>>s;
            mp[s]=i;
            cin>>m;
            for(int x=0; x<m; ++x)
            {
                int to,cost;
                cin>>to>>cost;
                to--;
                adj[i].push_back(to);
                v[i][to]=min(cost,v[i][to]);
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            string  s,e;
            cin>>s>>e;
            cout<<dijkstra(mp[s],mp[e])<<endl;
        }
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






//    vi d(nodes),s(nodes);
//    int x,y;
//    cin>>x>>y;
//    for(int i=0; i<nodes; ++i)
//    {
//        adj[i][i]=0;
//        d[i]=adj[x][i];
//        s[i]=x;
//    }
//    d[x]=0;
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
//                if(d[i]<mn_dist)
//                {
//                    mn_dist=d[i];
//                    node=i;
//                }
//            }
//        }
//        in[node]=1;
//        for(int i=0; i<nodes; ++i)
//        {
//            if(in.count(i)==0)
//            {
//                int old_dis=d[i];
//                d[i]=min(d[i],mn_dist+adj[i][node]);
//                if(d[i]!=old_dis)
//                {
//                    s[i]=node;
//                }
//            }
//
//        }
//    }
//        for(int i=0;i<nodes;++i)cout<<i<<" ";cout<<endl;
//        for(int i=0;i<nodes;++i)cout<<d[i]<<" ";cout<<endl;
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
