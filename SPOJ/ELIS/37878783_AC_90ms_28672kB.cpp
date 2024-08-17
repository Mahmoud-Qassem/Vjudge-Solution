#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define here cout<<"here"<<endl;
#define pi 3.141592653589793
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO INT_MAX
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
int dp[2509][2509];
class Solution
{
public:
    int solve(vector<int>&w,int idx,int&n,int last_idx)
    {
        if(idx==n-1)
        {
            if(w[idx]>w[last_idx])return 1;
            else return 0;
        }
        auto &ret=dp[idx][last_idx];
        if(~ret)return ret;
        int leave_it=solve(w,idx+1,n,last_idx);
        int take_it=0;
        if(w[idx]>w[last_idx])
            take_it=1+solve(w,idx+1,n,idx);

        return ret=max(take_it,leave_it);
    }

    int lengthOfLIS(vector<int>& nums)
    {
        int n=nums.size();
        memset(dp,-1,sizeof(dp) );
        vector<int>v;
        v.push_back(-1e5);
        n++;
        for(auto&i:nums)v.push_back(i);
        return solve(v,1,n,0);
    }
};
int main()
{
    cyan
    int n ;
    cin>>n;
    vi v(n);
    for(auto&i:v)cin>>i;
    Solution sol;
    cout<<sol.lengthOfLIS(v);




















}
