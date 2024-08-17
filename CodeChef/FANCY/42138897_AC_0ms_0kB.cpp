// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define T int t;cin>>t;while(t--)

long long help(long long x)
{
    long long cnt = 0;
    while (x >= 5)
    {
        cnt += x / 5;
        x /= 5;
    }
    return cnt;
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    for(int x=0; x<t; ++x)
    {

        string s,tmp;
        if(!x)
        cin.ignore();

        getline(cin,s);
//        cout<<s<<endl;
        int n=s.size(),valid=0;
        s+=' ';
        for(int i=0; i<=n; ++i)
        {
            if(s[i]==' ')
            {
                if(tmp=="not")valid=1;
                tmp="";
                continue;
            }
            tmp+=s[i];
        }
        if(valid)cout<<"Real Fancy"<<endl;
        else cout<<"regularly fancy"<<endl;

    }


}
