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
int n,m;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m;
}
vi dx= {0,0,1,-1};
vi dy= {1,-1,0,0};
vector<vector<ll>>v;
int dijkstra()
{
    vector<vector<int>>dist(n,vector<int>(m,OO));
    priority_queue< tuple<ll,int,int>, vector<tuple<ll,int,int>>,greater<tuple<ll,int,int>> >q;
    dist[0][0]=v[0][0];
    q.push({v[0][0],0,0});
    while(sz(q))
    {
        tuple<ll,int,int>cur=q.top();
        q.pop();
        int x=get<1>(cur);
        int y=get<2>(cur);
        int cost=get<0>(cur);
        if( dist[x][y]<cost )continue;
        for(int i=0;i<4;++i)
        {
            int xx=x+dx[i];
            int yy=y+dy[i];
            if(valid(xx,yy) and   dist[xx][yy] > v[xx][yy]+cost)
            {
                dist[xx][yy]=v[xx][yy]+cost;
                q.push({dist[xx][yy],xx,yy});
            }
        }
    }
    return dist[n-1][m-1];

}



int32_t main()
{
    Fast();
    File();
    T
    {
        cin>>n>>m;
        v=vector<vector<ll>>(n,vector<ll>(m,OO));
        for(auto&it:v)for(auto&ic:it)cin>>ic;
        cout<<dijkstra()<<endl;
    }












}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra works only on +ve w graphs
