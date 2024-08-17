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
#define EPS 1e-1
bool subseq(string&tmp,string&t)
{
    int idx=0;
    for(int i=0; i<sz(tmp); ++i)
    {
        if(tmp[i]==t[idx])idx++;
        if(idx==sz(t))return 1;
    }
    return 0;
}
int32_t main()
{
    Fast();
    T
    {
        string mother ,father ,all,child,all_child;
        cin>>mother>>father;
        int m;
        cin>>m;
        all=mother+father;
        while(m--)cin>>child,all_child+=child;
        map<char,int>mp;
        for(int i=0;i<sz(all);++i)
        {
            mp[ all[i] ]++;
        }
        bool valid=1;
        for(int i=0;i<sz(all_child)&&valid;++i)
        {
            if(not mp[ all_child[i] ])valid=0;
            else mp[ all_child[i] ]--;
        }

        if(valid)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;




    }

















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
