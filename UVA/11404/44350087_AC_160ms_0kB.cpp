#include <bits/stdc++.h>
using namespace std;
int n;
string s,ans;
const int MX=1011;
int visited[MX][MX];
int test;
int dp[MX][MX];
string dpp[MX][MX];
int solve(int i,int j)
{
    if(i>=j) return i==j ;

    int &ret=dp[i][j];
    if(~ret) return ret ;
    if(s[i]==s[j]) return ret=solve(i+1,j-1)+2;
    return ret=max(solve(i+1,j),solve(i,j-1));
}
string comp(string a,string b)
{
    if(a.size()>b.size())return a;
    if(a.size()<b.size())return b;
    return (a<b)?a:b;
}

string build(int i,int j)
{
    if(i==j)
    {
        return string(1,s[i]);
    }
    if(i>j)return "";


    auto&ret=dpp[i][j];
    if(visited[i][j]==test)return ret;

    visited[i][j]=test;


    int best=solve(i,j);

    string x,y,z;
    if(s[i]==s[j])
    {
        z=s[i]+build(i+1,j-1)+s[j];
    }
    int choice1=solve(i+1,j);
    int choice2=solve(i,j-1);
    if(choice1==best)
        x=build(i+1,j);

    if(choice2==best)
        y=build(i,j-1);

    return ret=comp(x,comp(y,z));

}
int main()
{

//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    while(cin>>s)
    {
        if(s.empty())break;
        test++;

//        cin>>s;
        memset(dp,-1,sizeof(dp));
        int mx=solve(0,s.size()-1);
        ans=build(0,s.size()-1);
        cout<<ans<<endl;
    }
    return 0;
}
