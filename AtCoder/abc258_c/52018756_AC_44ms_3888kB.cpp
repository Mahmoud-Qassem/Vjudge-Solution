#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()

int mod(int x,int n){
    return (x%n+n)%n;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;


    int start=0;
    while(q--){
        int  x,y;
        cin>>x>>y;
        if(x==2){
            // print
            int idx=start+y-1;

            idx=mod(idx,n);
            cout<<s[idx]<<endl;
        }
        else{
            // rotate
            start-=y;
            start=mod(start,n);
        }

    }





}
