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
    Fast();
//    File();
    /*
    problem J - Switch Bulbs
    ==> BFS
    */
    int t;
    cin>>t;
    for(int tt=1; tt<=t; ++tt)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>>sw(m);
        bool can=1;
        for(int i=0; i<m; ++i)
        {
            int x,we;
            cin>>x;
            for(int j=0; j<x; ++j)cin>>we,sw[i].push_back(n-we-1);
        }
        string start(n,'0');
        queue<string>q;
        q.push(start);
        unordered_map<string,int>visited;
        visited[start]=1;
        while(sz(q))
        {
            string cur=q.front();
            q.pop();
            for(int i=0; i<m; ++i)
            {
                string tmp=cur;
                int cnt=sz(sw[i]);
                for(int j=0; j<sz(sw[i]); ++j)
                {
                    if(tmp[ sw[i][j] ]=='0')tmp[sw[i][j]]='1';
                    else tmp[sw[i][j]]='0';
                }
                if(not visited[tmp]&&cnt)
                    q.push(tmp),visited[tmp]=visited[cur]+1;
            }
        }
        cout<<"Case "<<tt<<":\n";
        int qwe;
        cin>>qwe;
        for(int i=0; i<qwe; ++i)
        {
            string lol;
            cin>>lol;
            if(visited[lol])cout<<(visited[lol]-1)<<endl;
            else cout<<-1<<endl;
        }
        cout<<endl;





    }










}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
