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
void FAST()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
#ifndef ONLINE_JUDGE
//	freopen("inp.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

}

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

// mapping


int ans;

void dfs(map<string,vector<string>>&graph,map<string,bool>&visited,string node,int cnt )
{
    visited[node]=true;
    ans=max(cnt,ans);
    for(auto&ne : graph[node])
    {
        if(not visited[ne])
        {
            dfs(graph,visited,ne,cnt+1);
        }

    }



}








int main()
{

    cyan
    int n;
    cin>>n;
    map<string,vector<string>>adj;
    map<string,bool>visit;
    for(int i=0; i<n; ++i)
    {
        string from,to;
        cin>>from>>to>>to;
        for(int j=0; j<sz(from); ++j)from[j]=tolower(from[j]);
        for(int j=0; j<sz(to); ++j)to[j]=tolower(to[j]);
        adj[to].push_back(from);
    }
    int ans=0;
    int cnt=0;
    deque<string>q;
    q.push_back("polycarp");
    for(int sz=1; sz; sz=sz(q))
    {
        cnt++;
        while(sz--)
        {
            string cur=q.front();
            q.pop_front();
            for(int i=0; i<sz(adj[cur]); ++i)
            {
                q.push_back(adj[cur][i]);
            }
        }
    }


    cout<<cnt<<endl;
//    dfs(adj,visit,"polycarp",0);
//    cout<<ans+1<<endl;






}