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
#define OO 1e18
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
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
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};

struct DSU
{
    int leaders,Max;
    vector<int>parent, GroupSize;
    DSU(int n):leaders(n),Max(1)
    {
        parent = GroupSize = vector<int>(n+1);
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
            GroupSize[i]=1;
        }
    }
    int FindLeader(int i)
    {
        if(parent[i]==i)return i;
        return parent[i] = FindLeader(parent[i]);
    }
    bool sameGroup(int x,int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        return leader1 == leader2;
    }
    bool  MergeGroups(int x,int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)return 0;
        leaders--;
        if(GroupSize[leader1]>GroupSize[leader2])
        {
            parent[leader2] = leader1;
            GroupSize[leader1]+=GroupSize[leader2];
            Max= max(Max,GroupSize[leader1]);
        }
        else
        {
            parent[leader1] = leader2;
            GroupSize[leader2]+= GroupSize[leader1];
            Max= max(Max,GroupSize[leader2]);
        }
        return 1;
    }

    int size(int x)
    {
        int leader = FindLeader(x);
        return GroupSize[leader];
    }

};
struct edge
{
    ll from, to;
    ll cost;
    edge() {}
    edge(ll from, ll to, ll cost) :from(from), to(to), cost(cost) {}
    bool operator<(const edge &e)const
    {
        return e.cost<cost;
    }
};
int ans=INT_MAX;
vector<edge>used;
int c;
bool Kruskal_Disjoint_Union(priority_queue<edge>&q, ll n,int mid)
{
    DSU dsu(n);
    ll mn=INT_MAX,mx=INT_MIN;
    priority_queue<edge>qq=q;
    while (!qq.empty())
    {
        edge e= qq.top();
        qq.pop();
        if (dsu.MergeGroups(e.from, e.to))
        {
            mn=min(mn,e.cost);
            mx=max(mx,e.cost);
        }
    }
    ans=min(ll(ans),(mx-mn));
    return dsu.leaders==1;
}
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
//-----------------------------------------------
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int32_t main()
{
    Fast();
//    T
    {
        int n,m1,m2,from,to;
        cin>>n>>m1>>m2;
        vector<edge>v,vv;
        DSU mocha(n),diana(n);
        for(int i=0;i<m1;++i)
        {
            cin>>from>>to;from--,to--;
            mocha.MergeGroups(from,to);
        }
        for(int i=0;i<m2;++i)
        {
            cin>>from>>to;from--,to--;
            diana.MergeGroups(from,to);
        }
        vector<pair<int,int>>ans;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)continue;
                if(not mocha.sameGroup(i,j) and not diana.sameGroup(i,j))
                {
                    mocha.MergeGroups(i,j);
                    diana.MergeGroups(i,j);
                    ans.push_back({i+1,j+1});
                }
            }
        }
        cout<<sz(ans)<<endl;
        for(auto&it:ans)cout<<it.F<<" "<<it.S<<endl;

    }


































}
