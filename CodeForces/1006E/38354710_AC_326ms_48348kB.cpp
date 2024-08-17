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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
}
int n,m,cnt;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
vector<int>flow;
vector<pair<int,int>>interval;
void dfs(vector<set<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    flow.push_back(node);
    interval[node].first=sz(flow);
    for(auto&child:v[node])
    {
        if(not visited[child])
            dfs(v,visited,child);
    }
    interval[node].second=sz(flow);
}
int main()
{
    File();
    /*
    problem E "Military Problem"
    let us try to store children of every node sorted and try
    the last approach get MLE
    i should just store the the size of the subtree of each node
    which is the size of the vector of the flow traverse in the moment
    i see the node and the moment i finished traverse the all subtree of the node
    */
    int n,q;
    cin>>n>>q;
    vector<set<int>>v(n);
    for(int i=1;i<n;++i)
    {
        int p ;
        cin>>p;
        p--;
        v[p].insert(i);
        v[i].insert(p);
    }
    interval=vector<pair<int,int>>(n);
    vector<int>visited(n);
    dfs(v,visited,0);
    for(int i=0;i<q;++i)
    {
        int node,k;
        cin>>node>>k;
        node--;
        if(k > (interval[node].second-interval[node].first+1))cout<<-1<<endl;
        else cout<<flow[ interval[node].F+k-2 ]+1<<endl;
    }
}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
