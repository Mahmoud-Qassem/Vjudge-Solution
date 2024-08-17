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
void dfs(vector<vector<int>>&v,int x,int y,int&cnt,int c,bool&lake)
{
    v[x][y]=c;
    if(border(x,y)){lake=0;}
    cnt++;
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i],yy=dy[i]+y;
        if(valid(xx,yy)&&(v[xx][yy]==0))
        {
            dfs(v,xx,yy,cnt,c,lake);
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
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>cch;
            if(cch=='.')v[i][j]=0;
            else v[i][j]=1;
        }
    }
    vector<pair<int,int>>ans;
    int c=2;
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            if(v[i][j]==0)
            {
                int cnt=0;
                bool lake=1;
                dfs(v,i,j,cnt,c,lake);
                if(lake)
                {
                    ans.push_back({cnt,c});
                }
                c++;
            }
        }
    }
    int xx=0;
    sort(all(ans));
    if(sz(ans)>k)
    {
        int x=sz(ans)-k;
        for(int i=0; i<x; ++i)xx+=ans[i].first;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                bool convert=0;
                for(int h=0; h<x; ++h)
                {
                    if(v[i][j]==ans[h].second)
                    {
                        convert=1;
                        break;
                    }
                }
                if(v[i][j]>1&&convert)v[i][j]=1;
                if(v[i][j]!=1)v[i][j]=0;
            }
        }
    }
    else
    {
        int x=k-sz(ans);
        xx=0;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<m; ++j)
            {
                if(v[i][j]!=1)v[i][j]=0;
            }
        }
    }
    cout<<xx<<endl;
    for(auto&it:v){for(auto&ic:it)if(ic)cout<<'*';else cout<<'.';cout<<endl;}




















}
