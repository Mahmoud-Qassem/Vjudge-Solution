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
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
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
    unordered_map<string,int>prime;
    for(int i=1000;i<10000;++i)if(isprime(i))prime[to_string(i)]=1;
    T
    {
        int base ,goal;
        cin>>base>>goal;
        queue<int>q;
        q.push(base);
        int ans=-1;
        unordered_map<string,int>visited;
        visited[to_string(base)]=1;
        for(int level=0,sz=sz(q);sz;sz=sz(q),level++)
        {
            if(ans!=-1)break;
            while(sz--)
            {
                int cur=q.front();
                q.pop();
                if(cur==goal)
                {
                    ans=level;break;
                }
                string s=to_string(cur);
                for(int i=0;i<4;++i)
                {
                    string tmp=s;
                    for(char c='0';c<='9';++c)
                    {
                        tmp=s;
                        tmp[i]=c;
                        int num=stoi(tmp);
                        if(num>1000&&num<10000&&prime[tmp]&&not visited[tmp])
                        {
                            visited[tmp]=1;
                            q.push( num );
                        }
                    }
                }
            }
        }
        if(ans==-1)cout<<"Impossible\n";
        else cout<<ans<<endl;







    }







}// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
