#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
long long n,k;
vector<long long>v;
bool valid(long long mid)
{
    priority_queue<long long, vector<long long>, greater<long long>>q;

    long long idx=0;
    long long cc=0;
    while(idx<k)q.push(v[idx++]);

    while(q.size() and mid>=q.top())
    {
        mid+=q.top();
        q.pop();cc++;
        if(idx<n)
        q.push(v[idx++]);
    }
//    cout<<endl;
    return (cc==n);
}
int  main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    long long t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        v=vector<long long>(n);
        for(auto&it:v)cin>>it;

        long long l=0,r=1e9+5,mid,ans=0;
        while(l<=r)
        {
            mid=l+(r-l)/2;
            bool vv=valid(mid);
//            cout<<vv<<endl;
            if(vv)
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
