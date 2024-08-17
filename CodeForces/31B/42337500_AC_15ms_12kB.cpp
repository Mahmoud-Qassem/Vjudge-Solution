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
    string s,tmp;
    cin>>s;
    vector<string>ans;
    bool valid=1;
    int n=s.size();
    if(s[0]=='@' or s[n-1]=='@')valid=0;
    int cnt=count(all(s),'@'),c=0;
    if(cnt==0)valid=0;
    for(int i=0; i<n and valid; ++i)
    {
        if(s[i]=='@')
        {
            c++;
            tmp+=s[i];
            if(tmp[0]=='@')valid=0;
            if(cnt==c)continue;
            tmp+=s[i+1];
            if(tmp.back()=='@')valid=0;
            ans.push_back(tmp);
            tmp="";
            i++;
        }
        else
            tmp+=s[i];
    }
    ans.push_back(tmp);
    if(valid)
    {

        int nn=ans.size();
        for(int i=0; i<nn; ++i)
        {
            cout<<ans[i];
            if(i!=nn-1)cout<<",";
        }
        cout<<endl;
    }
    else cout<<"No solution"<<endl;















}
