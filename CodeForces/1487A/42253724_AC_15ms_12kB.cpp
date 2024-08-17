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
int n;
vector<int>v;
int calc(int s,int e)
{
    s=max(s,0);
    e=min(e,n-1);
    int cnt=0;
    for(int i=s+1;i<e;++i)
    {
        if(v[i]>v[i-1] and v[i]>v[i+1])cnt++;
        else if(v[i]<v[i-1] and v[i]<v[i+1])cnt++;
    }
    return cnt;

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        v=vector<int>(n);
        int mn=101,ans=0;;

        for(auto&it:v)cin>>it,mn=min(mn,it);
        for(auto&it:v)ans+=(it>mn);
        cout<<ans<<endl;


    }






}
