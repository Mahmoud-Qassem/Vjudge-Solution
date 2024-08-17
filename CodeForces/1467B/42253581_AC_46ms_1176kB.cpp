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
        for(auto&it:v)cin>>it;
        if(n<3){cout<<0<<endl;continue;}


        int cnt=0;
        for(int i=1;i<n-1;++i)
        {
            if(v[i]>v[i-1] and v[i]>v[i+1])cnt++;
            else if(v[i]<v[i-1] and v[i]<v[i+1])cnt++;
        }
//        cout<<cnt<<endl;

        int mn=cnt;
        for(int i=1;i<n-1;++i)
        {
            int before=calc(i-2,i+2);
            int tp=v[i];
//            cout<<before<<endl;
//            for(auto&it:v)cout<<it<<" ";cout<<endl;
//            cout<<endl;


            v[i]=v[i-1];
            int after=calc(i-2,i+2);
//            cout<<after<<endl;
//            for(auto&it:v)cout<<it<<" ";cout<<endl;
//            cout<<endl;

            if(after<before)
            mn=min(mn,cnt-(before-after));

            v[i]=v[i+1];
            after=calc(i-2,i+2);
//            cout<<after<<endl;
//            for(auto&it:v)cout<<it<<" ";cout<<endl;
//            cout<<endl;

            if(after<before)
            mn=min(mn,cnt-(before-after));

            v[i]=tp;
        }
//        mn=max(0,mn);
        cout<<mn<<endl;

    }






}
