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
        vector<int>v(n),tmp;
        for(auto&it:v)cin>>it;
        tmp=v;
        sort(all(tmp));
        vector<int>odd(100009);
        vector<int>even(100009);
        for(int i=0;i<n;++i)
        {
            if((i+1)&1)
            odd[v[i]]++;
            else
            even[v[i]]++;
        }

        bool valid=1;
        for(int i=0;i<n;++i)
        {
            int e=tmp[i];
            if((i+1)&1 and not odd[e])valid=0;
            else if((i+1)&1)
                odd[e]--;
            else if((i+1)%2==0 and not even[e])valid=0;
            else if((i+1)%2==0)
                even[e]--;

        }
        if(valid)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;











    }

}
