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
#define vii vector<vector<int>>
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
int n,m,cnt;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<m ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
vector<vector<char>>v;
vector<vector<bool>>visited;
bool safe(int x,int y)
{
    for(int i=0;i<4;++i)
    {
        int xx=dx[i]+x,yy=dy[i]+y;
        if(valid(xx,yy)&&v[xx][yy]=='T')return 0;
    }
    return 1;
}
void dfs(int x,int y)
{
    visited[x][y]=1;
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(valid(xx,yy)&&(v[xx][yy]=='G'||v[xx][yy]=='.')&&not visited[xx][yy] )
        {
//            cout<<xx+1<<" "<<yy+1<<endl;
            cnt+=v[xx][yy]=='G';
            v[xx][yy]='.';
            if(safe(xx,yy))
            {
                dfs(xx,yy);
            }
        }


    }
}
int main()
{
    Fast();
//    File();

//    cin>>n>>m;
    while(cin>>n>>m)
    {
        cnt=0;
        swap(n,m);
        v=vector<vector<char>>(n,vector<char>(m));
        visited=vector<vector<bool>>(n,vector<bool>(m));
        int x,y;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                cin>>v[i][j];
                if(v[i][j]=='P')x=i,y=j;
            }
        }
        if(not safe(x,y)){cout<<0<<endl;continue;}
        dfs(x,y);
        cout<<cnt<<endl;







    }














}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
