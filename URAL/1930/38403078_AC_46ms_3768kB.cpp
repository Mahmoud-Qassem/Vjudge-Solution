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
#define OO 1e8
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
int n,m;
vector<vector<pair<int,int>>>v;
int dijkstra(int src,int disti ,bool gear_type)
{
    vector<int>ppp(n,-1);
    vector<int>dist(n,OO);
    priority_queue<pair<int,int>>q;

    q.push({-0,src});
    dist[src]=0;
    ppp[src]=gear_type;
    while(sz(q))
    {
        pair<int,int> cur=q.top();
        q.pop();

        int node=cur.second;
        int cur_cost=-cur.first;

        if(cur_cost!=dist[node])continue;



        for(auto&it:v[node])
        {
            if(dist[it.S]>cur_cost+(it.F==ppp[node]?0:1))
            {
                ppp[it.S]=it.F;
                dist[it.S]=cur_cost+(it.F==ppp[node]?0:1);

                q.push({-dist[it.S],it.S});
            }
        }
    }
    return dist[disti];
}
int32_t main()
{
    Fast();
    cin>>n>>m;
    v=vector<vector<pair<int,int>>>(n);
    for(int i=0;i<m;++i)
    {
        int a,b,c;cin>>a>>b;
        a--,b--;
        v[a].push_back({1,b});
        v[b].push_back({0,a});
    }
    int source,distination;
    cin>>source>>distination;
    source--,distination--;
    int dijk1=dijkstra(source,distination,0);
    int dijk2=dijkstra(source,distination,1);
    cout<<min(dijk1,dijk2)<<endl;



}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra is only for +ve w graphs  ;)
