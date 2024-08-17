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
    srand(time(0));
    T
    {
        int n,x;
        cin>>n>>x;
        if(n==1)
        {
            cout<<x<<endl;
            continue;
        }
        int ans=x*n;
        int tmp=x*n;
        int ii=0;
        vi v(n,0);
        int pos=1000;
        unordered_map<int,bool>mp;
        for(int i=0; i<n; ++i)
        {
            v[ii++]=pos;
            mp[pos]=true;
            ans-=pos;
            pos--;
            if(ans<=0)break;
        }
        int neg=-1000;
        while(ans<0)
        {
            if(neg>=ans)
            {
                mp[-(neg)]=true;
                ans-=neg;
                v[ii++]=neg;
            }
            neg++;

        }
        int lol=1;
        for(int i=n-1;i>0;--i)
        {
            if(!v[i-1])
            {
                if(mp[lol]){i++;lol++;continue;}
                v[i]=lol;
                v[i-1]=-lol;
                mp[lol]=true;
                lol++;
                i--;
            }
        }
        int kk=accumulate(all(v),0);

        for(auto&it:v)cout<<it<<" ";cout<<endl;
//        cout<<sz(v)<<endl<<kk<<endl<<(kk/n)<<endl<<(kk%n)<<endl;




    }
















}





