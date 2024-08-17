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
int n;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<n ;
}
vi dx= {0,0,1,-1};
vi dy= {1,-1,0,0};
void dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child);
        }
    }
    cout<<node+1<<" ";
}

int main()
{
    File();
    int n,m;
    cin>>n>>m;
    vector<vector<int>>matrix(n,vector<int>(n+1,0));
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        matrix[from][to]=1;matrix[from][n]++;
        matrix[to][from]=1;matrix[to][n]++;
    }
    bool still=1;
    int ans=0;
    while(still)
    {
        still=0;
        vector<int>cur;
        for(int i=0;i<n;++i)
        {
            if(matrix[i][n]==1)
            {
                int idx=max_element(matrix[i].begin(),matrix[i].begin()+n)-matrix[i].begin();
                cur.push_back(i);
                matrix[i][n]--;
                still=1;
            }
        }
        for(int i=0;i<sz(cur);++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[j][cur[i] ])matrix[j][n]--;
                matrix[j][cur[i]]=0;
            }
        }


        ans+=still;





    }
    cout<<ans<<endl;















}
