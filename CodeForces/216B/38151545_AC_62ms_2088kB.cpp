#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define vii vector<vector<int>>
#define fast  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
///*  cout << fixed << setprecision(7);
vii v;
void dfs(vector<int>&colors,int node,int new_color)
{
    colors[node]=new_color;
    for(auto&it:v[node])
    {
        if(!colors[it])
        {
            dfs(colors,it,3-new_color);
        }
        else if(colors[it]==colors[node]&&colors[it]!=-1)
        {
            colors[it]=-1;
        }
    }
}


int main()
{
    fast
    int n,m;
    cin>>n>>m;
    v=vii(n);
    for(int i=0; i<m; ++i)
    {
        int from,to;
        cin>>from>>to;
        from--;
        to--;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    vi colors(n);
    for(int i=0; i<n; ++i)
    {
        if(!colors[i])
            dfs(colors,i,1);
    }
    int cnt=0;
    for(auto&it:colors)
    {
        if(it==-1)cnt++;
    }
    cout<<(cnt+((n-cnt)%2))<<endl;














}