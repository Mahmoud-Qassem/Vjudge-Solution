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
    int n;
    cin>>n;
    long long add=0;
    multiset<ll>s;
    for(int i=0; i<n; ++i) {
        int x;ll y;
        cin>>x;
        if(x==1) {
            cin>>y;
            s.insert(y-add);
        }
        else if(x==2){
            cin>>y;
            add+=y;
        }
        else {
            auto it=s.begin();
            cout<<*(it)+add<<endl;
            s.erase(it);
        }


    }



//    int n,cnt=0;
//    cin>>n;
//    for(int i=0;i<=n;++i){
//        cnt+=(clc(i));
//        int x=i+1;
//        int u=i;
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
