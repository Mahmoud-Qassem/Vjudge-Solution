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
        int n,m;
        cin>>n>>m;
        string s,t,help;
        cin>>s>>t;
        bool valid=1;
        for(auto&it:s)if(it!='?')help+=it;
        if(subseq(help,t))valid=0;

        if(not valid)cout<<-1<<endl;
        else
        {
            string lol=t;
            t="abcde";
            int x=0;
            bool done=0;
            while(true)
            {
                int idx=x++;
                string tmp,tmp2;
                for(int i=0; i<sz(s); ++i)
                {
                    if(s[i]=='?')tmp+=t[idx++],tmp2+=t[x-1];
                    else tmp+=s[i],tmp2+=s[i];
                    idx%=sz(t);
                }
                if(!subseq(tmp,lol) )
                {
                    cout<<tmp<<endl;
                    done=1;
                    break;
                }
                else if(!subseq(tmp2,lol))
                {
                    cout<<tmp2<<endl;
                    done=1;
                    break;
                }
               if(x==sz(t))
               if(next_permutation(all(t)))
               {
                   x=0;
               }
               else break;
            }
               if(not done)cout<<-1<<endl;
        }



    }

















}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
