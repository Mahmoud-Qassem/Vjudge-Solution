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
    int n;
    int t=1;
    while(cin>>n)
    {
        if(not n)break;
        int idx=0;
        string s;
        vector<vector<double>>v(n,vector<double>(n,0.0));
        map<string,int>mp;
        for(int i=0; i<n; ++i)cin>>s,mp[s]=idx++;

        int m;
        cin>>m;
        for(int i=0; i<m; ++i)
        {
            string s,ss;
            double cc;
            cin>>s>>cc>>ss;
            int from=mp[s],to=mp[ss];
            v[from][to]=max(cc,v[from][to]);
        }

        cout<<"Case "<<t++<<": ";
        bool valid=0;

        for(int k=0; k<n; ++k)
            for(int i=0; i<n; ++i)
                for(int j=0; j<n; ++j){
                    if(i==j)v[i][j]=max(v[i][j],1.0);
                    v[i][j]=max(v[i][j],v[i][k]*v[k][j]);}


        for(int i=0; i<n; ++i)valid|=(v[i][i]>1);

        if(valid)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;




    }





























}
