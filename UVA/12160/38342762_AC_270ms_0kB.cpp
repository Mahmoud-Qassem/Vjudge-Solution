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
#define OO INT_MAX
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif
}
int n,m,cnt;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
int t=1;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node,bool&cycle)
{
    visited[node]=t++;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child,cycle);
        }
        else
        {
            cout<<node+1<<" "<<child+1<<endl;
            if(t-visited[node]>1)cycle=1;
        }
    }
}
bool isprime(int n)
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
int main()
{
    File();
    int idx=1;
    string base,goal;
    while(cin>>base>>goal&&base!="0"&&goal!="0")
    {
        int buttons;
        cin>>buttons;
        vector<int>bb(buttons);
        for(auto&it:bb)cin>>it;
        queue<string>q;
        q.push(base);
        int ans=-1;
        unordered_map<string,int>visited;
        visited[base]=1;
        for(int level=0,sz=sz(q);sz;sz=sz(q),level++)
        {
            if(ans!=-1)break;
            while(sz--)
            {
                string cur=q.front();
                q.pop();
                if(cur==goal)
                {
                    ans=level;break;
                }
                for(int i=0;i<buttons;++i)
                {
                    int x=stoi(cur);
                    int tmp=bb[i]+x;
                    string s(4,'0');
                    for(int k=3;tmp&&k>=0;--k)
                    {
                        s[k]=char((tmp%10)+48);
                        tmp/=10;
                    }
                    if(not visited[s])
                    {
                        q.push(s);
                        visited[s]=1;
                    }
                }
            }
        }
        cout<<"Case "<<idx++<<": ";
        if(ans==-1)cout<<"Permanently Locked"<<endl;
        else cout<<ans<<endl;







    }







}

// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
