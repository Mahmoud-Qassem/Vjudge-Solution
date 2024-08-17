#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000000000LL
#define clr(v,value) memset(v,value,sizeof(v));
int n;
vector<ll>v;
ll dp[444][444];
int main()
{
    cin>>n;
    v=vector<ll>(n);
    for(auto&it:v)cin>>it;


    vector<ll>pref(n+5);
    ll cur=0;

    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j)
            dp[i][j]=inf;


    for(int i=0; i<n; ++i)
    {
        cur+=v[i];
        pref[i+1]=cur;
    }
    for(int i=n-1; i>=0; --i)
    {
        for(int j=i; j<n; ++j)
        {
            ll sum=pref[j+1]-pref[i];

            if(i==j)dp[i][j]=0;
            else
            {
                for(int k=i; k<j; ++k)
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum);

            }

        }
    }

    cout<<dp[0][n-1]<<endl;





}
