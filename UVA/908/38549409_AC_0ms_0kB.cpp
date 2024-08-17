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

struct UnionFind
{
    vector<ll>parent, rank;
    ll forests;
    UnionFind(ll n)
    {
        forests = n;
        parent = rank = vector<ll>(n + 1);
        for (ll i = 1; i <= n; ++i)
            parent[i] = i ;
    }
    ll find_parent(ll x)
    {
        if (x == parent[x])return x;
        return parent[x] = find_parent(parent[x]);
    }
    void link(ll x, ll y)
    {

        if (rank[x] > rank[y])swap(x, y);
        parent[x] = y;
        if (rank[x] == rank[y])rank[y]++;
    }
    bool connect(ll x, ll y)
    {
        x = find_parent(x), y = find_parent(y);
        if (x != y)
        {
            link(x, y);
            forests--;
        }
        return x != y;
    }
    bool same_set(ll x, ll y)
    {
        return find_parent(x) == find_parent(y);
    }
};
struct edge
{
    ll from, to;
    ll cost;
    edge() {}
    edge(ll from, ll to, ll cost) :from(from), to(to), cost(cost) {}
    bool operator<(const edge &e)const
    {
        return e.cost<cost;
    }
};
int ss=INT_MAX;
vector<edge>used;
int Kruskal_Disjoint_Union(vector<edge>&EdgeList, ll n)
{
    UnionFind dsu(n);
    priority_queue<edge>q;
    for (edge &e : EdgeList)q.push(e);
    int MnCost=0;
    while (!q.empty())
    {
        edge e= q.top();
        q.pop();
        if (dsu.connect(e.from, e.to))
        {
            MnCost+=e.cost;
            used.push_back(e);
        }
    }
    return MnCost;
}
int32_t main()
{
    Fast();
    File();
    int n,d=0,from,to,cost,k,m;
    while(cin>>n and n!=EOF)
    {
        if(d)cout<<endl;d=1;
        vector<edge>must;
        vector<edge>v;
        ll sum=0;
        for(int i=0; i<n-1; ++i)
        {
            cin>>from>>to>>cost;
            from--,to--;sum+=cost;
            must.push_back({from,to,cost});
        }
        cout<<sum<<endl;
        cin>>k;
        for(int i=0;i<k;++i)
        {
            cin>>from>>to>>cost;
            from--,to--;
            v.push_back({from,to,cost});
        }cin>>m;
        for(int i=0;i<m;++i)
        {
            cin>>from>>to>>cost;
            from--,to--;
            v.push_back({from,to,cost});
        }
        cout<<Kruskal_Disjoint_Union(v,n)<<endl;;

















    }






}
