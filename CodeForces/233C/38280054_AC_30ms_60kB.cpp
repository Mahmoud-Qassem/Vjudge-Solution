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
map<pair<int,int>,int>mp;
int mxcnt,mxcost;
void dfs(vector<vector<int>>&v,vector<bool>&visited,int node,int cost,int cnt)
{
    visited[node]=1;
    if(cnt>=mxcnt)
    {
        mxcost=max(mxcost,cost);
        cnt=mxcnt;
    }
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child,cost+mp[ {node,child}],cnt+1);
        }
    }
}
int main()
{
    File();
    int n;
    cin>>n;
    int tmp=n;
    int mn=100;
    vector<vector<int>>ans(mn,vector<int>(mn));
    for(int i=1;i<100;++i)
    {
        ans[0][i]=ans[i][0]=1;
        for(int j=0;j<i;++j)
        {
            if(n>=j)
            {
                n-=j;
            }
            else break;
            ans[i][j]=ans[j][i]=1;
        }
    }


    cout<<100<<endl;
    for(int i=0;i<mn;++i)
    {
        for(int j=0;j<mn;++j)
        {
            cout<<ans[i][j];
        }
        cout<<endl;
    }











}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
