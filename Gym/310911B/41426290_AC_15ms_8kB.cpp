#include <bits/stdc++.h>
using namespace std;
bool valid(vector<int>v,int n)
{
    for(int i=0;i<n;++i)
      {
        for(int j=i+1;j<n;++j)
        {
            for(int k=j+1;k<n;++k)
            {
                if((v[i]^v[j]^v[k])==0)
                {
                    return 1;
                }
            }

        }

      }
      return 0;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(nullptr), cout.tie(nullptr);
      int n;
      cin>>n;
      vector<int>v(n);
      for(auto&it:v)cin>>it;
      int XO=0;
      if(valid(v,n))cout<<"YES"<<endl;
      else cout<<"NO"<<endl;






}
