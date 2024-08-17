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
//    File();
    int n;
//    cin>>n;
    while(cin>>n)
    {
        int m,boss_home,office,my_home,market;
        cin>>m>>boss_home>>office>>my_home>>market;
        vector<vector<int>>v(n,vector<int>(n,OO));
        vector<vector<int>>vv(n,vector<int>(n,OO));
        for(int i=0;i<n;++i)v[i][i]=0;
        my_home--,market--;
        boss_home--,office--;
        for(int i=0;i<m;++i)
        {
            int from,to,cost;
            cin>>from>>to>>cost;
            from--,to--;
            v[from][to]=v[to][from]=cost;
        }
        vv=v;
        ncubic(v);
        bool did_not_path_my_home_or_market=1;
        for(int i=0;i<n;++i)
        {
            // if the distance from boss home to this place and the dist from this palce
            // to the office less than the dist from the boss home to the office
            // so he walk on it on his way

            if(v[boss_home][i]+v[i][office]<=v[boss_home][office])
            {
                if(i==my_home||i==market)did_not_path_my_home_or_market=0;
                for(int j=0;j<n;++j)
                {
                    vv[i][j]=vv[j][i]=OO;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            vv[i][boss_home]=vv[boss_home][i]=OO;
            vv[i][office]=vv[office][i]=OO;
        }
        ncubic(vv);
        if(vv[my_home][market]!=OO&&did_not_path_my_home_or_market)cout<<vv[my_home][market]<<endl;
        else cout<<"MISSION IMPOSSIBLE."<<endl;







    }






































}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
