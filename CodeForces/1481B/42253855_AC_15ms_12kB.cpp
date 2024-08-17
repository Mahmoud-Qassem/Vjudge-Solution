// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define yes(valid) if(valid)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define printv for(auto&it:v)cout<<it<<" ";cout<<endl;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(auto&it:v)cin>>it;
        int ans,cnt=0;
        while(true)
        {
            int idx=-1;
            for(int i=0;i<n-1;++i)
            {
                if(v[i]<v[i+1])
                {
                    v[i]++;
                    cnt++;
                    idx=i+1;
                    break;
                }
            }
            if(cnt==k or idx==-1)
            {
                ans=idx;
                break;
            }
        }
        cout<<ans<<endl;

    }






}
