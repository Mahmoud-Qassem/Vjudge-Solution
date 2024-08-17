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
void floyd(vector<vector<double>>&v)
{
    int n=sz(v);
    for(int k=0; k<n; ++k)
        for(int i=0; i<n; ++i)
            for(int j=0; j<n; ++j)
                v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
#define EPS 1e-1
int32_t main()
{
    Fast();
    File();
    int n,m;
    while(cin>>n>>m)
    {
        if(not n&&not m)break;
        vector<vector<double>>v(n,vector<double>(n,OO));
        vector<vector<double>>ppt,tmp22;
        vector<vector<double>>dd(n,vector<double>(n));
        vector<pair<double,double>>diss(n);
        for(int i=0; i<n; ++i)
        {
            cin>>diss[i].F>>diss[i].S;
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                dd[i][j]=sqrt( pow( (diss[i].F-diss[j].F) ,2)+pow( (diss[i].S-diss[j].S) ,2) );
            }
        }
        for(int i=0; i<m; ++i)
        {
            int from,to;
            cin>>from>>to;
            from--,to--;
            v[from][to]=v[to][from]=dd[from][to];
        }
        for(int i=0;i<n;++i)v[i][i]=0;
        tmp22=v;
        floyd(v);
        ppt=v;
        set<tuple<pair<double,double>,int,int>>ans;
        for(int i=0; i<n; ++i)
        {
            for(int j=0; j<n; ++j)
            {
                if(tmp22[i][j]==OO&&dd[i][j]<v[i][j])
                {
                    vector<vector<double>>tmp=ppt;
                    tmp[i][j]=tmp[j][i]=dd[i][j];
//                    floyd(tmp);
                    double dif=0.0;
                    for(int si=0; si<n; ++si)
                        for(int sj=0; sj<n; ++sj)
                        {
                            tmp[si][sj]=min(tmp[si][sj],tmp[si][i]+tmp[i][j]+tmp[j][sj]);
                            tmp[si][sj]=min(tmp[si][sj],tmp[si][j]+tmp[i][j]+tmp[i][sj]);
                            dif+=v[si][sj]-tmp[si][sj];
                        }

                        if(dif-1.0>EPS)
                    ans.insert({{-dif ,dd[i][j] },min(i,j) ,max(i,j) });
                }
            }
        }
        if(not sz(ans))
        {
            cout<<"No road required"<<endl;
        }
        else
        {
            auto it=ans.begin();
            cout<<get<1>(*it)+1<<" ";
            cout<<get<2>(*it)+1<<endl;
        }








    }


























}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
