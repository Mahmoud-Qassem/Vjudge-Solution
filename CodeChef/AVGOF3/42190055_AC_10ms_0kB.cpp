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
        int x;
        cin>>x;
        bool done=0;
        for(int i=1;i<=2 and not done;++i)
        {
            for(int j=i+1;j<=1000 and not done;++j)
            {
                for(int k=j+1 ;k<=1000 and not done;++k)
                {
                    if((i+j+k)%3==0 and (i+j+k)/3==x )
                    {
                        cout<<i<<" "<<j<<" "<<k<<endl;
                        done=1;
                    }
                }
            }
        }











    }



}
