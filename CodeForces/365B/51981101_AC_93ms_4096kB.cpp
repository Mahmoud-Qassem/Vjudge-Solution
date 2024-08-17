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
    long long n;
    cin>>n;
    vector<long long>v(n);
    for(auto&it:v)cin>>it;
    long long ans=0,cnt=0;
    for(long long i=2;i<n;++i){
        if(v[i]==(v[i-1]+v[i-2]))cnt++;
        else {
            cnt=0;
        }
        ans=max(ans,cnt);
    }
    cout<<min(ans+2,n)<<endl;






}

