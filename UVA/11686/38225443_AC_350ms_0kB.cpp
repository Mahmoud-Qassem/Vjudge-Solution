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
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8 ;
}
//vi dx= {0,0,1,-1,1,1,-1,-1};
//vi dy= {1,-1,0,0,1,-1,1,-1};
vi dx= {2,2,-2,-2,1,1,-1,-1};
vi dy= {1,-1,1,-1,-2,2,-2,2};
int cnt=0;
vector<int>start_time,end_time;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node,bool&cycle)
{
    if(cycle)return;
    visited[node]=1;
    start_time[node]=cnt++;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child,cycle);
        }
        else
        {
            if(start_time[child]<start_time[node]&&end_time[child]==-1)
            {
                cycle=1;
            }
        }
    }
    end_time[node]=cnt++;
}
void print(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    cout<<node+1<<endl;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            print(v,visited,child);
        }
    }
}
int main()
{
    File();
    int n,m;
    while(cin>>n>>m&&(n||m))
    {
        start_time=vector<int>(n,-1);
        end_time=vector<int>(n,-1);
        vector<vector<int>>v(n);
        vi out(n),in(n);
        for(int i=0; i<m; ++i)
        {
            int from,to;
            cin>>from>>to;
            from--,to--;
            out[from]++;
            in[to]++;
            v[from].push_back(to);
        }
        vector<int>visited(n);
        bool notValid=0;
        dfs(v,visited,0,notValid);
        if(notValid)
        {
            cout<<"IMPOSSIBLE"<<endl;
        }
        else
        {
            vector<int>vvv(n);
            vector<int>idx(n,0);
            int cc=n;
            while(cc)
            {
                for(int i=n-1; i>=0; --i)
                {
                    if(not vvv[i] && out[i]&&in[i]==0)
                    {
                        vvv[i]=1;
                        cout<<i+1<<endl;
                        cc--;
                        out[i]--;
                        for(int k=0;k<sz(v[i]);++k)
                        {
                            in[v[i][k]]--;
                        }
                    }
                    else if(not vvv[i]&&!out[i]&&!in[i])cout<<i+1<<endl,vvv[i]=1,cc--;
                }
            }
        }

    }














}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
