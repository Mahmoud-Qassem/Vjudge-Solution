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
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
}
void Fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<1e9 && y<1e9 ;
}
vi dx= {0,0,1,-1,1,1,-1,-1};
vi dy= {1,-1,0,0,1,-1,1,-1};
int main()
{
    Fast();
//    File();


    int n;
//    cin>>n;
    while(cin>>n)
    {
        cout<<"-----"<<endl;
        string s,ss="";
        vector<vector<int>>v(n);
        for(int i=0; i<n; ++i)
        {
            cin>>s;
            s+=',';
            vector<int>tmp;
            bool haha=0;
            for(int j=0; j<sz(s); ++j)
            {
                if(s[j]==','||s[j]=='-')
                {
                    if(not haha)
                    {
                        haha=1;
                        ss.clear();
                        continue;
                    }
                    if(ss.empty())continue;
                    int x=(stoi(ss));
                    x--;
                    v[i].push_back(x);
                    ss.clear();
                }
                else
                    ss+=s[j];
            }
        }
        int q;
        cin>>q;
        for(int i=0; i<q; ++i)
        {
            int source,dist;
            unordered_map<int,bool>visited;
            cin>>source>>dist;
            source--,dist--;
            vector<int>tmp,ans;
            ans.push_back(source);
            queue<vector<int>>q;
            q.push(ans);
            bool connected=0;
            while(sz(q))
            {
                tmp=q.front();
                q.pop();
                if(tmp.back()==dist)
                {
                    connected=1;
                    cout<<tmp[0]+1;
                    for(int i=1;i<sz(tmp);++i)
                    {
                        cout<<" "<<tmp[i]+1;
                    }
                    cout<<endl;
                }
                visited[tmp.back()]=1;
                for(auto&it:v[tmp.back()])
                {
                    if(not visited[it])
                    {
                        visited[it]=1;
                        tmp.push_back(it);
                        q.push(tmp);
                        tmp.pop_back();
                    }
                }
            }
            if(not connected)cout<<"connection impossible"<<endl;





        }



    }










}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
