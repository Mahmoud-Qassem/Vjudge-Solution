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
int cnt=0;
void dfs(vector<vector<int>>&v,vector<int>&painted,int node,int color,bool&valid)
{
    painted[node]=color;
    for(auto&child:v[node])
    {
        if(not painted[child])
        {
            dfs(v,painted,child,3-color,valid);
        }
        else
        {
            if(painted[child]==color)valid=0;
        }
    }
}

int main()
{
    File();
    int n,m,mx=0;
    cin>>n>>m;
    vector<vector<int>>v(n);
    vector<pair<int,int>>vec;
    for(int i=0;i<m;i++)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        vec.push_back({from,to});
        v[from].push_back(to);
        v[to].push_back(from);
    }
    int color=1;
    bool valid=1;
    vector<int>painted(n,0);
    dfs(v,painted,0,color,valid);
    if(!valid)
    {
        cout<<"NO"<<endl;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<sz(vec);++i)
        {
            if(painted[vec[i].first]==1)cout<<1;
            else cout<<0;
        }
    }


















}
