#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<int, null_type,less_or_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
typedef unsigned long long int  ull;
typedef long long int  ll;
#define num_len(n) floor(log10(n)) + 1;
#define T  int mahmoud; cin >> mahmoud;while (mahmoud--)
#define GO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define for1(a,b) for (int i = a; i < b; i++)
#define for2(a,b) for (int j = a; j < b; j++)
#define nf(b) for (int i = b - 1; i >= 0; i--)
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define li list<int>
#define dqi deque<int>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) v.size()
#define NO  cout<<"NO";
#define F  first
#define S  second
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define huge  LONG_LONG_MAX
#define mhuge LONG_LONG_MIN
#define big  INT_MAX
#define mbig INT_MIN
#define pb push_back
#define skip continue;
#define pf push_front
#define mod 1000000007
#define vii vector<vector<int>>
#define vbb vector<vector<bool>>
///*  cout << fixed << setprecision(7);
///*  work smart not hard  :) E.MS
ll  gcd(ll  a, ll b)
{
    return (b == 0 ? abs(a) : gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}
ll fast_pow(int x,int pp)
{
    if(pp==1)return x;
    else if(!pp)return 1;
    ll tmp=fast_pow(x,pp/2);
    tmp*=tmp;
    if(pp&1)tmp*=x;
    return tmp;
}

ll fpow2(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n&1)res=res*x;
        x*=x;

        n/=2;
    }

    return res;
}

ll sum(ll x, ll n)
{
    if(!n)return 1;
    if(n==1) return x;
    ll ans = sum(x,n/2);
    ans+= ans * fpow2(x,n/2);
    if(n&1)ans+=fpow2(x,n);
    return ans;
}
deque<int>ans;
int n;
set<int>ss;
deque<int>last;
void dfs(vii&graph,vb&visit,int node)
{
    ans.push_back(node+1);
    ss.insert(node+1);
    if(ss.size()==n)
    {
        last=ans;
        return;
    }
    visit[node]=true;
    for(int i=0;i<sz(graph[node]);++i)
    {
        if(!visit[graph[node][i]])
        {
            dfs(graph,visit,graph[node][i]);
            ans.pop_back();
            ss.erase(ss.find(graph[node][i]+1));
            visit[ graph[node][i] ]=false;
        }
    }


}


int main()
{
    GO
    /* test your code before submit *****/
    cin>>n;
    vii v(n);
    map<int,vi>mp;
    for(int i=0;i<n;++i)
    {
        int from ,to;
        cin>>from>>to;
        mp[i+1].push_back(from);
        mp[i+1].push_back(to);
        v[from-1].pb(to-1);
        v[to-1].pb(from-1);
    }
    vb visit(n);
    dfs(v,visit,0);
    if( mp[last[n-1]][0]!=last[0] && mp[ last[n-1] ][0]!=last[1]  )
        reverse(all(last));
    for(int i=0;i<sz(last);++i)cout<<last[i]<<" ";cout<<endl;















}