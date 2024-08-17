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
vector<short>dx= {0,0,-1,1};
vector<short>dy= {0,0,-1,1};
int n,m;
bool valid(int x,int y)
{
    return x>=0 and x<2 and y>=0 and y<n;
}
vector<vector<char>>v;
void help(int x,int y,int&cnt)
{
    int add=(v[x][y]=='0'?-1:1);
//    cout<<x<<" "<<y<<" "<<add<<endl;
    if(x==0)
    {
        if(valid(x+1,y))if(v[x+1][y]=='1')cnt+=add;
        if(valid(x+1,y-1))if(v[x+1][y-1]=='1')cnt+=add;
        if(valid(x+1,y+1))if(v[x+1][y+1]=='1')cnt+=add;
    }
    else
    {
        if(valid(x-1,y))if(v[x-1][y]=='1')cnt+=add;
        if(valid(x-1,y-1))if(v[x-1][y-1]=='1')cnt+=add;
        if(valid(x-1,y+1))if(v[x-1][y+1]=='1')cnt+=add;
    }

}



int32_t main()
{
    Fast();
    cin>>n>>m;
    v=vector<vector<char>>(2,vector<char>(n,'0'));
    int cnt=0;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        if(v[x][y]=='0')
            v[x][y]='1';
        else
            v[x][y]='0';
//            for(int i=0;i<n;++i)cout<<v[0][i];cout<<endl;
//            for(int i=0;i<n;++i)cout<<v[1][i];cout<<endl;
        help(x,y,cnt);
//        cout<<cnt<<endl;
        if(cnt)cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }





























}
