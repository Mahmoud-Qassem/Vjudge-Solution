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

    ll n;
    cin>>n;
    ll sum=1;
    vector<ll>v(n);
    for(auto&it:v)cin>>it;
    sort(all(v));

    for(ll i=0;i<n;++i){
        if(sum<v[i]){
            cout<<sum<<endl;
            return 0;
        }
        sum+=v[i];
    }
    cout<<sum;


}
