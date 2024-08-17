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
#define OO INT_MAX
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}
int n,m,cnt;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
void dfs(vector<vector<char>>&v,vector<vector<int>>&visited,int x,int y,char land)
{
    visited[x][y]=1;
     if(y==0 and v[x][m-1]==land and not visited[x][m-1]&&m-1)
            {
                cnt++;
                dfs(v,visited,x,m-1,land);
            }
            else if(y==m-1 and v[x][0]==land and not visited[x][0]&&m-1)
            {
                cnt++;
                dfs(v,visited,x,0,land);
            }
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];

        if(valid(xx,yy)&&not visited[xx][yy]&&v[xx][yy]==land)
        {
            cnt++;
            dfs(v,visited,xx,yy,land);
        }
    }
}
int main()
{
    File();
    while(cin>>n>>m)
    {
        int x,y,mx=0;

        vector<vector<char>>v(n,vector<char>(m));
        for(auto&it:v)for(auto&ic:it)cin>>ic;
        cin>>x>>y;
        char land=v[x][y];



        vector<vector<int>>visited(n,vector<int>(m,0));
        dfs(v,visited,x,y,land);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(not visited[i][j]&&v[i][j]==land)
                {
                    cnt=1;
                    dfs(v,visited,i,j,land);
                    mx=max(cnt,mx);
                }
            }
        }
        cout<<mx<<endl;

    }
























}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
