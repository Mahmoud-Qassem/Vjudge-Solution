#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef unsigned long long int  ull;
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
#define F first
#define S second
#define OO 1e9
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define inverse_of_sum(n) (ll)( sqrt(2*n+0.25)-0.5  )
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
    //return x>=0 && y>=0 && x<n && y<m ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
struct edge
{
    ll from,to,wt;

};
vector<edge>edges;
int n,m,cnt;
bool bellman_ford()
{
    vector<ll>dist(n,OO);
    dist[0]=0;
    for(ll i=0,flag=0;i<n;++i,flag=0)
    {
        for(ll e=0;e<sz(edges);++e)
        {
            ll from=edges[e].from,to=edges[e].to,cost=edges[e].wt;
            if( cost+dist[from] < dist[to])
            {
                if(i==n-1)return true;
                flag=1;
                dist[to]=cost+dist[from];
            }
        }

        if(!flag)break;
    }
    return false;
}



int32_t main()
{
    Fast();
    File();
    T
    {
        cin>>n>>m;
        edges.clear();
        for(ll i=0;i<m;++i)
        {
            ll a,b,c;cin>>a>>b>>c;
            edges.push_back({a,b,c});
        }
        if(bellman_ford())cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }

















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra works only on +ve w graphs
