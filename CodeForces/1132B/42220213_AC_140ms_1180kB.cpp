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
#define scan(dx) int (dx);cin>>(dx);
bool isdiv(string s,string ss)
{
    int n=s.size();
    int m=ss.size();
    int idx=0;
    for(int i=0; i<n; ++i)
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
    for(long long k=0; k<n; ++k)
        for(long long i=0; i<n; ++i)
            for(long long j=0; j<n; ++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>>n;
    vector<int>v(n);
    long long sum=0;
    for(auto&it:v)cin>>it,sum+=it;
    int q;
    cin>>q;
    sort(all(v));
    while(q--)
    {
        scan(x)
        cout<<sum-(v[n-x])<<endl;

    }


















}
