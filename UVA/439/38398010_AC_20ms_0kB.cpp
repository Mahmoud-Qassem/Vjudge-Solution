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
void dfs(vector<vector<char>>&v,int x,int y)
{
    v[x][y]='0';
    for(int i=0;i<8;++i)
    {
        int xx=dx[i]+x;
        int yy=dy[i]+y;
        if(valid(xx,yy)&&v[xx][yy]=='1')
        {
            dfs(v,xx,yy);
        }
    }
}
int main()
{
    File();
    string s,ss;
    while(cin>>s>>ss)
    {
        int a,b,x,y;
        a=s[0]-'a',x=ss[0]-'a',b=s[1]-'1',y=ss[1]-'1';
        queue<pair<int,int>>q;
        q.push({a,b});
        int level=0;
        for(int sz=sz(q);sz;sz=sz(q),level++)
        {
            bool done=0;
            while(sz--)
            {
                int curX=q.front().F;
                int curY=q.front().S;
                q.pop();
                if(curX==x&&curY==y)
                {
                    done=1;
                    break;
                }
                for(int i=0;i<8;++i)
                {
                    int xx=dx[i]+curX,yy=dy[i]+curY;
                    if(valid(xx,yy))
                    {
                        q.push({xx,yy});
                    }
                }
            }
            if(done)break;
        }
        cout<<"To get from "<<s<<" to "<<ss<<" takes "<<level<<" knight moves."<<endl;

    }
}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
