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
        int n;
        cin>>n;
        string s,ans=string(n,'0');
        cin>>s;
        char pr='3';
        for(int i=0;i<n;++i)
        {
            for(char c='2';c>='0';--c)
            {
                if(c==pr)continue;
                if(c=='2' and s[i]=='1')
                {
                    ans[i]='1';
                    pr='2';
                    break;
                }
                else if(c=='1' and s[i]=='0')
                {
                    ans[i]='1';
                    pr='1';
                    break;
                }
                else if(c=='1' and s[i]=='1')
                {
                    ans[i]='0';
                    pr='1';
                    break;
                }
                else if(c=='0' and s[i]=='0')
                {
                    ans[i]='0';
                    pr='0';
                    break;
                }
            }
        }
        cout<<ans<<endl;
    }



}
