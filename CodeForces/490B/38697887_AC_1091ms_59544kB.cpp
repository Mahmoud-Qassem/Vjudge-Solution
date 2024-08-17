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
#define OO 1e7
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
int n;
unordered_map<int,int>mp2;
vector<int>lft;
vector<int>rit;
vector<bool>visited;
void dfs(int node,vector<vector<int>>&v)
{
    visited[node]=true;
    if(node<n)rit.push_back(node);
    for(auto&it:v[node])
    {
        if(not visited[it])
        {
            dfs(it,v);
        }
    }
}

void dfsRight(int node,vector<vector<int>>&v)
{
    visited[node]=1;
    if(node<n)lft.push_back(node);
    for(auto&it:v[node])
    {
        if(not visited[it])
        {
            dfsRight(it,v);
        }
    }

}

int32_t main()
{
//    Fast();
    cin>>n;
    int idx=1,ppp=n;
    map<int,int>mp;
    vector<int>fr(2*1000000+5);
    vector<vector<int>>v(n*2+5);
    for(int i=0; i<n; ++i)
    {
        int from,to;
        cin>>from>>to;

        if(from and not mp[from])
        {
            mp2[idx-1]=from;
            mp[from]=idx++;
        }
        if(to and not mp[to])
        {
            mp2[idx-1]=to;
            mp[to]=idx++;
        }
        from=mp[from]-1;
        to=mp[to]-1;

        if(from>=0)
        {
            v[from].push_back(ppp);
            fr[ppp]++;
        }
        if(to>=0)
        {
            v[ppp].push_back(to);
            fr[to]++;
        }
        ppp++;
    }
    int frnt=-1,bck=-1;
    for(int i=0;i<n*2;++i)
    {
        if(fr[i]==0)
        {
            if(frnt==-1)frnt=i;
            else
            {
                bck=i;
                break;
            }
        }
    }
    visited=vector<bool>(n*2+5);
    dfs(frnt,v);
    visited=vector<bool>(n*2+5);
    dfsRight(bck,v);
    int i=0,j=0;
    while(i<sz(lft) or j<sz(rit))
    {
        if(j<sz(rit))
        cout<<mp2[rit[j]]<<" ";
        if(i<sz(lft))
        cout<<mp2[lft[i]]<<" ";
        i++,j++;
    }






























}
