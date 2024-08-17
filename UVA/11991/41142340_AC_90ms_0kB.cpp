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
    freopen("testCase_input.txt", "r", stdin);
//    freopen("testCase_actualOutput.txt", "w", stdout);

}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int32_t main()
{
    Fast();
    int n;
    while(cin>>n && n)
    {
        int m;
        cin>>m;
        vector<vector<int>>v(1e6+5);
        for(int i=0;i<n;++i)
        {
            int ele;
            cin>>ele;
            v[ele].push_back(i+1);
        }
        for(int i=0;i<m;++i)
        {
            int k,e;
            cin>>k>>e;
            if(v[e].size()<k)cout<<0<<endl;
            else cout<<v[e][k-1]<<endl;
        }
    }







}





