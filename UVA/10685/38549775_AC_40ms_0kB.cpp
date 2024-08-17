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

struct DSU{
    int leaders,Max;
    vector<int>parent , GroupSize;
    DSU(int n):leaders(n),Max(1){
        parent = GroupSize = vector<int>(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            GroupSize[i]=1;
        }
    }
    int FindLeader(int i){
        if(parent[i]==i)return i;
        return parent[i] = FindLeader(parent[i]);
    }
    bool sameGroup(int x,int y){
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        return leader1 == leader2;
    }
    bool  MergeGroups(int x,int y){
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)return 0;
        leaders--;
        if(GroupSize[leader1]>GroupSize[leader2]){
            parent[leader2] = leader1;
            GroupSize[leader1]+=GroupSize[leader2];
            Max= max(Max,GroupSize[leader1]);
        }
        else{
            parent[leader1] = leader2;
            GroupSize[leader2]+= GroupSize[leader1];
            Max= max(Max,GroupSize[leader2]);
        }
        return 1;
    }

    int size(int x){
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
int ss=INT_MAX;
vector<edge>used;
int Kruskal_Disjoint_Union(vector<edge>&EdgeList, ll n)
{
    DSU dsu(n);
    priority_queue<edge>q;
    for (edge &e : EdgeList)q.push(e);
    int MnCost=0;
    while (!q.empty())
    {
        edge e= q.top();
        q.pop();
        if (dsu.MergeGroups(e.from, e.to))
        {
            MnCost+=e.cost;
        }
    }
    return dsu.Max;
}

int32_t main()
{
    Fast();
    File();
    int idx=1;
    int n,m;
    while(cin>>n>>m)
    {
        if(not (n+m))break;

        map<string,int>mp;string s;
        for(int i=0;i<n;++i)cin>>s,mp[s]=i;
        vector<edge>v;
        for(ll i=0;i<m;++i)
        {
            string s,ss;
            cin>>s>>ss;
           int from=mp[s],to=mp[ss];
            v.push_back({from,to,1});
        }
        int ans=Kruskal_Disjoint_Union(v,n);
        cout<<ans<<endl;
    }






}
