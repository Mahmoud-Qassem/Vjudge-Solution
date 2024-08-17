#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf 100000000000000LL
#define clr(v,value) memset(v,value,sizeof(v));
long long n;
vector<ll>v;
ll dp[444][444];
long long solve(long long i,long long j)
{
    if(i>=j)return 0;

    auto&ret=dp[i][j];
    if(~ret)return ret;
    ret=1e15;


    long long sumofthisrange=0;
    for(long long k=i; k<j; ++k)
    {
        sumofthisrange+=v[k];
        ret=min(ret,solve(i,k)+solve(k+1,j));
    }
    ret+=sumofthisrange+v[j];

    return ret;












}
int main()
{
    cin>>n;
    v=vector<ll>(n);
    for(auto&it:v)cin>>it;
    clr(dp,-1);
    cout<<solve(0,n-1)<<endl;



    // 0 1 2 3  4 5
    // 7 6 8 6  1 1
    // the rec is just a function that return the valid answer for some range i give to it
    // i just give it the start and the end of the range





}
// cost so far of (0 : 3) = 1 + 3 + 6 =10
// cost so far of (0 : 2) = 4







// cost so far of (0 : 3) = 4 + 5 + 9 = 18
// 9



// 0 1   2 3
// 1 2 3      16+12       9  2 6 3


//                         (0,3)
//                                            4         0
//  (0,0) + (1,3)+sumofthisrange    (0,1) + (2,3)+sumofthisrange      (0,2) + (3,3)+sumofthisrange






















