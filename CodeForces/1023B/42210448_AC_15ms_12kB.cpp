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
//    T
    {
        long long n,k;
        cin>>n>>k;
        if(n>=k)cout<<(k-1)/2<<endl;
        else if(n <= k/2)cout<<0<<endl;
        else
        {
            long long mx=(k-1)/2;
            //    1 14    2 13    3 12   4 11  5 10  6 9     7 8
           //     1 15    2 14    3 13   4 12  5 11  6 10    7 9     8 8
           //  n-(k-1)/2
            n=min(n,k);
            if(k%2==0)
            cout<<abs(n-(k-1)/2)-1<<endl;
            else
            cout<<abs(n-(k-1)/2)<<endl;
        }

    }








}
