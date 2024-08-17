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
        ll n;
        cin>>n;
        vector<ll>v(n);
        for(auto&it:v)cin>>it;
        if(n==1){cout<<1<<endl;continue;}
        sort(all(v));
        priority_queue<int>q;
        int cnt=1;
        for(int i=1;i<n;++i)
        {
            if(v[i]!=v[i-1] )
            {
                q.push(cnt);
                cnt=1;
            }
            else cnt++;
        }
        q.push(cnt);
        int lol=0;
        while(sz(q)>1)
        {
            int top=q.top();q.pop();
            int topeltop=q.top();q.pop();
            top--;topeltop--;
            lol+=2;
            if(top)q.push(top);
            if(topeltop)q.push(topeltop);
        }
        cout<<n-lol<<endl;



    }

















}
