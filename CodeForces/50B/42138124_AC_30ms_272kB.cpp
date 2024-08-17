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

long long help(long long x)
{
    long long cnt = 0;
    while (x >= 5)
    {
        cnt += x / 5;
        x /= 5;
    }
    return cnt;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    string s;
    cin>>s;
    int n=s.size();
    long long ans=0LL;
    vector<long long>fr(333);
    for(int i=0; i<n; ++i)
    {
        fr[s[i]]++;
    }

    for(int j=0; j<333; ++j)
    {
        ans+=(fr[j]*(fr[j]));
    }
    cout<<ans<<endl;


}
