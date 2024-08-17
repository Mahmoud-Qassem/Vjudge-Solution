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
const int MAX=59;
int a[MAX]= {25,18,15,12,10,8,6,4,2,1},n,t;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    map<string,vector<int> > m;
    vector<pair<vector<int>,string> > ans;
    string s;
    cin>>t;
    while (t--)
    {
        cin>>n;
        for (int i=0; i<n; i++)
        {
            cin>>s;
            if (m.find(s)==m.end())
                m[s].resize(MAX);
            m[s][0]+=a[i],m[s][i+1]++;
        }
    }
    for (auto &v:m)
        ans.push_back({v.second,v.first});
    cout<<max_element(ans.begin(),ans.end())->second<<'\n';
    for (auto &v:ans)
        swap(v.first[0],v.first[1]);
    cout<<max_element(ans.begin(),ans.end())->second<<'\n';


}


















