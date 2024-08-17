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

void ncubic(vector<vector<int>>&v)
{
    int n=sz(v);
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]),
                        v[j][i]=min(v[j][i],v[j][k]+v[k][i]);
}

int32_t main()
{
    Fast();
    int n,m;
    cin>>n;m=n*(n-1)/2;m--;
    vector<vector<int>>v(n,vector<int>(n,OO));
    for(int i=0;i<n;++i)v[i][i]=0;
    vector<int>players_games(n);
    for(int i=0;i<m;++i)
    {
        int from,to;
        cin>>from>>to;
        from--,to--;
        players_games[to]++;
        players_games[from]++;
        v[from][to]=1;
    }
    int missed1=-1,missed2=-1;
    for(int i=0;i<n;++i)
    {
        if(players_games[i]<n-1)
        {
            if(missed1!=-1){missed2=i;break;}
            else
            {
                missed1=i;
            }
        }
    }
    ncubic(v);
//    for(int i=0;i<n;++i)
//    {
//        for(int j=0;j<n;++j)
//            cout<<v[i][j]<<" ";cout<<endl;
//    }

    if(v[missed1][missed2]!=OO)cout<<missed1+1<<" "<<missed2+1<<endl;
    else cout<<missed2+1<<" "<<missed1+1<<endl;
















}
