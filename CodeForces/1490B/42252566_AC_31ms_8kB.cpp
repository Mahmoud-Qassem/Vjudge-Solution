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

void check(int&cnt,int mn,int mx)
{
    while(mn*2<mx)
    {
        mn*=2;
        cnt++;
    }

}

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int n,tmp;
        cin>>n;
        vector<int>v(3);
        for(int i=0; i<n; ++i)
        {
            cin>>tmp;
            v[tmp%3]++;
        }
        int mid=accumulate(all(v),0LL)/3;
        int ans=0;
        while(v[0]<mid&&v[1]>mid)
        {
            v[0]++;
            v[1]--;
            ans+=2;
        }
        while(v[2]<mid&&v[1]>mid)
        {
            v[2]++;
            v[1]--;
            ans++;
        }


        while(v[1]<mid&&v[0]>mid)
        {
            v[1]++;
            v[0]--;
            ans++;
        }
        while(v[2]<mid&&v[0]>mid)
        {
            v[2]++;
            v[0]--;
            ans+=2;
        }


        while(v[0]<mid&&v[2]>mid)
        {
            v[0]++;
            v[2]--;
            ans++;
        }
        while(v[1]<mid&&v[2]>mid)
        {
            v[1]++;
            v[2]--;
            ans+=2;
        }
        cout<<ans<<endl;



    }


//    int n=7,A=
//    for(int x1=0; x1<n; ++x1)
//    {
//        for(int y1=0; y1<n; ++y1)
//        {
//            for(int x2=0; x2<n; ++x2)
//            {
//                for(int y2=0; y2<n; ++y2)
//                {
//                    for(int x3=0; x3<n; ++x3)
//                    {
//                        for(int y3=0; y3<n; ++y3)
//                        {
//
//                        }
//                    }
//                }
//            }
//        }
//    }





}
