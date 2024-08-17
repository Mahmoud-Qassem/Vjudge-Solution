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
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
int lvl,mx;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node,int lvl=0)
{
    visited[node]=1;
    mx=max(mx,lvl);
    for(auto&child:v[node])
    {
        if(not visited[child])
            dfs(v,visited,child,lvl+1);
    }
}
int main()
{
    Fast();
//    File();
    /*
    problem J - Switch Bulbs
    ==> BFS
    */
    int n;
    cin>>n;
    vector<vector<int>>v(n);
    for(int i=0; i<n-1; ++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    vector<deque<int>>home;
    deque<int>q;
    q.push_back(0);
    vector<int>parent(n);
    vector<int>visited(n);
    visited[0]=1;
    for(int lvl=0,sz=sz(q); sz; ++lvl,sz=sz(q))
    {
        if(lvl>2 and sz)
            home.push_back(q);
        while(sz--)
        {
            int cur=q.back();
            q.pop_back();
            for(auto&child:v[cur])
            {
                if(not visited[child])
                {
                    visited[child]=1;
                    parent[child]=cur;
                    q.push_front(child);
                }
            }
        }
    }
    int ans=0;
    vector<int>vstd(n);
    for(int i=sz(home)-1; i>=0; i--)
    {
        for(int j=0; j<sz(home[i]); ++j)
        {
            int node=home[i][j];
            if(not vstd[node])
            {
                ans++;
                vstd[parent[node]]=1;
                for(auto&ne:v[ parent[node] ])
                {
                    vstd[ne]=1;
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
