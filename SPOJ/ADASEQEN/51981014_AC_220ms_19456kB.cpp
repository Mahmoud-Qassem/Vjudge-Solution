#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
const int M=1e9+5;
//bool valid(int x,int y) {
//    return (x>=1 and y>=1 and x<=n and y<=m);
//}
int dx[]= {0,0,-1,1,1,1,-1,-1};
int dy[]= {1,-1,0,0,1,-1,-1,1};
vector<int>cost(26);
int rec(string s, string ss, int m, int n)
{
    int dp[m+1][n+1];
    for(int i=0;i<=m;++i) {
        for(int j=0;j<=n;++j) {
            if (i==0 || j==0)
                dp[i][j]=0;
            else if (s[i-1]==ss[j-1])
                dp[i][j]=dp[i-1][j-1]+cost[s[i-1]-'a'];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m][n];
}


int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(auto&it:cost)cin>>it;
    string a,b;
    cin>>a>>b;
    cout<<rec(a,b,n,m);



}

