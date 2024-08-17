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
vector<vector<pair<ll,ll>>>v;
ll n,m;
ll dijkstra(ll s,ll e)
{
    vector<ll>dist(n,OO);
    priority_queue<pair<ll,ll>>q;
    dist[s]=0;
    q.push({0,s});
    while(sz(q))
    {
        ll cost=-q.top().first;
        ll node=q.top().second;
        q.pop();

        if(cost>dist[node])continue;
        if(node==e)break;
        for(auto&child:v[node])
        {
            if(dist[child.first]>cost+child.second)
            {
               dist[child.first]=cost+child.second;
               q.push({-dist[child.first],child.first});
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
        cin>>n>>m;
        v=vector<vector<pair<ll,ll>>>(n);
        for(ll i=0;i<m;++i)
        {
            ll from,to,cost;
            cin>>from>>to>>cost;
            from--,to--;
            v[from].push_back({to,cost});
//            v[to].push_back({from,cost});
        }
        ll s,e;
        cin>>s>>e;s--,e--;
        ll tmp=dijkstra(s,e);
        if(tmp==OO)cout<<"NO"<<endl;
        else cout<<tmp<<endl;


    }











}
