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
#define OO 1e9
#define clr(v,x) memset(v,x,sizeof(v))
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
int n,m,dp[101][101],c;
vector<vector<int>>v;
bool valid(int x,int y)
{
    return x>=0 and y>=0 and x<n and y<m;
}

int rec(int i,int j)
{
    if(i==n-1)return v[i][j];
    int&ret=dp[i][j];
    if(~ret)return ret;
    ret=0;
    if(valid(i+1,j))
    {
        ret=v[i][j]+rec(i+1,j);
    }
    if(valid(i+1,j+1))
    {
        int x=v[i][j]+rec(i+1,j+1);
        ret=max(x,ret);
    }
    if(valid(i+1,j-1))
    {
        int x=v[i][j]+rec(i+1,j-1);
        ret=max(x,ret);
    }
    return ret;


}


int32_t main()
{
    Fast();
    T
    {
        cin>>n>>m;
        v=vector<vector<int>>(n,vector<int>(m));

        for(auto&it:v)for(auto&ic:it)cin>>ic;

        int mx=0;
        clr(dp,-1);
        for(int i=0;i<m;++i)
        {
            mx=max(mx,rec(0,i));
        }
        cout<<mx<<endl;

    }

}
