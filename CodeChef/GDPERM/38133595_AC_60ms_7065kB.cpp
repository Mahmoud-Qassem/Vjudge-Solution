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
bool mxx(string&a,string&b)
{
    if(sz(a)!=sz(b))return sz(a)>sz(b);
    return a>b;
}
int n;
int pp(int x)
{
    int idx=x,sum=0;
    for(int i=0; i<n; ++i)
    {
        sum+=idx++;
    }
    return sum;
}
int main()
{
    cyan
    T
    {
        int n;
        cin>>n;
        vi v(n);
        if(n==1||n==3){cout<<-1<<endl;continue;}
        else if(n==5)
        {
            cout<<"2 3 5 1 4"<<endl;continue;
        }
        else if(n==2)
        {
            cout<<"2 1"<<endl;continue;
        }
        for(int i=0; i<n; ++i)v[i]=i+1;
        reverse(all(v));
        if(n%2==0)
        {
            for(auto&it:v)cout<<it<<" ";cout<<endl;continue;
        }
        swap(v[n/2],v[n/2+1]);
        sort(v.begin()+n-3,v.end());
        do
        {
            bool done =1;
            int xoor=0;
            for(int i=0; i<n; ++i)
            {
                if(v[i]==(i+1))
                {
                    done=0;
                    break;
                }
                xoor^=abs(v[i]-i-1);
            }
            if(done && !xoor)
            {
                if(1)
                {
                    for(auto&it:v)cout<<it<<" ";
                    cout<<endl;
                    break;
                }
            }
        }
        while(next_permutation(all(v)));









    }


}









//    vi v(2005);
//    int x=-1000;
//    for(int i=1;i<2005;++i)v[i]=x++;
//    for(int i=1;i<2005;++i)v[i]+=v[i-1];
//    T
//    {
//
//    int x;
//    cin>>n>>x;
//    for(int i=-1000,idx=0;i<=1000-n;++i)
//    {
//        int tmp=v[i+n+2]-v[i];
//        if((tmp/n)==x)
//        {
//            for(int j=0;j<n;++j)cout<<i++<<" ";
//            cout<<endl;
//            break;
//        }
//    }
//
//    }
//
//

