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
#define OO 1e8
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
struct edge
{
    int x,y,cost;
    edge(int cost,int x,int y):cost(cost),x(x),y(y){}
    bool operator < (const edge&e)const
    {
        return e.cost<cost;
    }
};
vi dx= {-1,-1,0,1,1,1,0,-1  };
vi dy= { 0, 1,1,1,0,-1,-1,-1};
int n,m;
int s,d,ss,dd;
bool valid(int x,int y)
{
    return x>=0 and y>=0 and x<n and y<m;
}
vector<string>v;
int dijkstra()
{
    vector<vector<int>>dist(n,vector<int>(m,OO));
    dist[s][d]=0;
    priority_queue<edge>q;
    q.push({0,s,d});
    int ans=INT_MAX;
    while(sz(q))
    {
        edge e=q.top();
        q.pop();
        int cost= e.cost;
        int x= e.x;
        int y=  e.y;
        if(dist[x][y] < cost)continue;
        if(x==ss&&y==dd)
        {
            break;
        }
        for(int i=0; i<8; ++i)
        {
            int xx=x+dx[i],yy=dy[i]+y;

            if(valid(xx,yy) and dist[xx][yy] > cost+(v[x][y]-'0'!=i) )
            {
                dist[xx][yy]=cost+(v[x][y]-'0'!=i);
                q.push( {(cost+(v[x][y]-'0'!=i)),xx,yy} );
            }
        }
    }
    return dist[ss][dd];
}

int32_t main()
{
    Fast();
    File();
    cin>>n>>m;
    v=vector<string>(n);
    for(auto&it:v)cin>>it;
    int q;
    cin>>q;
    while(q--)
    {
        cin>>s>>d>>ss>>dd;
        s--,d--,ss--,dd--;
        cout<<dijkstra()<<endl;
    }


}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
// dijkstra works only on +ve w graphs
