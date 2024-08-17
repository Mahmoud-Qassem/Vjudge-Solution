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

bool power_of_two(ll n)
{
    ll tmp=1;
    while(tmp<n)tmp<<=1;
    return tmp==n;
}
const int MX=10000;

//vi len(MX,INT_MAX);
//vii parent(20);
//void bfs(vii&v,int start,bool&tree)
//{
//    queue<int>q;
//    q.push(start);
//    len[start]=0;
//    cout<<start<<" "<<0<<endl;
//    for(int level=0,sz=1    ; sz(q) ;    level++,sz=sz(q))
//    {
//
//        while(sz--)
//        {
//            for(int ne : v[q.front()])
//            {
//                if(sz( parent[q.front()] )&&ne == parent[q.front()][0])continue;
//                if(len[ne]==INT_MAX)
//                {
//                    parent[ne].push_back(q.front());
//                    cout<<ne<<" "<<level+1<<endl;
//                    len[ne]=level+1;
//                    q.push(ne);
//                }
//                else tree=0;
//
//            }
//            q.pop();
//        }
//    }
//
//
//
//
//}
//void dfs(deque<int>&ret,int node)
//{
//    if(!sz(parent[node]))return;
//    ret.push_back(parent[node][0]);
//    dfs(ret,parent[node][0]);
//
//
//
//}
#define vi vector<int>
#define sz(v) v.size()
class Solution
{
public:

    int rec(vi&v,int idx,int x,int goal,int cnt)
    {
        if(x==goal)return cnt;
        if(idx>=sz(v))return INT_MAX;
        return min( {rec(v,idx+1,x+v[idx],goal,cnt+1 ),rec(v,idx+1,x-v[idx],goal,cnt+1 ),rec(v,idx+1,(x^v[idx]),goal,cnt+1 )});


    }

    int minimumOperations(vector<int>& nums, int start, int goal) {

        int cnt=0;
        int res=rec(nums,0,start,goal,cnt);
        return res;


    }
};
vi v;
void dfs(vii&graph,vi&visited,int node,int&mn)
{
    visited[node]++;
    mn=min(mn,v[node]);
    for(int ne:graph[node])
    {
        if(not visited[ne])
        {
            dfs(graph,visited,ne,mn);
        }
    }
}






int main()
{
    cyan
//    vii v(MX);
//    int n,m;
//    cin>>n>>m;
//    for(int i=0; i<m; ++i)
//    {
//        int from,to;
//        cin>>from>>to;
//        v[from].push_back(to);
//        v[to].push_back(from);
//    }
//    bool tree=1;
//    bfs(v,0,tree);
//    tree?cout<<"TREE":cout<<"NOT A TREE";cout<<endl;
//
//
//    for(int node=1;node<n;++node)
//    {
//        cout<<"Path from "<<0<<" to "<<node<<" : ";
//        deque<int>path;
//        path.clear();
//        path.push_back(node);
//        dfs(path,node);
//
//        if((sz(path)&&path.back()!=0)||!sz(path))cout<<"Not exist"<<endl;
//        else {
//                reverse(all(path));
//            for(auto&it:path)cout<<" "<<it;cout<<endl;
//
//        }
//    }
//    int n;
//    cin>>n;
//    vi v(n);
//    for(auto&it:v)cin>>it;
//    int start=313,goal;cin>>start>>goal;
//    Solution x;
//    cout<<x.minimumOperations(v,start,goal);
    int n,m;
    cin>>n>>m;
    v=vi (n);
    for(auto&it:v)cin>>it;
    vii adj(n+1);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        adj[from].push_back(to);
        adj[to].push_back(from);
    }
    vi visited(n+1);
    ll ans=0;
    for(int i=0;i<n;++i)
    {
        if(not visited[i])
        {
            int mn=v[i];
            dfs(adj,visited,i,mn);
            ans+=mn;
        }
    }
    cout<<ans<<endl;















}