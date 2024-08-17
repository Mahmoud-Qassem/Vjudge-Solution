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
    int a,b;
    cin>>a>>b;
    if(a==b-1 or (a==10 and b==1) or (a==1 and b==10) or b==a-1)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;



}
