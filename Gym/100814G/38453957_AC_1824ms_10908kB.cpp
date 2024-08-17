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
#define inverse_of_sum(n) (long long)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
bool valid(int x,int n)
{
    if(x<0||x>=n)return 0;
    return 1;
}


struct edge
{
    int wisd,cost,city;
    edge(int wisd,int cost,int city): wisd(wisd),cost(cost),city(city){}
    bool operator < (const edge&e)const{
        return cost>e.cost;
    }
};



int n,m,k;
vector<vector<edge>>adj;
int dijkstra(int mid)
{
    /////////////////////wis,cost,to

    priority_queue<pair<int,int>>q;
    vector<int>cost(n,OO);
    vector<int>pro(n);
    // you should minimize on wisdom and check the cost on your way

    q.push({0,0});
    cost[0]=0;
    bool reached=0;
    while(sz(q))
    {
        pair<int,int>cur =q.top();
        q.pop();

        int cur_city  = cur.S;;
        int cur_cost  = -cur.F;

        if(pro[cur_city])continue;
        if(cur_city==n-1){reached=1;break;}
        pro[cur_city]=1;
        for(auto&child:adj[cur_city])
        {
            //     wisd              cost           city
            int x=child.wisd,y=child.cost,z=child.city;

            if( ( (cur_cost+y) <k)  && x <= mid  )
            {
                cost[z]=min(cost[z],(cur_cost+y));
                q.push({ -(cur_cost+y),z });
            }
        }
    }
    if(!reached)return 0;
    return 1;

}

int main()
{
    cyan
    T
    {
        cin>>n>>m>>k;
        adj=vector<vector<edge>>(n);
        for(int i=0;i<m;++i)
        {
            int from,to,wisd,cost;
            cin>>from>>to>>cost>>wisd;
            from--,to--;
            adj[from].push_back(edge(wisd,cost,to));
            adj[to].push_back(edge(wisd,cost,from));
        }
        ll l=0,r=1e9,ans=-1,mid;
        while(l<=r)
        {
//            here
            mid=l+(r-l)/2;
            if(dijkstra(mid))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }

        }
        cout<<ans<<endl;



    }




}
