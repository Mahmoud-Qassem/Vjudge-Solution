#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
typedef unsigned long long int  ull;
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
#define OO 1e12
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
    freopen("testCase_input.txt", "r", stdin);
//    freopen("testCase_actualOutput.txt", "w", stdout);

}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
int n;
bool valid(int mid,int a,int b)
{
    for(int i=0; i<n; ++i)
    {
        if(a)
        {
            if(a >= 2*mid)
                a-=mid;
            else
                a=0;
        }
        else if(b)
        {
            if(b>=2*mid)
                b-=mid;
            else
                b=0;

        }
        else return 0;
    }
    return 1;
}
int32_t main()
{
    Fast();
    int t;
    cin>>t;
    for(int j=0;j<t;++j)
    {
        int n;
        cin>>n;
        vector<vector<int>>adg(n);
        vector<pair<int,int>>ans;
        for(int i=0;i<n;++i)
        {
            int nep,cnt=0;
            while(cin>>nep)
            {
                cnt++;
                char c;
                cin.get(c);
                if(c==10)break;
            }
            ans.push_back({cnt,i+1});
        }
        sort(all(ans));
        int i=1,mn=ans[0].first;
        cout<<ans[0].second;
        while(ans[i].first==mn)cout<<" "<<ans[i++].second;
        cout<<endl;



    }







}





