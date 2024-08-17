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
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
void ncube(vector<vector<int>>&v)
{
    int n=sz(v);
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
int32_t main()
{
    Fast();
    int n;
    cin>>n;
    vii v(n,vi(n));
    for(auto&it:v)for(auto&ic:it)cin>>ic;
    vii vv=v;
    int q;
    cin>>q;
    vl ans(q);
    ll cur=0;
    ncube(v);
    for(auto&it:v)for(auto&ic:it)cur+=ic;
    for(int jk=0; jk<q; ++jk)
    {
        int from,to,cost;
        cin>>from>>to>>cost;
        from--,to--;

        if(cost<v[from][to]||cost<v[to][from])
        {
            ll sum=0;
            v[from][to]=v[to][from]=cost;
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j)
                {
                    v[i][j]=min(v[i][j],v[i][from]+v[from][to]+v[to][j]);
                    v[i][j]=min(v[i][j],v[i][to]+v[to][from]+v[from][j]);
                    sum+=v[i][j];
                }
                cur=sum;
        }
        ans[jk]=cur/2;
    }
    for(auto&it:ans)cout<<it<<" ";













}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
