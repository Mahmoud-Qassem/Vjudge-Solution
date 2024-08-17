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
void dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    cnt++;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child);
        }
    }
}

int main()
{
    File();
    int n,m,root;
    cin>>n>>m>>root;root--;
    vector<vector<int>>v(n);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        v[from].push_back(to);
    }
    vector<int>visited(n,0);
    dfs(v,visited,root);
    vector<pair<int,int>>vec;
    for(int node=0;node<n;++node)
    {
        if(not visited[node])
        {
            vector<int>visited2=visited;
            cnt=0;
            dfs(v,visited2,node);
            vec.push_back({cnt,node});
        }
    }
    int ans=0;
    sort(allr(vec));
    for(int i=0;i<sz(vec);++i)
    {
        if(not visited[vec[i].second ])
        {
            ans++;
            dfs(v,visited,vec[i].second);
        }
    }
    cout<<ans<<endl;











}