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
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}
vector<vector<char>>v;
bool win(string grid)
{
    int idx=0;
    vector<vector<char>>tmp(10,vector<char>(10));
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<3;++j)
        {
            tmp[i][j]=grid[idx++];
        }
    }
    string s,ss;
    for(int i=0; i<3; ++i)s+=tmp[i][i],ss+=tmp[i][2-i];
    if(s=="OOO"||s=="XXX")return 1;
    if(ss=="OOO"||ss=="XXX")return 1;
    for(int i=0; i<3; ++i)
    {
        string s;
        for(int j=0; j<3; ++j)
            s+=tmp[i][j];
        if(s=="OOO"||s=="XXX")return 1;
    }
    for(int i=0; i<3; ++i)
    {
        string s;
        for(int j=0; j<3; ++j)
            s+=tmp[j][i];
        if(s=="OOO"||s=="XXX")return 1;
    }
    return 0;



}

int main()
{
//    cyan
    T
    {
       string grid;
       int x=3;
       while(x--)
       {
           string s;
           cin>>s;grid+=s;
       }
       // bfs   we can get the shortest path from an empty config to the given config if found
       queue<pair<string,bool>>q;
       q.push({".........",1});
       string ans="no";
       while(sz(q))
       {

           string cur=q.front().F;
           bool player=q.front().S;
           q.pop();
           if(cur==grid)
           {
               ans="yes";
               break;
           }
           if(win(cur))continue;
           for(int i=0;i<9;++i)
           {
               if(cur[i]=='.')
               {
                   if(player)cur[i]='X';
                   else cur[i]='O';
                   if(cur[i]==grid[i])
                   {
                       q.push({cur,1^player});
                   }
                   cur[i]='.';
               }
           }
       }
       cout<<ans<<endl;













    }



  





}
