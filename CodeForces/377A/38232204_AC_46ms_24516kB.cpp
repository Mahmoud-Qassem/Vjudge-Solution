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
int n,m;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m ;
}
bool border(int x,int y)
{
    return (x==0||y==0||x==n-1||y==m-1);
}
vi dx= {0,0,1,-1};
vi dy= {1,-1,0,0};
int cc;
void dfs(vector<vector<int>>&v,int x,int y,int&cnt)
{
    if(cnt==cc){return;}
    v[x][y]=2;
    cnt++;
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i],yy=dy[i]+y;
        if(valid(xx,yy)&&(v[xx][yy]==0))
        {
            dfs(v,xx,yy,cnt);
        }
    }
}
int main()
{
    File();
    int k;
    cin>>n>>m>>k;
    vector<vector<int>>v(n,vector<int>(m));
    char cch;
    int x,y;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>cch;
            if(cch=='.')v[i][j]=0,x=i,y=j,cc++;
            else v[i][j]=1;
        }
    }
     int cnt=0;
     cc-=k;
     dfs(v,x,y,cnt);
     for(int i=0;i<n;++i)
     {
         for(int j=0;j<m;++j)
         {
             if(v[i][j]==0)cout<<'X';
             else if(v[i][j]==1)cout<<'#';
             else if(v[i][j]==2)cout<<'.';
         }
         cout<<endl;
     }










}
