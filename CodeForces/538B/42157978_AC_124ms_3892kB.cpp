// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define T int t;cin>>t;while(t--)
int32_t main()
{

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);
    vector<int>v;
    v.push_back(1);
    int p=0;
    vector<int>dp(1e6+5,1000);
    dp[1]=1;
    dp[0]=0;
    while(v.back()<=1e6)
    {
        int nn=v.size();
        for(int i=p; i<nn and v.back()<=1e6; ++i)
        {
            v.push_back(v[i]*10);
            dp[v[i]*10]=1;
            v.push_back(v[i]*10+1);
            dp[v[i]*10+1]=1;
        }
        p=nn;
    }
    v.pop_back();
    vector<int>ans;
    for(int i=1; i<1e6+2; ++i)
    {
        for(int j=0; j<64; ++j)
        {
            if(i>=v[j])
            {
                dp[i]=min(dp[i],1+dp[ i-v[j] ]);
            }
        }
    }

    long long n;
    cin>>n;
    cout<<dp[n]<<endl;

    int m=dp[n];
    while(n)
        for(int j=0; j<64; ++j)
        {
            if( n-v[j]>=0 and 1+dp[n-v[j]]==dp[n] )
            {
                cout<<v[j]<<" ";
                n-=v[j];
                break;
            }
        }














}
