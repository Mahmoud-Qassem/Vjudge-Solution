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
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
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
    File();
    int x,ne,t=1;
    while(cin>>x)
    {
        vector<vector<int>>v(20,vector<int>(20,OO));
        for(int i=0; i<20; ++i)v[i][i]=00;
        while(x--)
        {
            cin>>ne;
            ne--;
            v[0][ne]=v[ne][0]=1;
        }
        for(int i=1; i<=18; ++i)
        {
            cin>>x;
            while(x--)
            {
                cin>>ne;
                ne--;
                v[i][ne]=v[ne][i]=1;
            }
        }
        ncubic(v);
        int q;
        cin>>q;
        cout<<"Test Set #"<<t++<<endl;
        for(int i=1;i<=q;++i)
        {
            int from,to;
            cin>>from>>to;
            cout<<setfill(' ')<<setw(2)<<from<<" to ";
            cout<<setfill(' ')<<setw(2)<<to<<": "<<v[from-1][to-1]<<endl;
        }
        cout<<endl;





    }



















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
