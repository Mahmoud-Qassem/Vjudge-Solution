#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define inf 100000LL
#define all(v) (v).begin(),(v.end())
#define clr(v,value) memset(v,value,sizeof(v));

int L,n;
vector<int>v;
const int MX=1001;
int dp[MX][MX];

int solve(int start,int endd)
{
    if(start>=endd)return 0;

    auto&ret=dp[start][endd];
    if(~ret)return ret;

    ret=inf;
    int l=lower_bound(all(v),start)-v.begin();
    int r=lower_bound(all(v),endd)-v.begin();

    bool cool=0;
    for(int k=l; k<r; ++k)
    {
        cool=1;
        int x=solve(start,v[k]);
        int y=solve(v[k]+1,endd);
        ret=min(ret,x+y+(endd-start+1));
    }
    ret*=cool;
    return ret;


}



int32_t main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>L ,L)
    {
        cin>>n;
        clr(dp,-1);
        v.resize(n);
        for(auto&it:v)cin>>it;
        int ans=solve(1,L);
        cout<<"The minimum cutting is "<<ans<<'.'<<endl;
    }



}






