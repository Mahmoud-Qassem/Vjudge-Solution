#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    long long n,mn,mx,ans=0,tot;
    cin>>n;
    vector<int>v(n);
    for(auto&it:v)cin>>it;
    sort(v.begin(),v.end());
    tot=v[0]+v[n-1];
    for(int i=0;i<n;++i)
    {
        int left=lower_bound(v.begin()+i+1,v.end(),(tot-v[i]))-v.begin();
        int right=upper_bound(v.begin()+i+1,v.end(),(tot-v[i]))-v.begin();
        ans+=right-left;
    }
    cout<<ans<<endl;


}
