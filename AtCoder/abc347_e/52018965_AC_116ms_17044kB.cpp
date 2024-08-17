#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    long long n,q;
    cin>>n>>q;

    map<long long,long long>mp;
    long long size_so_far=0;
    vector<long long>ans(n,0);

    long long sz=0;
    while(q--) {
        long long xi;
        cin>>xi;

        if(mp[xi]) {
            // you now need to remove it
            ans[xi-1]+=size_so_far;
            mp[xi]--;
            sz--;

            size_so_far+=sz;
        } else {

            ans[xi-1]-=size_so_far;

            mp[xi]++;
            sz++;
            size_so_far+=sz;
        }
//        cout<<size_so_far<<endl;
    }
    for(auto&it:mp)ans[it.first-1]+=size_so_far*(it.second);

    for(auto&it:ans)cout<<it<<" ";
    cout<<endl;







}
