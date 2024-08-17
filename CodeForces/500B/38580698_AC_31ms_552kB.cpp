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
#define OO 1e6
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
bool valid(ll x,ll y)
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
    bool operator < (const edge &e)const
    {
        return e.cost<cost;
    }
};
void floyd(vector<vector<int>>&v)
{
    int n=sz(v);
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
int32_t main()
{
    Fast();
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto&it:v)cin>>it;
    vector<vector<int>>vv(n,vector<int>(n,OO));
    for(int i=0;i<n;++i)vv[i][i]=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            char link;
            cin>>link;
            if(link=='1')vv[i][j]=1;
        }
    }
    floyd(vv);
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            if(v[i]>v[j] and vv[i][j]!=OO)
            {
                swap(v[i],v[j]);
            }
        }
    }
    for(auto&it:v)cout<<it<<" ";



















}
