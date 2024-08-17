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
#define OO 1e7
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

//void ncubic(vector<vector<int>>&v)
//{
//    int n=sz(v);
//    for(int k=0; k<n; ++k)
//        for(int i=0; i<n; ++i)
//            for(int j=i+1; j<n; ++j)
//                v[i][j]=min(v[i][j],v[i][k]+v[k][j]),
//                        v[j][i]=min(v[j][i],v[j][k]+v[k][i]);
//}
ll help(vi v,ll mid)
{
    ll ans=0;
    for(int i=0; i<sz(v); ++i)
    {
        ans+=ceil(v[i]*1.00/mid*1.00);
    }
    return ll(ans);
}

int32_t main()
{
    Fast();
    T
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(k);
        vector<int>vv(k);
        for(int i=0; i<k-1; ++i)
            v[i]=1;
        v[k-1]=n-k+1;
        for(int i=0; i<k-1; ++i)
            vv[i]=2;
        vv[k-1]=n-(k*2-2);


        bool valid=1,barity=(v[0]&1);
        for(int i=0; i<k; ++i)
        {
            if(v[i]<=0 or(v[i]&1) != barity)
            {
                valid=0;
            }
        }
        if(valid)
        {
            cout<<"YES"<<endl;
            for(auto&it:v)cout<<it<<" ";
            cout<<endl;
        }
        else
        {

            bool valid=1,barity=(vv[0]&1);
            for(int i=0; i<k; ++i)
            {
                if(vv[i]<=0 or(vv[i]&1) != barity)
                {
                    valid=0;
                }
            }
            if(valid)
            {
                cout<<"YES"<<endl;
                for(auto&it:vv)cout<<it<<" ";
                cout<<endl;
            }
            else
            {
                cout<<"NO"<<endl;

            }
        }
    }





//    int n,k;
//    cin>>n>>k;
//    vector<vector<int>>vv(n);
//    vector<int>bages(n);
//    for(auto&it:bages)cin>>it;










}
