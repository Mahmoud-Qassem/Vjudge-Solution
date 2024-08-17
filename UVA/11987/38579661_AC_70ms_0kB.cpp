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
#define OO 1e18
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool valid(ll x,ll y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
const int N=2e5+5;
struct DSU
{
    ll parent[N],SUM[N],GroupSize[N];
    void init(int n)
    {
        for(int i=1; i<=n; i++)
        {
            parent[i]=i+n;
            parent[i+n]=i+n;

            SUM[i]=i;
            SUM[i+n]=i;

            GroupSize[i]=0;
            GroupSize[i+n]=1;
        }
    }

    int FindLeader(int i)
    {
        if(parent[i]==i)return i;
        return parent[i] = FindLeader(parent[i]);
    }

    void  MergeGroups(int x,int y)
    {
        int leader1 = FindLeader(x);
        int leader2 = FindLeader(y);
        if(leader1 == leader2)return ;

        if(GroupSize[leader1]>GroupSize[leader2])
            swap(leader1,leader2);

        parent[leader1] = leader2;
        SUM[leader2]+=SUM[leader1];
        GroupSize[leader2]+= GroupSize[leader1];
    }

    void movee(int p,int q)
    {
        int leader1 = FindLeader(p);
        int leader2 = FindLeader(q);
        if(leader1 == leader2)return ;

        GroupSize[leader1]--;
        GroupSize[leader2]++;
        SUM[leader2]+=p;
        SUM[leader1]-=p;
        parent[p]=leader2;
    }

    void print(int x)
    {
        x=FindLeader(x);
        cout<<GroupSize[x]<<" "<<SUM[x]<<endl;
    }

}dsu;

int32_t main()
{
    Fast();
    File();
    int n,m;
    while(cin>>n>>m)
    {
        dsu.init(n);
        for(int i=0; i<m; ++i)
        {
            int op,x,y;
            cin>>op;
            if(op==1)
            {
                cin>>x>>y;
                dsu.MergeGroups(x,y);
            }
            else if(op==2)
            {
                cin>>x>>y;
                dsu.movee(x,y);
            }
            else
            {
                cin>>x;
                dsu.print(x);
            }
        }
    }
    return 0;
}
