// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define yes(valid) if(valid)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define printv for(auto&it:v)cout<<it<<" ";cout<<endl;

int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        string s;
        cin>>s;
        int L=0,R=0,U=0,D=0;
        for(auto&it:s)
        {
            if(it=='L')L++;
            if(it=='R')R++;
            if(it=='D')D++;
            if(it=='U')U++;
        }
        if(x<0)
        {
            //LD
            if(y<0)
            {
                if(L>=abs(x) and D>=abs(y))cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
            // LU
            else
            {
                if(L>=abs(x) and U>=abs(y))cout<<"YES"<<endl;
                else cout<<"NO"<<endl;

            }
        }
        else
        {
            //RD
            if(y<0)
            {
                if(R>=abs(x) and D>=abs(y))cout<<"YES"<<endl;
                else cout<<"NO"<<endl;

            }
            // RU
            else
            {

                if(R>=abs(x) and U>=abs(y))cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

    }






}
