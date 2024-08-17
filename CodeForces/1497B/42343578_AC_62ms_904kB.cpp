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
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        vector<int>mp(1e5+9);
        for(auto&it:v)cin>>it,it%=k,mp[it]++;
        int ans=n;
//        for(auto&it:v)cout<<it<<" ";cout<<endl;
        for(int i=0;i<n;++i)
        {
            int rem=k-v[i];
            if(rem==0 or rem==k)
            {
                if(mp[0])
                ans++;

                ans-=mp[0];
                mp[0]=0;
            }
            else if(not mp[rem]);
            else if(rem==v[i])
            {
                if(mp[rem])
                ans++;
                ans-=mp[rem];
                mp[rem]=0;
            }
            else
            {
                int mn=min(mp[v[i]],mp[rem]);
                int mx=max(mp[v[i]],mp[rem]);
                int tmp=min(mx,mn+1);
                if(mp[v[i]]==mn)mp[v[i]]=0,mp[rem]-=tmp;
                else mp[rem]=0,mp[v[i]]-=tmp;

//                cout<<mn<<" mn tmp "<<tmp<<endl;
                ans-=(mn+tmp);
                ans++;
            }
//            cout<<v[i]<<" "<<ans<<endl;
        }
        cout<<ans<<endl;









    }

}
















