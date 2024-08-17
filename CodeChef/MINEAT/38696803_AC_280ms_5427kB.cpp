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
#define sz(v) (int)v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define F first
#define S second
#define OO 1e7
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

//void ncubic(vector<vector<int>>&v)
//{
//    int n=sz(v);
//    for(int k=0; k<n; ++k)
//        for(int i=0; i<n; ++i)
//            for(int j=i+1; j<n; ++j)
//                v[i][j]=min(v[i][j],v[i][k]+v[k][j]),
//                        v[j][i]=min(v[j][i],v[j][k]+v[k][i]);
//}
ll help(vi v,ll mid)
{
    ll ans=0;
    for(int i=0;i<sz(v);++i)
    {
        ans+=ceil(v[i]*1.00/mid*1.00);
    }
    return ll(ans);
}

int32_t main()
{
    Fast();
    T
    {
        ll n,k;
        cin>>n>>k;
        vi v(n);
        for(auto&it:v)cin>>it;
        ll l=1,r=1e12,mid,ans;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(help(v,mid)>k)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
                ans=mid;
            }
        }
        cout<<ans<<endl;
    }





//        int n,k;
//        cin>>n>>k;
//        string s;
//        cin>>s;
//        int ans=0;
//        vector<bool>visited(n);
//        for(int i=0;i<k;++i)
//        {
//            int cnt=0;
//            vector<int>fr(26);
//            if(visited[i])continue;
//            for(int j=i;j<n;j+=k)
//            {
//                fr[s[j]-'a']++;
//                cout<<s[j]<<" ";
//                cnt++;
//            }
//            cout<<endl;
//            ans+=(cnt-*max_element(all(fr)));
//            int idx=max_element(all(fr))-fr.begin();
//            char c=char (idx+'a');
//            for(int j=i;j<n;j+=k)
//            {
//                if(s[j]!=c)s[j]=c;
//            }
//        }
//        cout<<s<<endl;
//        cout<<ans<<endl;
//










}
