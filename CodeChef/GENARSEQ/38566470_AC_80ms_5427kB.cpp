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
#define sz(v) (int)v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO 1e18
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
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
    T
    {
        int a,b,n;
        cin>>a>>b>>n;
        vector<int>ans(1005);
        vector<bool>mp(2*1e6);
        for(int i=1;i<=n;++i)
        {
            ans[i]=ans[i-1]+1;
            while(mp[ans[i]])ans[i]++;
            int lol=ans[i];
            for(int j=1;j<=i;++j)
            {
                int aa=a*ans[i]-b*ans[j];
                int bb=a*ans[j]-b*ans[i];
                if(aa>=ans[i])mp[aa]=1;
                if(bb>=ans[i])mp[bb]=1;
            }
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }












}
