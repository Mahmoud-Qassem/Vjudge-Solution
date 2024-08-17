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

//    ios_base::sync_with_stdio(false);
//    cin.tie(nullptr), cout.tie(nullptr);
    int n;
    cin>>n;
    int l=1,r=n,mid,ans;
    while(l<=r)
    {
        mid=(l+r)/2;
        cout<<"? "<<mid<<endl;
        int md;
        cin>>md;
        int mdplus=1000000;
        if(mid+1<=n)
        {
            cout<<"? "<<mid+1<<endl;
            cin>>mdplus;

        }
        if(md<mdplus)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<"! "<<l<<endl;

}
















