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
    int n;
    cin>>n;
    n*=2;
    vector<int>v(n),tmp;
    for(auto&it:v)cin>>it;
    sort(all(v));
    tmp=v;
    int ans=INT_MAX;
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
        {
            int tp=0;
            v=tmp;
            for(int k=0;k<n;++k)
            {
                for(int x=0;x<n;++x)
                {
                    if(x!=k and v[x] and v[k] and x!=i and x!=j and k!=i and k!=j)
                    {
                        tp+=abs(v[x]-v[k]);
                        v[x]=0,v[k]=0;
                        break;
                    }
                }
            }
            ans=min(ans,tp);
        }
    }
    cout<<ans<<endl;
//    int ans=100000;
//    for(int mx=0; mx<=1000; ++mx)
//    {
//        v=tp;
//        vector<int>dif;
//
//        for(int i=0; i<n; ++i)
//        {
//            int mxidx=-1;
//            if(v[i]==10000)continue;
//            for(int j=i+1; j<n; ++j)
//            {
//                if(v[j]!=10000 and abs(v[j]-v[i])<=mx)
//                {
//                    mxidx=j;
//                    break;
//                }
//            }
//            if(mxidx!=-1)
//            {
//                dif.push_back(abs(v[mxidx]-v[i]));
//
//                cout<<v[i]<<" "<<v[mxidx]<<endl;
//                v[mxidx]=10000;
//            }
//        }
//        cout<<endl;
//        if(dif.size()>=n/2-1)
//        {
//            for(auto&it:dif)cout<<it<<" dif ";cout<<endl;
//            cout<<endl;
//
//            sort(all(dif));
//            int tmpsum=0;
//            for(int jk=0; jk<n/2-1; ++jk)
//                tmpsum+=dif[jk];
//
//            ans=min(tmpsum,ans);
//        }
//    }
//    cout<<ans<<endl;
//
//
//
//










}
