#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
#define INF 0x3F3F3F3F

const int MAX=1e4+5;
vector<pair<int,int>>adj[MAX];
int n,m,dis[MAX];
string s;
int dijkstra(int s,int e)
{
	for(int i=0;i<=n;++i)dis[i]=INF;
    priority_queue<pair<int,int>>q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty())
    {
        int cur=q.top().second;
        int curNodeCost=-q.top().first;
        q.pop();
		if(cur==e)break;
        if(curNodeCost>dis[cur])continue;
        for(auto ne:adj[cur])
        {
            if(curNodeCost+ne.second<dis[ne.first])
            {
                // update the distance of that neighbor if better path was found
                dis[ne.first]=curNodeCost+ne.second;
                q.push({-dis[ne.first],ne.first});
            }
        }
    }
    return dis[e];
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        map<string,int>mp;
        cin>>n;
		for(int i=0;i<=n;++i)adj[i].clear();
        for(int i=0; i<n; ++i)
        {
            cin>>s;
            mp[s]=i;
            cin>>m;
            for(int j=0; j<m; ++j)
            {
                int to,cost;
                cin>>to>>cost;
                to--;
                adj[i].push_back({to,cost});
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            string s,e;
            cin>>s>>e;
            cout<<dijkstra(mp[s],mp[e])<<endl;
        }
    }
}