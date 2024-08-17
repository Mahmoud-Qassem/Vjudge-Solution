#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int>v(n),smaller(n+2),bigger(n+2);
    for(auto&it:v)cin>>it;
    for(int i=0;i<n-1;++i)
    {
        smaller[i+1]=(v[i]<=v[i+1]);
        bigger[i+1]=(v[i]>=v[i+1]);
    }
    for(int i=1;i<=n;++i)
    {
        smaller[i]+=smaller[i-1];
        bigger[i]+=bigger[i-1];
    }
    // 9 1 2 3 4 5 6
//    for(auto&it:smaller)cout<<it<<" ";cout<<endl;
//    for(auto&it:bigger)cout<<it<<" ";cout<<endl;


    int l,r;
    while(q--)
    {
        cin>>l>>r;
        int small=smaller[r-1]-smaller[l-1];
//        cout<<small<<endl;
        if(small==r-l or not small)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }





}
