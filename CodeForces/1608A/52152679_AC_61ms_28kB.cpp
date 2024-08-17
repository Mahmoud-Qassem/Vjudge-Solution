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

char rec(int n,ll k) {
    if(n==1)return '0';

    ll L=1LL<<(n-1);

    // K is in the first half
    if(k<=L/2) {
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
int ans=0;
void calc(vector<int>v,int k) {
    int n=v.size();

    int left=0,right=0,sum=0,rem=k;
    while(left<n) {
        while(right<n and rem>=0) {
            bool br=0;
            if(v[right]>=0) {
                sum+=v[right];
                if(rem>=0)
                    ans=max(sum,ans);
            } else {
                int ab=abs(v[right]);
                int mn=min(ab,rem);

                if(rem>=0) {
                    ans=max(ans,sum+mn);
                }

                sum+=ab;
                rem-=ab;

                if(rem>=0)
                    ans=max(sum,ans);

            }
//            cout<<left+1<<" "<<right+1<<" "<<ans<<endl;
            right++;

        }
//            cout<<left+1<<" "<<right+1<<" "<<ans<<endl;
        if(v[left]<0) {
            rem+=abs(v[left]);
            sum-=abs(v[left]);
        } else {
            sum-=v[left];
        }

        if(rem>=0)
            ans=max(sum,ans);
        left++;
    }
}
bool isprime(ll n)
{
    if(n==2)return 1;
    else if(n<2)return 0;
    else if(n==3)return 1;
    else if(n%2==0||n%3==0)return 0;
    for(int i=5; i<=sqrt(n); i+=6)
    {
        if(n%i==0||n%(i+2)==0)return 0;
    }
    return 1;
}
int32_t main() {
    FastFile();
    vector<int>v;

    int idx=1;
    while(v.size()<1001){
        if(isprime(idx)){
            v.push_back(idx);
        }
        idx++;
    }
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=0; i<n; ++i) {
                cout<<v[i]<<" ";
        }
        cout<<endl;
    }











}
