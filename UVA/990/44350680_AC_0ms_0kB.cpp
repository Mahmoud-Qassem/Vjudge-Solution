#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
const int MX=1111;
int k,n,w;
int dp[31][MX],depth[35],coins[35];
int solve(int idx,int oxygen)
{
    if(oxygen<0)return -1e7;
    if(idx==n)return 0;

    auto&ret=dp[idx][oxygen];
    if(~ret)return ret;

    ret=0;

    // take this treasure
    ret=max(ret,solve(idx+1,oxygen-w*depth[idx])+coins[idx]);

    // leave this treasure
    ret=max(ret,solve(idx+1,oxygen));
    return ret;
}
vector<int>ans;
void build(int idx,int oxygen)
{
    if(idx==n)
    {
        return ;
    }


    int best=solve(idx,oxygen);

    int one=solve(idx+1,oxygen-w*depth[idx])+coins[idx];
    int two=solve(idx+1,oxygen);
    if(one==best)
    {
        ans.push_back(idx);
        build(idx+1,oxygen-w*depth[idx]);
        return ;
    }
    else
    {
        build(idx+1,oxygen);
        return ;
    }
    return ;


}


int32_t main()
{
//      freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    bool en=0;
    while(cin>>k and k!=EOF)
    {
        ans.clear();
        if(en)cout<<endl;
        en=1;

        memset(dp,-1,sizeof dp);
        cin>>w>>n;
        w*=3;
        for(int idx=0; idx<n; ++idx)cin>>depth[idx]>>coins[idx];

        cout<<solve(0,k)<<endl;
        build(0,k);
        cout<<ans.size()<<endl;
        for(auto&it:ans)
        {
            cout<<depth[it]<<" "<<coins[it]<<endl;
        }
    }














}
