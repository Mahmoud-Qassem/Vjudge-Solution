#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    ll n,d,x;
    cin>>n>>d>>x;

    vector<pair<ll,ll>>v(n);
    //                  X           H
    for(auto&it:v)cin>>it.first>>it.second;

    sort(all(v));

    ll bomb=0;
    vector<ll>prefHealth(n+5);

    for(ll i=0;i<n;++i){
        if(i)prefHealth[i]+=prefHealth[i-1];

        ll remainHealth=v[i].second-prefHealth[i];
//        cout<<remainHealth<<endl;

        if(remainHealth>0){
            ll neededbomb=( remainHealth+x-1 )/x;
            bomb+=neededbomb;
            ll minusHealth=neededbomb*x;

            // left effect of the current needed-bomb
            prefHealth[i]+=minusHealth;

            // right effect of the current needed-bomb
            pair<ll,ll>p={v[i].first+2*d,LONG_LONG_MAX};
            ll idx=upper_bound(all(v),p)-v.begin();

            if(idx<n)prefHealth[idx]-=minusHealth;

        }
//        for(auto&it:prefHealth)cout<<it<<" ";cout<<endl;


    }

    cout<<bomb<<endl;








}
