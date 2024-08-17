#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    vector<int>v(n);
    map<int,bool>mp;
    for(auto&it:v)cin>>it,mp[it]=1;
    sort(all(v));
    while(q--){
        int  x;
        cin>>x;
        if(mp[x])cout<<0<<endl;
        else {
            int idx=upper_bound(all(v),x)-v.begin();
            int left=idx,right=n-left;
            if(left&1)cout<<"NEGATIVE"<<endl;
            else cout<<"POSITIVE"<<endl;
        }

    }





}
