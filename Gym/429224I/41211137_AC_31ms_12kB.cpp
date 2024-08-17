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
//    freopen("testCase_input.txt", "r", stdin);
//    freopen("testCase_actualOutput.txt", "w", stdout);

}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool palind(int i)
{
    string s=to_string(i);
    for(int j=0; j<s.size(); ++j)
    {
        if(s[j]!=s[s.size()-j-1])return 0;
    }
    return 1;
}

int32_t main()
{
//    freopen("FileName.in", "r", stdin);
    Fast();
    int n,c=0;
    cin>>n;

    int yz7;
    int ans=0;

    for(int x=1;x<=n;x++)
    {
        yz7=n-3*x;
        if(yz7%7!=0)continue;

        int yz=yz7/7;
        for(int div=1;div*div<=yz;++div)
        {
            if(div*div==yz)ans++;
            else if(yz%div==0)ans+=2;
        }

    }
    cout<<ans<<endl;




//    int n;
//    cin>>n;
//    for(int i=n+1;; ++i)
//    {
//        if(palind(i))
//        {
//            cout<<i<<endl;
//            break;
//        }
//    }
//
//
//    string s=to_string(n);
//    int nn=s.size();
//    if(nn&1)
//    {
//        if( (s[nn/2])!='9' )
//        {
//            s[nn/2]++;
//            for(int i=0; i<nn/2; ++i)
//            {
//                s[nn-i-1]=s[i];
//            }
//        }
//        else
//        {
//            bool nine=0;
//            s[nn/2]='0';
//            for(int i=nn/2-1; i>=0; --i)
//            {
//                if(s[i]=='9' and s[nn-i-1]=='9')
//                    s[i]=s[nn-i-1]='0';
//                if(s[i]!=s[nn-i-1])
//                {
//                    s[i]=s[nn-i-1]=max(s[i],s[nn-i-1]);
//                    nine=1;
//                    break;
//                }
//            }
//            if(nine)
//            {
//                for(int i=0; i<nn/2; ++i)
//                {
//                    s[nn-i-1]=s[i];
//                }
//            }
//        }
//    }
//            cout<<s<<endl;
//
//
//
//
//
//

}






