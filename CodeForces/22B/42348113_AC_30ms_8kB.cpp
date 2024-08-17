// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int(v.size()))
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define yes(valid) if(valid)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define printv for(auto&it:v)cout<<it<<" ";cout<<endl;
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<bool>>v(n,vector<bool>(m));
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            char c;
            cin>>c;
            if(c=='1')
                v[i][j]=1;
            else
                v[i][j]=0;
        }
    }
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        for(int ii=i; ii<n; ++ii)
        {
            for(int j=0; j<m; ++j)
            {
                for(int jj=j; jj<m; ++jj)
                {
                    int x=jj-j+1,y=ii-i+1;
                    int mult=x*y;
                    for(int xx=i; xx<=ii; ++xx)
                    {
                        for(int yy=j; yy<=jj; ++yy)
                        {
                            mult-=v[xx][yy];
                        }
                    }

                    if(x*y==mult)
                    {

                        ans=max(ans,2*x+2*y);
                    }
                }
            }
        }
    }
    cout<<ans<<endl;















}
















