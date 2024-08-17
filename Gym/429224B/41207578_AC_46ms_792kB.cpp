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
    int n,m,k;
    cin>>n>>m>>k;
    v=vector<int>(n);
    vv=vector<int>(m);
    for(auto&it:v)cin>>it;
    for(auto&it:vv)cin>>it;
    sort(all(v));
    sort(all(vv));
    int l=0,r=0;
//    5 5 1
//    10 20 30 40 50
//    9 21 30 38 50
int cnt=0;
    while(l<n and r<m)
    {
        if(abs(v[l]-vv[r])<=k)
        {
            cnt++;
            l++;
            r++;
        }
        else if(v[l]<vv[r])l++;
        else if(v[l]>vv[r])r++;




    }
    cout<<cnt<<endl;





}






