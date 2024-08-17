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
#define EPS  0.01

struct edge
{
    double temp,disi;
    int city;
    edge(double temp,double disi,int city): temp(temp),disi(disi),city(city) {};

};
int n,m,s,e;

vector<vector<edge>>v;
double dijkstra_on_temp()
{
    vector<double>tmp(n,OO);
    priority_queue<pair<double,int>>q;

    q.push({0.00,s});
    tmp[s]=0.0;
    vector<int>visited(n);

    while(sz(q))
    {
        pair<double,int>cur=q.top();
        q.pop();

        int node=cur.S;
        double tmpp=-cur.F;
        if(visited[node])continue;

        if(node==e)
        {
            break;
        }

        visited[node]=1;

        for(auto&it:v[node])
        {
            double nw_temp=it.temp;
            int nw=it.city;

            if(tmp[nw] > max(nw_temp,tmpp) )
            {
                tmp[nw] = max(nw_temp,tmpp);
                q.push({-tmp[nw],nw});
            }
        }
    }
    return tmp[e];
}
vector<int>parent;
double dijkstra_on_disi(double mn_tmp)
{
    vector<double>dist(n,OO);
    priority_queue<pair<double,int>>q;

    q.push({0.00,s});
    dist[s]=0.0;
    vector<int>visited(n);

    while(sz(q))
    {
        pair<double,int>cur=q.top();
        q.pop();

        int node=cur.S;
        double disi=-cur.F;


        if(visited[node])continue;

        if(node==e)
        {
            break;
        }

        visited[node]=1;

        for(auto&it:v[node])
        {
            double nw_disi=it.disi;
            double nw_ttt=it.temp;
            int nw=it.city;


            if(dist[nw] > disi+nw_disi  and  nw_ttt<=mn_tmp  )
            {
                dist[nw] = disi+nw_disi;
                parent[nw]=node;
                q.push({-dist[nw],nw});
            }
        }
    }
    return dist[e];


}










int32_t main()
{
    Fast();
    File();
    while(cin>>n&&n!=EOF)
    {
        cin>>m>>s>>e;
        s--,e--;
        v=vector<vector<edge>>(n);
        parent=vector<int>(n,-1);

        for(int i=0; i<m; ++i)
        {
            int from,to;
            double temp,disi;
            cin>>from>>to>>temp>>disi;
            from--,to--;
            v[from].push_back(edge(temp,disi,to));
            v[to].push_back(edge(temp,disi,from));
        }


        double mn_temp=dijkstra_on_temp();
        double mn_disi=dijkstra_on_disi(mn_temp);


        vector<int>path;
        int cur=parent[e];
        while(parent[cur]!=-1)
        {
            path.push_back(cur+1);
            cur=parent[cur];
        }
        path.push_back(s+1);
        reverse(all(path));
        cout<<fixed<<setprecision(1);
        for(auto&it:path)cout<<it<<" ";cout<<e+1;
        cout<<endl;
        cout<<mn_disi<<" "<<mn_temp<<endl;
    }












}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra works only on +ve w graphs
