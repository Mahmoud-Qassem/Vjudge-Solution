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
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
//-----------------------------------------------
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T
    {
        string small ,large;
        cin>>small>>large;
        int mn=small.size(),mx=large.size();
        if(mn>mx)
        {
            swap(small,large);
            swap(mn,mx);
        }

        int lc=lcm(mn,mx),x=lc/mn;
        string ans;
        while(x--)ans+=small;
        bool valid=1;
        valid&=isdiv(ans,small);
        valid&=isdiv(ans,large);
        if(valid)
        cout<<ans<<endl;
        else cout<<-1<<endl;



    }



}
