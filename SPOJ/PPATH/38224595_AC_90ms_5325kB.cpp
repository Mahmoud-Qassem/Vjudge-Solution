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
#define get(v) for(auto&it:v)cin>>it;
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
int n;
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<n && y<n ;
}
vi dx= {0,0,1,-1};
vi dy= {1,-1,0,0};
int cnt=0;
void dfs(vector<vector<int>>&v,vector<int>&visited,int node)
{
    visited[node]=1;
    cnt++;
    for(auto&child:v[node])
    {
        if(not visited[child])
        {
            dfs(v,visited,child);
        }
    }
}
bool isprime(ll n)
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
    map<string,bool>prime;
    for(int i=1000;i<10000;++i)if(isprime(i))prime[to_string(i)]=true;
    T
    {
        int n,m;
        cin>>n>>m;
        string nn,mm;
        mm=to_string(m);
        nn=to_string(n);
        queue<string>q;
        q.push(to_string(n));
        map<string,bool>visited;
        visited[to_string(n)]=true;
        int level=0;
        for(int sz=sz(q);sz;sz=sz(q),level++ )
        {
            bool done=0;
            while(sz--)
            {
                string cur=q.front();
                q.pop();
                if(cur==mm){done=1;break;}
                for(int i=0;i<4;++i)
                {
                    for(char digit='0';digit<='9';++digit)
                    {
                        string tmp=cur;
                        tmp[i]=digit;
                        if(prime[tmp]&&not visited[tmp])
                        {
                            visited[tmp]=true;
                            q.push(tmp);
                        }
                    }
                }
            }
            if(done)break;
        }
            cout<<level<<endl;







    }





}
