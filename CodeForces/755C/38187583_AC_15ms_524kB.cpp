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
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
void dfs(int node,vector<vector<int>>&v,vector<bool>&visited)
{
    visited[node]=true;
    for(auto&child:v[node])
    {
        if(not visited[child])
        dfs(child,v,visited);
    }
}


int main()
{
    File();
    int n,m,CC=0;
    cin>>n;
    vector<vector<int>>v(n);
    for(int i=0;i<n;++i)
    {
        int from,to;
        cin>>from;
        from--;to=i;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    vector<bool>visited(n,0);
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            CC++;
            dfs(i,v,visited);
        }
    }
    cout<<CC<<endl;












}
