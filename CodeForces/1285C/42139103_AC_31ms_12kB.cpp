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
    long long n;
    cin>>n;
    long long s=sqrt(n);
    long long ans=LONG_LONG_MAX,aa=1,bb=n;

    for(int i=1;i<=s;++i)
    {
        if(n%i==0)
        {
            long long a=i,b=n/i;
            if(lcm(a,b)!=n)continue;
            if(ans>max(a,b))
            {
                ans=max(a,b);
                aa=a,bb=b;
            }
        }
    }
    cout<<aa<<" "<<bb<<endl;

}
