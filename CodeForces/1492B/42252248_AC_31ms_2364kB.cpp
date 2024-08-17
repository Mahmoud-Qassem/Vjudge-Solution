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
        int n;
        cin>>n;
        vector<int>v(n);
        for(auto&it:v)cin>>it;

        vector<int>mx(n);
        int maxi=v[0];
        for(int i=0;i<n;++i)
            maxi=max(maxi,v[i]),mx[i]=maxi;

        vector<int>tmp,ans;
        for(int i=n-1;i>=0;--i)
        {
            if(mx[i]==v[i])
            {
                tmp.push_back(v[i]);
                reverse(all(tmp));
                for(auto&it:tmp)ans.push_back(it);
                tmp.clear();
            }
            else tmp.push_back(v[i]);
        }
        for(auto&it:ans)cout<<it<<" ";cout<<endl;

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
