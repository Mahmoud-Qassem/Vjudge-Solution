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
int32_t main()
{
    Fast();
    File();
    ll idx=1;
    ll n,m;
    while(cin>>n && n!=EOF)
    {
        vector<ll>v(n+1);
        for(int i=1;i<=n;++i)cin>>v[i];
        cin>>m;
        vector<edge>edges;
        for(int i=0;i<m;++i)
        {
            int a,b;
            cin>>a>>b;
            ll tmp=v[b]-v[a];
            edges.push_back({a,b,tmp*tmp*tmp});
        }
        // apply bellman_ford
        vector<ll>dist(n+1,OO);
        dist[1]=0;
        vector<int>negative_effected(n+1);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                ll from=edges[j].from,to=edges[j].to,cost=edges[j].wt;
                if( dist[from]!=OO and dist[from]+cost<dist[to] )
                {
                    if( i==n-1 )
                    {
                        negative_effected[to]=1;
                    }
                    dist[to]=dist[from]+cost;
                }
            }
        }
        int q;
        cin>>q;
        cout<<"Set #"<<idx++<<endl;
        while(q--)
        {
            int city;cin>>city;
            if(negative_effected[city] || dist[city] < 3 || dist[city] == OO   )cout<<'?'<<endl;
            else cout<<dist[city]<<endl;
        }












    }













}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra works only on +ve w graphs
