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
int cnt=1,n,m;
vector<int>dx={0,0,-1,1};
vector<int>dy={-1,1,0,0};
bool valid(int x,int y )
{
    return (x>=0 and y>=0 and x<n and y<m);
}
vector<vector<char>>v;
vector<vector<int>>visited;
void dfs(int x,int y)
{
    visited[x][y]=cnt;
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(valid(xx,yy) and not visited[xx][yy] and v[xx][yy]==v[x][y])
        {
            dfs(xx,yy);
        }
    }
}
int32_t main()
{
    Fast();
    cin>>n>>m;
    v=vector<vector<char>>(n,vector<char>(m));
    for(auto&it:v)for(auto&ic:it)cin>>ic;

    visited=vector<vector<int>>(n+5,vector<int>(m+5,0));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(not visited[i][j])
            {
                dfs(i,j);
                cnt++;
            }
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        x--,y--,yy--,xx--;
        if(visited[x][y]==visited[xx][yy])
        {
            if(v[xx][yy]=='1')cout<<"decimal"<<endl;else cout<<"binary"<<endl;
        }
        else
        {
            cout<<"neither"<<endl;
        }
    }







}
