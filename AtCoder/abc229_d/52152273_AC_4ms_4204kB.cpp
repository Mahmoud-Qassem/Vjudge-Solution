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
void calc(vector<int>v,int k){
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

                if(rem>=0){
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
int32_t main() {
    FastFile();
    string s;
    cin>>s;
    int k;
    cin>>k;
    vector<int>v;
    s+='K';
    int cnt=1,n=s.size();
    for(int i=1; i<n; ++i) {
        if(s[i]==s[i-1]) {
            cnt++;
        } else {
            if(s[i-1]=='X') {
                v.push_back(cnt);
            } else {
                v.push_back(-cnt);
            }
            cnt=1;
        }
    }


    calc(v,k);
    reverse(all(v));
    calc(v,k);

    cout<<ans<<endl;
//    for(auto&it:v)cout<<it<<" ";
//    cout<<endl;











}
