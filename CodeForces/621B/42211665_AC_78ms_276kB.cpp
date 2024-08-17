// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define T int tst;cin>>tst;while(tst--)
bool isdiv(string s,string ss)
{
    int n=s.size();
    int m=ss.size();
    int idx=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=ss[idx])return 0;
        idx++;
        idx%=m;
    }
    return 1;



}
const long long inf=1000000000000 ;


void floyd(vector<vector<long long>>&v)
{
    long long n=v.size();
    for(long long k=0;k<n;++k)
        for(long long i=0;i<n;++i)
            for(long long j=0;j<n;++j)
            v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long n;
    cin>>n;
    map<long long,long long>mp,mpp;
    for(long long i=0;i<n;++i)
    {
        long long x,y;
        cin>>x>>y;
        mp[x+y]++;
        mpp[x-y]++;
    }
    long long ans=0;
    for(auto&it:mp)
    {
        long long k=it.second;
        ans+=(k*(k-1))/2;
    }
    for(auto&it:mpp)
    {
        long long k=it.second;
        ans+=(k*(k-1))/2;
    }
    cout<<ans<<endl;





}
