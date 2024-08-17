#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
#define T int t;cin>>t;while(t--)
void FastFile() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
//    freopen("input.txt", "r", stdin);
//    freopen("OOO.txt", "w", stdout);
}

int32_t main() {
    FastFile();
    int t=1;
//    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        string s;
        cin>>s;

        vector<vector<ll>>v(3);
        for(ll i=0; i<n; ++i) {
            if(s[i]=='R')v[0].push_back(i+1);
            else if(s[i]=='G')v[1].push_back(i+1);
            else v[2].push_back(i+1);
        }

        ll ans=0;
        for(ll i=0; i<v[0].size(); ++i) {
            for(ll j=0; j<v[1].size(); ++j) {
                ll mn=min(v[0][i],v[1][j]);
                ll mx=max(v[0][i],v[1][j]);
                ll diff=mx-mn;
                ans+=v[2].size();
                ll a=0,b,c;

                set<int>f;
                b=diff+mx;
                f.insert(b);
                c=mn-diff;
                f.insert(c);



                if(diff%2==0) {
                    a=mn+diff/2;
                    f.insert(a);

                    for(auto&it:f) {
                        auto r = equal_range(all(v[2]), it);
                        ans-=(r.second-r.first) ;
                    }
                } else {
                    for(auto&it:f) {
                        auto r = equal_range(all(v[2]), it);
                        ans-=(r.second-r.first) ;
                    }
                }



            }
        }
        cout<<ans<<endl;


    }





}
