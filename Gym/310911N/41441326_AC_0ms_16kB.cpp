#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int n,m,k;
    cin>>n>>m>>k;

    vector<int>frogs(m),hills(k);
    for(auto&frog:frogs)cin>>frog;
    for(auto&hill:hills)cin>>hill;

    int mn=1e9+12;
    map<int,vector<int>>mp;
    for(int i=0;i<m;++i)
    {
        int frog=frogs[i];
        int cnt=0;
        for( int j=0;j<k;++j)
        {
            if(hills[j]%frog==0)cnt++;
        }
        mp[cnt].push_back(i+1);
    }
    auto it =mp.begin();
    cout<<it->second.size()<<endl;
    for(auto&ic:it->second)cout<<ic<<" ";
    cout<<endl;



}
