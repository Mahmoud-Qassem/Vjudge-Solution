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
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(auto&it:v)cin>>it;
        sort(all(v));

        auto valid=[&](int mid) {

            int cnt=0;
            int last=v[0];
            for(int i=1; i<n; ++i) {
                if( v[i]-last+1 > mid) {
                    last=v[i];
                    cnt++;
                }
            }

//            cout<<mid<<" "<<cnt<<endl;
            if( v[n-1]-last+1 <= mid)cnt++;
            else if( v[n-1]-last+1 > mid)cnt+=2;
//            cout<<mid<<" "<<cnt<<endl;
//            cout<<endl;
            return cnt<=k;

        };


        int ans=0,left=0,right=1e9+1;
        while(left<=right) {
            int mid=left+(right-left)/2;
            if(valid(mid)) {
                right=mid-1;
                ans=mid;
            } else {
                left=mid+1;
            }
        }
        cout<<ans<<endl;






    }





}
