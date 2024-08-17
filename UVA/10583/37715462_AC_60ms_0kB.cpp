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
struct DSU
{
    vector<int> parent,treeSize;
    int forest;
    DSU(int n)
    {
        parent=vector<int>(n);treeSize=vector<int>(n,1);
        forest=n;
        for(int i=0;i<n;++i)parent[i]=i;
    }
    // find_set
    int find_leader(int i)
    {
        if(parent[i]==i)return i;
        return parent[i]=find_leader(parent[i]);
    }
    // to link two nodes (two parents)
    void link(int x,int y)
    {
        if(treeSize[x]>treeSize[y])swap(x,y);
        parent[y]=x;
        if(treeSize[x]==treeSize[y]) treeSize[x]++;
    }

    bool union_sets(int x,int y)
    {
        x=find_leader(x),y=find_leader(y);
        if(x!=y)link(x,y),forest--;
        return (x!=y);
    }
    int CC()
    {
        vector<vector<int>>adj(sz(parent),vector<int>(0));
        for(int i=0;i<sz(parent);++i)
        {
            adj[ find_leader(i) ].push_back(i);
        }
        int cnt=0;
        for(int i=0;i<sz(adj);++i)cnt+=(sz(adj[i])>0);
        return cnt;
    }
};
int main()
{
    cyan
    int n,m,idx=1;
    while(cin>>n>>m)
    {
        if(n==0&&m==0)break;
        DSU dsu(n);
        for(int i=0;i<m;++i)
        {
            int from,to;
            cin>>from>>to;
            from--,to--;
            dsu.union_sets(from,to);
        }
        cout<<"Case "<<idx++<<": "<<dsu.CC()<<endl;
    }













}
