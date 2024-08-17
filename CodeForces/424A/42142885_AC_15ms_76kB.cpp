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
    for(long long i=2; i<r; ++i)
    {
        if(!arr[i])primes.push_back(i);
        for(long long j=0; j<primes.size() and i*primes[j]<=r; ++j)
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
    int n;
    cin>>n;
    string s;
    cin>>s;
    int stand=n/2,sit=n/2;

    vector<string>v;
    for(int i=0; i<n; ++i)
    {
        if(s[i]=='X')
        {
            stand--;
        }
        else
        {
            sit--;
        }
        if(sit<0)
        {
            sit=0;
            stand--;
            s[i]='X';
            v.push_back(s);
        }
        if(stand<0)
        {
            sit--;
            stand=0;
            s[i]='x';
            v.push_back(s);
        }
    }
    cout<<v.size()<<endl;cout<<s<<endl;

}
