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
#define OO 1e4
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (ll)( sqrt(2*n+0.25)-0.5  )
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
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
void floyd(vector<vector<double>>&v)
{
    int n=sz(v);
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}

vector<int>fr;
int k;
bool help(int mid)
{
    vector<int>mp=fr;
    bool still=1;
    int cnt=0;
    int tmp=mid;
    mid=0;
    while(not mid)
    {
        mid=tmp;
        if(mid&1)
        {
            bool odd_found=0;
            for(int i=0;i<26;++i)
            {
                if(mp[i]&1)
                {
                    mp[i]--;
                    odd_found=1;
                    break;
                }
            }
            if(not odd_found)
            {
                for(int i=0;i<26;++i)if(mp[i]){mp[i]--;odd_found=1;break;}
            }
            if(not odd_found)
            {
                break;
            }
            mid--;
        }
        for(int i=0;i<26&&mid;++i)
        {
            if(mp[i]<=mid)
            {
                if(mp[i]&1)
                {
                    mid-=mp[i]-1;
                    mp[i]=1;
                }
                else
                {
                    mid-=mp[i];
                    mp[i]=0;
                }
            }
            else
            {
                mp[i]-=mid;
                mid=0;
                break;
            }
        }
        if(not mid)cnt++;
    }
    return cnt>=k;



}
int32_t main()
{
    Fast();
    T
    {
        fr=vector<int>(26,0);
        int n;
        cin>>n>>k;
        string s;
        cin>>s;
        for(int i=0;i<sz(s);++i)fr[ s[i]-'a' ]++;
//        for(auto&it:fr)cout<<it;cout<<endl;
        int l=1,r=sz(s),mid,ans=1;
        while(l<=r)
        {
            mid =(l+r)/2;
            if(help(mid))
            {
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<endl;
    }

















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
