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
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
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
    int x,xx,y,yy,n,row,l,r;
    cin>>x>>y>>xx>>yy>>n;
    // row l.......r
    unordered_map<int,unordered_map<int,bool>>mp;
    for(int i=0;i<n;++i)
    {
        cin>>row>>l>>r;
        for(int k=l;k<=r;++k)
        {
            mp[row][k]=true;
        }
    }
    map<pair<int,int>,bool>visited;
    queue<pair<int,int>>q;
    q.push({x,y});
    int level=0,ans=-1;
    for(int sz=sz(q);sz;sz=sz(q),level++)
    {
        if(ans!=-1)break;
        while(sz--)
        {
            int i=q.front().F;
            int j=q.front().S;
            q.pop();
            if(i==xx&&j==yy)
            {
                ans=level;
                break;
            }
            visited[{i,j}]=true;
            for(int k=0;k<8;++k)
            {
                int nw_x=i+dx[k];
                int nw_y=j+dy[k];
                if(valid(nw_x,nw_y) and not visited[{nw_x,nw_y}] && mp[nw_x][nw_y] )
                    {
                        q.push({nw_x,nw_y});
                        visited[{nw_x,nw_y}]=1;
                    }

            }

        }
    }
    cout<<ans<<endl;

















   
}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem