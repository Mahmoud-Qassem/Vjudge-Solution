#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,x,cnt=0;
    cin>>n;
    vector<int>v(n),tmp;
    
    map<int,int>mp;
    for(auto&it:v)cin>>it,mp[it]++;
    bool valid=1;

    while(valid)
    {
        valid=0;
        for(auto&it:mp)
        {
            // if second then second-- and push the first
            if(it.second)
            {
                it.second--;
                tmp.push_back(it.first);
                if(it.second)valid=1;
            }
//            if(mp[i])tmp.push_back(i),mp[i]--;
//            if(mp[i])valid=1;
        }
    }

    for(int i=0; i<tmp.size()-1; ++i)
    {
        cnt+=(tmp[i]<tmp[i+1]);
    }
    cout<<cnt<<endl;











}
