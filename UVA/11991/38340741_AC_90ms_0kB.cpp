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
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}
int n,m,cnt;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
int t=1;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node,bool&cycle)
{
    visited[node]=t++;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child,cycle);
        }
        else
        {
            cout<<node+1<<" "<<child+1<<endl;
            if(t-visited[node]>1)cycle=1;
        }
    }
}
int main()
{
    File();
    ll x,n,m;
    while(cin>>n&&n!=EOF)
    {
        cin>>m;
        vector<vector<ll>>v(1000001);
        for(ll i=0;i<n;++i)
        {
            cin>>x;
            v[x].push_back(i+1);
        }
        while(m--)
        {
            ll freq,element;
            cin>>freq>>element;
            if(sz(v[element])<freq)cout<<0<<endl;
            else cout<<v[element][freq-1]<<endl;
        }
    }


















}// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
