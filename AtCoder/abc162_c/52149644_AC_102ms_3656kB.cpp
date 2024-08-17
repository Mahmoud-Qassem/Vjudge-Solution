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

char rec(int n,ll k){
    if(n==1)return '0';

    ll L=1LL<<(n-1);

    // K is in the first half
    if(k<=L/2){
        return rec(n-1,k);
    }
    // K is in the 2nd half
    else {
        return rec(n-1,k-L/2)=='0'?'1':'0';
    }
    return 'L';
    return 'O';
    return 'L';
}

int32_t main() {
    FastFile();
    int n;
    cin>>n;
    int g=0;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
                for(int k=1;k<=n;++k){
                    g+=__gcd(__gcd(i,j),k);
                }
        }
    }
    cout<<g<<endl;



}
