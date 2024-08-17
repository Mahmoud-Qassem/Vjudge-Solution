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
#define OO 1e12
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
int help(vector<vector<string>>&v)
{
    int n=sz(v[0]);
    int k=0,kk=0;
    int cnt=0,cnt2=0,idx=0;
    char c=v[0][0][0];
    for(int i=0;i<n*2;++i)
    {
        k=0;
        int x=i;
        if(x>=n)x%=n,k=2;
        for(int j=0;j<n*2;++j)
        {
            int y=j;
            kk=k;
            if(y>=n)y%=n,kk++;


            if(x%2==0 and idx%2==0)
                {if(c!=v[kk][x][y])cnt++;}
            else if(x%2==0 and idx%2==1)
                {if(c==v[kk][x][y])cnt++;}
            else if(x%2==1 and idx%2==0)
                {if(c==v[kk][x][y])cnt++;}
            else if(x%2==1 and idx%2==1)
                {if(c!=v[kk][x][y])cnt++;}

                idx++;
        }
    }




    k=0,kk=0,idx=0;
    for(int i=0;i<n*2;++i)
    {
        k=0;
        int x=i;
        if(x>=n)x%=n,k=2;
        for(int j=0;j<n*2;++j)
        {
            int y=j;
            kk=k;
            if(y>=n)y%=n,kk++;

            if(x%2==0 and idx%2==0)
                {if(c==v[kk][x][y])cnt2++;}
            else if(x%2==0 and idx%2==1)
                {if(c!=v[kk][x][y])cnt2++;}
            else if(x%2==1 and idx%2==0)
                {if(c!=v[kk][x][y])cnt2++;}
            else if(x%2==1 and idx%2==1)
                {if(c==v[kk][x][y])cnt2++;}
                idx++;
        }
    }





    return min(cnt,cnt2);
}

int32_t main()
{
    Fast();
    int n;
    cin>>n;
    vector<vector<string>>v(4,vector<string>(n));
    for(int k=0;k<4;++k)
    {
        for(int i=0;i<n;++i)
        {
            cin>>v[k][i];
        }
    }
    int ans=INT_MAX;
    vector<int>p={0,1,2,3};
    do
    {
        vector<vector<string>>vv(4);
        for(int i=0;i<4;++i)
        {
            vv[i]=(v[ p[i] ]);
        }
        int ret=help(vv);
        ans=min(ans,ret);
    }while(next_permutation(all(p)));
    cout<<ans<<endl;











}
