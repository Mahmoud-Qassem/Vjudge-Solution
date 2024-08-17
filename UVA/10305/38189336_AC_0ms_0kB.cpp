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
int n;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<n ;
}
vi dx= {0,0,1,-1};
vi dy= {1,-1,0,0};
void dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child);
        }
    }
    cout<<node+1<<" ";
}

int main()
{
    File();
    int n,m;
    while(cin>>n>>m&&(n||m))
    {
        vector<vector<int>>v(n,vector<int>(0));
        vector<pair<int,int>>dd;
        vector<int>d(n);
        for(int i=0;i<m;++i)
        {
            int from,to;
            cin>>from>>to;
            from--;
            to--;
            v[to].push_back(from);
            d[from]++;
        }
        for(int i=0;i<n;++i)
        {
            dd.push_back({d[i],i});
//            cout<<d[i]<<" "<<i+1<<endl;
        }
        sort(all(dd),[&](pair<int ,int>&a,pair<int ,int>&b){
             if(a.first!=b.first)return a.first>b.first;
             return a.second<b.second;
             });
        vector<int>visited(n,0);
        for(int i=0;i<n;++i)
        {
            if(not visited[dd[i].second])
            {
                dfs(v,visited,dd[i].second);
            }
        }
        cout<<endl;

    }











}
