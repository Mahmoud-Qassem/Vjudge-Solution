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
int n;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<n ;
}
vi dx= {0,0,1,-1};
vi dy= {1,-1,0,0};
void dfs(int x,int y,vector<vector<char>>&v)
{
    v[x][y]='.';
    for(int i=0; i<4; ++i)
    {
        int xx=dx[i]+x,yy=dy[i]+y;
        if(valid(xx,yy)&&v[xx][yy]!='.')
        {
            dfs(xx,yy,v);
        }
    }
}


int main()
{
    File();
    int t;
    cin>>t;
    for(int idx=1; idx<=t; ++idx)
    {
        int CC=0;
        cin>>n;
        vector<vector<char>>v(n,vector<char>(n));
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)cin>>v[i][j];
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(v[i][j]=='x')
                {
                    CC++;
                    dfs(i,j,v);
                }
            }
        }
        cout<<"Case "<<idx<<": "<<CC<<endl;

    }











}
