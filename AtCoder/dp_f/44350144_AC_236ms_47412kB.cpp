#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
const int MX=3333;
string a,b;
int dp[MX][MX];
int solve(int i,int j)
{
    if(i==a.size() || j==b.size()  )return 0;

    auto&ret=dp[i][j];
    if(~ret)return ret;
    ret=0;
    if(a[i]==b[j])ret=max(ret,solve(i+1,j+1)+1);
    ret=max(ret,solve(i+1,j));
    ret=max(ret,solve(i,j+1));
    return ret;
}
string ans;
void build(int i,int j)
{
    if(i==a.size() || j==b.size()  )
    {
        return ;
    }

    int best=solve(i,j);

    if(a[i]==b[j])
    {
        ans+=a[i];
        build(i+1,j+1);
    }
    else
    {
        int one=solve(i+1,j);
        int two=solve(i,j+1);
        if(one==best)
        {
            build(i+1,j);
            return ;
        }

        if(two==best)
        {
            build(i,j+1);
            return ;
        }
    }


    return ;
}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    memset(dp,-1,sizeof dp);
    cin>>a>>b;
    solve(0,0);
    build(0,0);
    cout<<ans<<endl;


}
