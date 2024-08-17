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
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO INT_MAX
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

bool isprime(ll n)
{
    if(n==2)return 1;
    else if(n<2)return 0;
    else if(n==3)return 1;
    else if(n%2==0||n%3==0)return 0;
    for(int i=5; i<=sqrt(n); i+=6)
    {
        if(n%i==0||n%(i+2)==0)return 0;
    }
    return 1;
}
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
void dfs(vii&graph,vi&visited,int node)
{
    visited[node]=1;
    for(int ne:graph[node])
    {
        if(not visited[ne])
        {
            dfs(graph,visited,ne);
        }
    }
}






int main()
{
    cyan
    int n,m;
    bool line=0;
    int idx=1;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        vi v(n);
        vii adj(n+1);
        for(int i=0; i<m; ++i)
        {
            int from,to;
            cin>>from>>to;
            from--,to--;
            adj[from].push_back(to);
            adj[to].push_back(from);
        }
        vi visited(n+1,0);
        int cnt=0;
        for(int i=0; i<n; ++i)
        {
            if(not visited[i])
            {
                cnt++;
                dfs(adj,visited,i);
            }
        }
        cout<<"Case "<<idx++<<": "<<cnt<<endl;;
    }

















}
