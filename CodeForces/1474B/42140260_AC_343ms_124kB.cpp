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


const int r=30099;
bool arr[r];
vector<long long>primes;
void makePrimes()
{
    arr[0]=1,arr[1]=1;
    memset(arr,0,sizeof(arr));
    for(long long i=2;i<r;++i)
    {
        if(!arr[i])primes.push_back(i);
        for(long long j=0;j<primes.size() and i*primes[j]<=r;++j)
        {
            arr[ primes[j]*i ]=1;
            if(i*primes[j]==0)break;
        }
    }
}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);


    makePrimes();

    T
    {
        long long d;cin>>d;
        long long n=primes.size();
        long long mn=LONG_LONG_MAX;
        long long dx=lower_bound(all(primes),1+d)-primes.begin();
        for(long long i=dx;i<n;++i)
        {
            long long idx=lower_bound(all(primes),primes[i]+d)-primes.begin();
            if(idx != n)
                mn=min(mn,primes[i]*primes[idx]);
        }
        cout<<mn<<endl;









    }
}
