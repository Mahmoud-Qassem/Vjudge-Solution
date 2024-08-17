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
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int n,m;
bool valid(int x,int nn)
{
    return (x>=0&&x<nn);
}
vi dx={0,0,-1,1};
vi dy={-1,1,0,0};
vector<vector<int>>v;
bool ok_with(int x,int i,int j)
{
    for(int k=0;k<sz(dx);++k)
    {
        if(valid(i+dx[k],n)&&valid(j+dy[k],m)&&v[i+dx[k]][j+dy[k]]==x)return 0;
    }
    return 1;
}

void rec(int x,int y)
{
    for(int i=0;i<sz(dx);++i)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(valid(xx,n)&&valid(yy,m))
        {
            if(!v[xx][yy])
            for(int j=1;;j++)
            {
                if(ok_with(j,xx,yy))
                {
                    v[xx][yy]=j;
                    rec(xx,yy);
                    break;
                }
            }
        }
    }


}
int main()
{
    cyan
    T
    {
        cin>>n>>m;
        v=vector<vector<int>>(n,vector<int>(m,0));
        int x,y,xx,yy;
        cin>>x>>y>>xx>>yy;
        x--,y--;
        xx--,yy--;
        v[x][y]=1;
        v[xx][yy]=2;
        rec(x,y);
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)cout<<v[i][j]<<" ";cout<<endl;
        }

    }
















}





