#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(s) (s).begin(),(s).end()
#define allr(s) (s).rbegin(),(s).rend()
const int M=1e9+5;
//bool valid(int x,int y) {
//    return (x>=1 and y>=1 and x<=n and y<=m);
//}
int dx[]= {0,0,-1,1,1,1,-1,-1};
int dy[]= {1,-1,0,0,1,-1,-1,1};

int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto&it:v)cin>>it;
    int cnt=0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){

            if( (v[i]+v[j])%k==0 )cnt++;
        }
    }
    cout<<cnt<<endl;



}

