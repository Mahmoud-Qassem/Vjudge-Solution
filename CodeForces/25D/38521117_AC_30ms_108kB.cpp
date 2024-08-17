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
pair<vector<int>,vector<pair<int,int>>> Kruskal_Disjoint_Union(vector<edge>&EdgeList, ll n)
{
    UnionFind dsu(n);
    priority_queue<edge>q;
    for (edge &e : EdgeList)q.push(e);
    vector<pair<int,int>>vec;
    while (!q.empty())
    {
        edge e= q.top();
        q.pop();
        if (!dsu.connect(e.from, e.to))
        {
            vec.push_back({e.from,e.to});
        }
        if (dsu.forests == 1)break;
    }
    vector<int>ret;
    for(int i=0;i<sz(dsu.parent);++i)
    {
        if(dsu.parent[i]==i)ret.push_back(i);
    }
    return make_pair( ret,vec );
}
int32_t main()
{
    Fast();
    int n;
    cin>>n;
    vector<edge>v;
    for(int i=0; i<n-1; ++i)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        v.push_back({x,y,1});
    }
    pair<vector<int>,vector<pair<int,int>>>ans=Kruskal_Disjoint_Union(v,n);
    int tmp=ans.second.size();
    cout<<tmp<<endl;
    int idx=1;
    for(int i=0;i<tmp;++i)
    {
        cout<<ans.second[i].first+1<<" ";
        cout<<ans.second[i].second+1<<" ";
        cout<<ans.first[0]+1<<" ";
        cout<<ans.first[idx++]+1<<" ";
        cout<<endl;
    }






}
