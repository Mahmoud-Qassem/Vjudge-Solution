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

bool clc(int x) {
    int lst=x%10;
    x/=10;
    while(x) {
        if(x%10==lst)return 0;
        lst=x%10;
        x/=10;
    }
    return 1;

}
int32_t main() {
    FastFile();

    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    const ll MAX=10001;
    vector<ll>frq(MAX);
    set<ll>s;
    for(auto&it:v)cin>>it,frq[it]++,s.insert(it);

    auto dist=[&](ll x,ll y) {
        ll cnt=0;
        bitset<14>a(x),b(y);
        for(ll i=0; i<14; ++i) {
            cnt+=(a[i]!=b[i]);
        }
        return cnt;
    };
    ll cnt=0;
    if(k) {
        for(auto&it:s) {
            for(ll i=0; i<MAX; ++i) {
                ll tmp=dist(it,i);
                if(tmp==k) {
                    cnt+=frq[i]*frq[it];
                    if(it==i and frq[i])cnt--;
                }
            }
        }
        cout<<cnt/2<<endl;
    } else {
        for(ll i=0; i<MAX; ++i) {
            cnt+=(frq[i]*(frq[i]-1))/2;
        }
        cout<<cnt<<endl;
    }




//    ll n,cnt=0;
//    cin>>n;
//    for(ll i=0;i<=n;++i){
//        cnt+=(clc(i));
//        ll x=i+1;
//        ll u=i;
//
//        x-= (u/10);
//        if(u-(u/10)*10 < (u/10) )x+=(u/10);
//
////        x-= (u/100)*9;
////        x-= (u/1000)*90;
//
//        cout<<i<<" "<<cnt<<" "<<x<<endl;
//    }


}
