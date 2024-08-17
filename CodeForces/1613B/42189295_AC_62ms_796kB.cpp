// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define T int t;cin>>t;while(t--)

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    T
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto&it:v)cin>>it;
        sort(all(v));
        int ans=n/2;
        for(int i=1;ans;++i)cout<<v[i]<<" "<<v[0]<<endl,ans--;


    }

}
