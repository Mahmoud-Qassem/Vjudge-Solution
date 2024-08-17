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
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };
vector<vector<bitset<4>>>v;
vector<vector<bool>>visited;
void dfs(int x,int y)
{
    visited[x][y]=true;
    for(int i=0;i<4;++i)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if((!v[x][y][i])&&valid(xx,yy)&& not visited[xx][yy])
        {
            cnt++;
            dfs(xx,yy);
        }
    }



}
int main()
{
//    File();
    cin>>n>>m;
    v=vector<vector<bitset<4>>>(n,vector<bitset<4>>(m));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            int tmp;
            cin>>tmp;
            bitset<4>s(tmp);
            v[i][j]=s;
        }
    }
    visited=vector<vector<bool>>(n,vector<bool>(m,0));
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(not visited[i][j])
            {
                cnt=1;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    sort(allr(ans));
    for(auto&it:ans)cout<<it<<" ";cout<<endl;










}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
