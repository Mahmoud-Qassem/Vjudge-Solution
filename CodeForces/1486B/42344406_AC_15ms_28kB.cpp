// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define sz(v) (int(v.size()))
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define yes(valid) if(valid)cout<<"YES"<<endl;else cout<<"NO"<<endl;
#define printv for(auto&it:v)cout<<it<<" ";cout<<endl;

struct DSU
{
    int leaders,Max;
    vector<int>parent, GroupSize;
    DSU(int n):leaders(n),Max(1)
    {
        parent = GroupSize = vector<int>(n+1);
        for(int i=0; i<=n; i++)
        {
            parent[i]=i;
            GroupSize[i]=1;
        }
    }
    int FindLeader(int i)
    {
        if(parent[i]==i)return i;
        return parent[i] = FindLeader(parent[i]);
    }
    bool sameGroup(int x,int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        return leader1 == leader2;
    }
    bool  MergeGroups(int x,int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)return 0;
        leaders--;
//        if(GroupSize[leader1]>GroupSize[leader2])
//        {
//            parent[leader2] = leader1;
//            GroupSize[leader1]+=GroupSize[leader2];
//            Max= max(Max,GroupSize[leader1]);
//        }
//        else
//        {
            parent[leader1] = leader2;
            GroupSize[leader2]+= GroupSize[leader1];
            Max= max(Max,GroupSize[leader2]);
//        }
        return 1;
    }

    int size(int x)
    {
        int leader = FindLeader(x);
        return GroupSize[leader];
    }

};
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t;
    cin>>t;
    for(int tt=1;tt<=t;++tt)
    {
        int n;
    cin>>n;
    vector<int>x,y,vx,vy;
    while(n--){
        int xx,yy;
        cin>>xx>>yy;
        x.push_back(xx);
        y.push_back(yy);
    }
    sort(all(x));
    sort(all(y));
    ll mn=1e18;
    for(int i=0;i<sz(x);i++){
        ll ans=0;
        for(int j=0;j<sz(x);j++){
            ans+=abs(x[i]-x[j]);
        }
        mn=min(mn,ans);
    }
    for(int i=0;i<sz(x);i++){
        ll ans=0;
        for(int j=0;j<sz(x);j++){
            ans+=abs(x[i]-x[j]);
        }
        if(ans==mn){
            vx.push_back(x[i]);
        }
    }
    mn=1e18;
    for(int i=0;i<sz(y);i++){
        ll ans=0;
        for(int j=0;j<sz(y);j++){
            ans+=abs(y[i]-y[j]);
        }
        mn=min(mn,ans);
    }
    for(int i=0;i<sz(y);i++){
        ll ans=0;
        for(int j=0;j<sz(y);j++){
            ans+=abs(y[i]-y[j]);
        }
        if(ans==mn){
            vy.push_back(y[i]);
        }
    }
    ll ansx=vx.back()-vx[0]+1;
    ll ansy=vy.back()-vy[0]+1;
    cout<<ansx*ansy<<endl;
    }

}
















