// just WORK for what you WANT
// et3ab shoyia thoghananeeeen
#include<bits/stdc++.h>
using namespace std;
//#define ll long long
#define ull unsigned long long
#define endl '\n'
#define mod 998244353
#define all(s) (s).begin(),(s).end()
#define T int tst;cin>>tst;while(tst--)
bool isdiv(string s,string ss)
{
    int n=s.size();
    int m=ss.size();
    int idx=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=ss[idx])return 0;
        idx++;
        idx%=m;
    }
    return 1;



}
const long long inf=1000000000000 ;


void floyd(vector<vector<long long>>&v)
{
    long long n=v.size();
    for(long long k=0;k<n;++k)
        for(long long i=0;i<n;++i)
            for(long long j=0;j<n;++j)
            v[i][j]=min(v[i][j],v[i][k]+v[k][j]);
}
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
//    T
    {
        string s,t;
        cin>>s>>t;
        long long sz=s.size();
        long long n;
        cin>>n;
        vector<vector<long long>>v(27,vector<long long>(27,100000));
        for(long long i=0;i<27;++i)v[i][i]=0;

        for(long long i=0;i<n;++i)
        {
            char from,to;long long cost;
            cin>>from>>to>>cost;
            long long ff=int(from-'a');
            long long tt=int(to-'a');
            v[ff][tt]=min(v[ff][tt],cost);
        }
        if(sz!=t.size())
        {
            return cout<<-1<<endl,0;
        }
        floyd(v);
        long long totCost=0;
        for(long long i=0;i<sz;++i)
        {
            long long a=s[i]-'a';
            long long b=t[i]-'a';
            if(a==b)continue;
            long long mn=INT_MAX;
            int last=0;
            for(int alp=0;alp<26;alp++)
            {
                int tmp=mn;
                mn=min(mn,v[a][alp]+v[b][alp]);
                if(tmp!=mn)last=alp;
            }
            if(mn>10000)continue;
            s[i]=t[i]=char(last+'a');
            totCost+=mn;
        }
        if(s!=t)return cout<<-1<<endl,0;
        cout<<totCost<<endl;
//        cout<<s<<endl;
        cout<<t<<endl;



    }



}
