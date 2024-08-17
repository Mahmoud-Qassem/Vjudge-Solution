#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define here cout<<"here"<<endl;
#define pi 3.141592653589793
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    cyan
    T
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int one=count(all(s),'1'),zero=sz(s)-one;
        if(one==zero)
        {
            cout<<"YES"<<endl;
            cout<<1<<" "<<n<<endl;
            continue;
        }
        else if(n&1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(one<zero)
        {
            cout<<"YES"<<endl;
            int l=0,r=0,ones=0,zeroes=0,dif=zero-one;
            dif/=2;
            while(r<n&&zeroes-ones<dif)
            {
                zeroes+=(s[r]=='0');
                ones+=(s[r]=='1');
                r++;
            }
            cout<<1<<" "<<r<<endl;

        }
        else
        {
            cout<<"YES"<<endl;
            int l=0,r=0,zeroes=0,ones=0,dif=one-zero;
            dif/=2;
            while(r<n&&ones-zeroes<dif)
            {
                ones+=(s[r]=='1');
                zeroes+=(s[r]=='0');
                r++;
            }
            cout<<1<<" "<<r<<endl;

        }





    }







}





