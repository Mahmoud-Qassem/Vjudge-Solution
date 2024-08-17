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

vector<int>visited;
vector<int>tmp;
vector<vector<int>>v;

void dfs(int node)
{
    visited[node]=1;
    for(auto&child:v[node])
    {
        if(visited[child] == 0)
            dfs(child);
    }
    tmp.push_back(node);
}
void dfs2(int node)
{
    visited[node]=2;
    for(auto&child:v[node])
        if(visited[child]==1)
        dfs2(child);
}
int main()
{
    File();
    int idx;
    cin>>idx;
    for(int t=1;t<=idx;++t)
    {
        int n,x,y,d,ans=0;
        cin>>n;
        v=vector<vector<int>>(n);
        visited=vector<int>(n,0);
        tmp.clear();

        vector<tuple<int,int,int>>local(n);

        for(int i=0;i<n;++i)
        {
            cin>>get<0>(local[i])>>get<1>(local[i])>>get<2>(local[i]);
        }

        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                int x=get<0>(local[i]);
                int y=get<1>(local[i]);
                int d=get<2>(local[i]);
                d/=2;
                int x2=get<0>(local[j]);
                int y2=get<1>(local[j]);

                if( (x2>=x-d&&x2<=x+d)&&(y2>=y-d&&y2<=d+y) )
                {
                    v[i].push_back(j);
                }
            }
        }



        for(int node=0;node<n;++node) if(visited[node]==0)dfs(node);
        reverse(all(tmp));
        for(auto&i:tmp) if(visited[ i ]==1) dfs2(i),ans++;
        cout<<ans<<endl;
    }

}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
