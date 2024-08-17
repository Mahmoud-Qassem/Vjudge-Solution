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
int n,k;
bool haveK(int x)
{
    while(x)
    {
        if(x%10==k)return 1;
        x/=10;
    }
    return 0;
}
bool valid(int x)
{
    int cnt=x/k;
    for(int i=0;i<min(100,cnt);++i)
    {
        if(haveK(x-(i*k)))return 1;
    }
    return 0;
}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0,x;i<n;++i)
        {
            cin>>x;
            if(haveK(x) or x%k==0 or valid(x))cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }


    }






}
