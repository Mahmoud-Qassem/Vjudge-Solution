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
    long long n,m,a,b,x,y,tmp=12800000;
    cin>>n>>m>>a>>b;
    long long  mn=1e9;
    if(b/m==a and b%m==0)cout<< n*a<<endl;
    else cout<<min({ (n*a), (((n/m)*b)+(n%m)*a ), (long long)(ceil(n*1.00/m)*b)});

}
