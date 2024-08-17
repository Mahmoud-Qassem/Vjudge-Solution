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
void dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            cnt++;
            dfs(v,visited,child);
        }
    }
}
int main()
{
    File();
    T
    {
        int n;
        cin>>n;
        vector<vector<int>>v(n);
        for(int i=0;i<n;++i)
        {
            int ne;
            while(cin>>ne)
            {
                v[i].push_back(ne-1);
                char c;
                cin.get(c);
                if(c==10)break;
            }
        }
        vector<pair<int,int>>ans;
        for(int i=0;i<n;++i)
        {
            ans.push_back({sz(v[i]),i+1});
        }
        sort(all(ans));
        int mn=ans[0].F;
        cout<<ans[0].S;
        int idx=1;
        while(ans[idx].F==mn)cout<<" "<<ans[idx++].S;
        cout<<endl;


    }











}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
