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
int ss=INT_MAX;
vector<tuple<int,int,int>>used;
map<int,int>fromm;
map<int,int>too;
map<int,int>visited;
int Kruskal_Disjoint_Union(vector<edge>&EdgeList, ll n)
{
    DSU dsu(n);
    priority_queue<edge>q;
    bool done=0;
    int MnCost=0;
    for (edge &e : EdgeList)
    {
        if(not done)
        {
            dsu.MergeGroups(e.from,e.to);
            MnCost+=e.cost;
            done=1;
            continue;
        }
        q.push(e);
    }
    while (!q.empty())
    {
        edge e= q.top();
        q.pop();
        if (dsu.MergeGroups(e.from, e.to))
        {
//            cout<<e.from<<" "<<e.to<<" "<<e.cost<<endl;
            MnCost+=e.cost;
        }
    }
    return MnCost;
}
int char_mn_cost(char c,char cc)
{
    int a=c-'0';
    int b=cc-'0';
    int nnn=min(a,b);
    int xx=max(a,b);
    int cnt=0,mn=xx-nnn;
    while(xx!=nnn)
    {
        nnn--;
        if(nnn==-1)nnn=9;
        cnt++;
    }
    mn=min(mn,cnt);
    return mn;
}
int help(string a,string b)
{
    int cost=0;
    for(int i=0; i<4; ++i)
    {
        int tmp=char_mn_cost(a[i],b[i]);
        cost+=tmp;
    }
    return cost;
}
int32_t main()
{
    Fast();
//    File();
    T
    {
        int n;
        string s;
        cin>>n;
        vector<edge>vec;
        vector<string>v;
        v.push_back("0000");
        for(int i=0; i<n; ++i)
        {
            cin>>s;
            v.push_back(s);
        }
        int x,ccc=INT_MAX;
        for(int i=1; i<n+1; ++i)
        {
            int cost=help(v[i],v[0]);
            if(cost<ccc)
            {
                x=i;
                ccc=cost;
            }
        }
//        cout<<0<<" "<<x<<" "<<ccc<<endl;
//        cout<<endl;
        vec.push_back({0,x,ccc});
        for(int i=1; i<n+1; ++i)
        {
            for(int j=1; j<n+1; ++j)
            {
                if(i==j)continue;
                int cost=help(v[i],v[j]);
                vec.push_back({i,j,cost});
            }
        }
        cout<<Kruskal_Disjoint_Union(vec,n+1)<<endl;




    }














}
