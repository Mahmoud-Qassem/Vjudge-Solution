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

    int n;
    cin>>n;
    vector<int>v(n);
    int left=1,right=n,idx=0,turn=1;
    while(left<=right)
    {
        if(turn)
        v[idx++]=left++;
        else
        v[idx++]=right--;
        turn =!turn;
    }
//    for(auto&it:v)cout<<it<<" ";cout<<endl;
            int ans=0,md=n+1;
        for(int i=0;i<n-1;++i)
        {
            ans+=(v[i]+v[i+1])%md;
        }
     cout<<ans<<endl;








}
