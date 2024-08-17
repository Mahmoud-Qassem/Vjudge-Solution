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
    ll from, to;double cost;
    edge() {}
    edge(ll from, ll to, double cost) :from(from), to(to), cost(cost) {}
    bool operator<(const edge &e)const
    {
        return e.cost<cost;
    }
};
tuple<ll,ll,ll> Kruskal_Disjoint_Union(vector<edge>&EdgeList, ll n,ll r)
{
    UnionFind dsu(n);
    priority_queue<edge>q;
    for (edge &e : EdgeList)q.push(e);
    ll MnCost = 0;
    ll CC=1;
    bool done=0;
    double rial_roads=0,roads=0;
    while (!q.empty())
    {
        edge e= q.top();
        q.pop();
        if(not done and e.cost>r)
        {
            CC=dsu.forests;
            done=1;
        }

        if (dsu.connect(e.from, e.to))
        {
            if(not done)
            {
                roads+= e.cost;
            }
            else
            {
                rial_roads+=e.cost;
            }
        }
        if (dsu.forests == 1)break;
    }
    return {CC,round(roads),round(rial_roads)};
}
double dd(double x,double y,double xx,double yy)
{
    return (sqrt( powl((y-yy),2)+pow((x-xx),2) ));
}
int32_t main()
{
    Fast();
    ll idx=1;
    File();
    T
    {
        ll n,r;
        cin>>n>>r;
        vector<pair<double,double>>prs(n);
        vector<edge>EdgeList;
        for(ll i=0; i<n; ++i)
        {
            cin>>prs[i].first>>prs[i].second;
        }
        for(ll i=0; i<n; ++i)
        {
            for(ll j=0; j<n; ++j)
            {
                if(i==j)continue;
                double d=dd( prs[i].F,prs[i].S,prs[j].F,prs[j].S );
                EdgeList.push_back({i,j,d});
            }
        }
        tuple<ll,ll,ll>ans=Kruskal_Disjoint_Union(EdgeList,n,r);
        cout<<"Case #"<<idx++<<": ";
        cout<<get<0>(ans)<<" ";
        cout<<get<1>(ans)<<" ";
        cout<<get<2>(ans)<<endl;





    }









}
