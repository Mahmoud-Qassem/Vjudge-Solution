#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef unsigned long long int  ull;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define here cout<<"here"<<endl;
#define pi 3.141592653589793
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) (int)v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO 1e12
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
//    freopen("testCase_input.txt", "r", stdin);
//    freopen("testCase_actualOutput.txt", "w", stdout);

}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
vector<int>v,vv;


int32_t main()
{
//    freopen("FileName.in", "r", stdin);
    Fast();
    long  long n,x;
    cin>>n>>x;
    long long tmp=x;
    double flag=1;
    bool valid=0;
    for(long long i=x;i>1;--i)
    {
        if(flag<1e9 and tmp)flag*=n,tmp--;
        flag/=i;
    }
    while(tmp--)
    {
        flag*=n;
        if(flag>1)break;
    }
    if(flag>1)cout<<"zozo"<<endl;
    else cout<<"zezo"<<endl;

}






