#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int base,goal,n,idx=1;
    while(cin>>base>>goal>>n)
    {
        if(not (base|goal|n))break;
        cout<<"Case "<<idx<<": ";
        vector<int>choices(n);
        for(auto&it:choices)cin>>it;
        vector<bool>visited(1e5+5);

        queue<int>q;
        q.push(base);
        visited[base]=true;
        int ans=-1;
        for(int level=0,sz=q.size(); sz; sz=q.size(),level++)
        {
            while(sz--)
            {
                int cur=q.front();
                q.pop();
                if(cur==goal)
                {
                    ans=level;
                    break;
                }
                // iterate over all choices
                for(int i=0; i<n; ++i)
                {
                    int tmp=(choices[i]+cur);
                    tmp%=10000;
//                cout<<tmp<<endl;
                    if(not visited[tmp])
                    {
                        q.push(tmp);
                        visited[tmp]=true;
                    }
                }
            }
        }
        if(ans==-1)cout<<"Permanently Locked"<<endl;
        else
        cout<<ans<<endl;
        idx++;
    }




















}