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
void floyd(vector<vector<double>>&v)
{
    int n=sz(v);
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
struct edge
{
    ll from,to,w;
    edge(ll from,ll to,ll w):from(from),to(to),w(w) {}
    bool operator < (const edge &e)
    const
    {
        return e.w < w;
    }
};
ll n,m,s,e;
vector<ll>ppp;
vector<vector<pair<ll,ll>>>v;
ll dijkstra()
{
    vector<ll>dist(n,OO);
    priority_queue<pair<ll,ll>>q;
    q.push({0,s});
    vector<bool>processed(n);
    dist[s]=0;
    while(sz(q))
    {
        pair<ll,ll> cur=q.top();
        q.pop();
        ll node=cur.second;
        ll cur_cost=-cur.first;
        if(processed[node])continue;
        processed[node]=1;
        for(auto&it:v[node])
        {
            if(dist[it.S]>cur_cost+it.F)
            {
                dist[it.S]=cur_cost+it.F;
                q.push({-dist[it.S],it.S});
            }
        }
    }
    return dist[e];
}
int32_t main()
{
    Fast();
    T
    {
        cin>>n>>m>>s>>e;
        s--,e--;
        v=vector<vector<pair<ll,ll>>>(n);
        for(ll i=0; i<m; ++i)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            a--,b--;
            c+=12;
            v[a].push_back({c,b});
            v[b].push_back({c,a});
        }
        ll tmp=dijkstra();
        cout<<tmp<<endl;
    }







}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra is only for +ve w graphs  ;)
