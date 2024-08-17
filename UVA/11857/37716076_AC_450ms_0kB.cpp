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
struct DSU
{
    vector<int> parent,treeSize;
    int mx_lol=1;
    int forest;
    DSU(int n)
    {
        parent=vector<int>(n);
        treeSize=vector<int>(n,1);
        forest=n;
        mx_lol=1;
        for(int i=0; i<n; ++i)parent[i]=i;
    }
    // find_set
    int find_leader(int i)
    {
        if(parent[i]==i)return i;
        return parent[i]=find_leader(parent[i]);
    }
    int SZ(int  h)
    {
        h=find_leader(h);
        return treeSize[h];
    }
    // to link two nodes (two parents)
    bool union_sets(int x,int y)
    {
        x=find_leader(x),y=find_leader(y);
        if(x==y)return 0;
        forest--;
        if(treeSize[x]>treeSize[y])
        {
            parent[y]=x;
            treeSize[x]+=treeSize[y];
            mx_lol=max(mx_lol,treeSize[x]);
        }
        else
        {
            parent[x]=y;
            treeSize[y]+=treeSize[x];
            mx_lol=max(mx_lol,treeSize[y]);
        }
        return 1;
    }
    bool connected(int x,int y)
    {
        x=find_leader(x);
        y=find_leader(y);
        return (x==y);
    }
    int CC()
    {
        vector<vector<int>>adj(sz(parent),vector<int>(0));
        for(int i=0; i<sz(parent); ++i)
        {
            adj[ find_leader(i) ].push_back(i);
        }
        int cnt=0;
        for(int i=0; i<sz(adj); ++i)cnt+=(sz(adj[i])>0);
        return cnt;
    }
};
struct edge
{
    int from,to,cost;
    edge(int from,int to,int cost):from(from),to(to),cost(cost){};
    bool operator < (const edge&e)const
    {
        return cost>e.cost;
    }
};
int main()
{
    cyan
    int n,m;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        DSU dsu(n);
        vector<edge>edges ;
        for(int i=0; i<m; ++i)
        {
            int from,to,cost;
            cin>>from>>to>>cost;
            edges.push_back({from,to,cost});
        }
        priority_queue<edge>q;
        for(int i=0;i<sz(edges);++i)q.push(edges[i]);
        int cnt=0;
        int mx=0;
        while(q.size())
        {
            edge e=q.top();
            q.pop();
            if(dsu.union_sets(e.from,e.to))
            {
                mx=max(mx,e.cost);
                cnt++;
            }
        }
        if(cnt==n-1)cout<<mx<<endl;
        else cout<<"IMPOSSIBLE"<<endl;


    }













}
