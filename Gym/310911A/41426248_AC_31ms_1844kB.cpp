#include <bits/stdc++.h>
using namespace std;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr), cout.tie(nullptr);
      int n,x,cnt=0;
      cin>>n;
      vector<int>v(n),tmp,mp(1e5+5);
      for(auto&it:v)cin>>it,mp[it]++;

      bool valid=1;
      while(valid){
            valid=0;
        for(int i=0;i<1e5+1;++i){
            if(mp[i])tmp.push_back(i),mp[i]--;
            if(mp[i])valid=1;
        }
      }

      for(int i=0;i<n-1;++i)
      {
          cnt+=(tmp[i]<tmp[i+1]);
      }
      cout<<cnt<<endl;











}
