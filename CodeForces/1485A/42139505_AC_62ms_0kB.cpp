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

int calc(int a,int b)
{
    int cnt=0;
    while(a)
    {
        cnt++;
        a/=b;
    }
    return cnt;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T
    {
        int a,b;
        cin>>a>>b;
        int mn=1e9;
        for(int i=0;i<=1e5;++i)
        {
            if(b==1 and i==0)continue;
            mn=min(mn,i+calc(a,b+i));
        }
        cout<<mn<<endl;

    }
}
