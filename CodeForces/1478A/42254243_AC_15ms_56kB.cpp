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
        int mx=0,n;
        cin>>n;
        vector<int>v(10000);
        for(int i=0;i<n;++i)
        {
            int c;
            cin>>c;
            v[c]++;
            mx=max(mx,v[c]);
        }
        cout<<mx<<endl;
        

    }






}
