#include<bits/stdc++.h>
using namespace std;
typedef long long int  ll;
#define T  int tests; cin >> tests;while (tests--)
#define vi vector<int>
#define vl vector<ll>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) v.size()
#define filll(c,n,k)  cout<<setfill(c)<<setw(n)<<k;
#define pb push_back
#define vii vector<vector<int>>
#define fast  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define mod 1000000007
///*  cout << fixed << setprecision(7);
int ans=0;
int last=0;
void dfs(vii &v,vi&visit,int node ,int cnt)
{
    visit[node]++;
    for(auto it:v[node])
    {
        if(!visit[it])
        {
            cnt++;
            if(cnt>=ans)
            last=it;
            ans=max(ans,cnt);
            dfs(v,visit,it,cnt);
            cnt--;
        }
    }
}



int main()
{
    fast
    int n;
    cin>>n;
    vii v(n);
    for(int i=0;i<n-1;++i)
    {
        int from,to;
        cin>>from>>to;
        v[from-1].push_back(to-1);
        v[to-1].push_back(from-1);
    }
    int cnt=0;
    vi visit(n);
    dfs(v,visit,0,cnt);
    cnt=0;
    visit=vi(n,0);
    dfs(v,visit,last,cnt);
    cout<<ans<<endl;







}
