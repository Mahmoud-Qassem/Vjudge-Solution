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
//#define F first
//#define S second
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
 //         red,blue
vector<pair<int,int>>rb;
unordered_map<int,int>red;
unordered_map<int,int>blue;
pair<int,int>dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    int r=0,b=0;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            pair<int,int>p=dfs(v,visited,child);
            r+=p.first;
            b+=p.second;
        }
    }
    return rb[node]={r+red[node],b+blue[node]};



}




int main()
{
    File();
    /*
    problem F1 tree cutting
    let us root the tree and then count the number of red nodes and blue nodes
    at every subtree and the edge between the parent
    and its subtree which contain all red/blue and zero blue/red is A NICE edge
    */
    int n;
    cin>>n;
    rb=vector<pair<int,int>>(n);
    int allred=0,allblue=0;
    for(int i=0;i<n;++i)
    {
        int clr;cin>>clr;
        if(clr==1)red[i]=1,allred++;
        else if(clr==2)blue[i]=1,allblue++;
    }
    vector<vector<int>>v(n);
    for(int i=0;i<n-1;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    vector<int>visited(n);
    rb[0]=dfs(v,visited,0);
    int ans=0,idx=1;
    for(int i=1;i<n;++i)
    {
        if((rb[i].first==allred&&rb[i].second==0)||(rb[i].first==0&&rb[i].second==allblue))
        {
            ans++;
        }
    }
    cout<<ans<<endl;























}

// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
