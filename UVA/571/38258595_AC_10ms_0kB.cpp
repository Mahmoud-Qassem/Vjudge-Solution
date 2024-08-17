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
#define get(v) for(auto&it:v)cin>>it;
#define vii vector<vector<int>>
#define cyan  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define inverse_of_sum(n) (double)( sqrt(2*n+0.25)-0.5  )
#define mod 1000000007
void File()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}
bool valid(int x,int y)
{
    return x>=0 && y>=0 && x<8 && y<8 ;
}
//vi dx= {0,0,1,-1,1,1,-1,-1};
//vi dy= {1,-1,0,0,1,-1,1,-1};

vector<int>visited;
vector<int>tmp;
vector<vector<int>>v;

void dfs(int node)
{
    visited[node]=1;
    for(auto&child:v[node])
    {
        if(visited[child] == 0)
            dfs(child);
    }
    tmp.push_back(node);
}
void dfs2(int node)
{
    visited[node]=2;
    for(auto&child:v[node])
        if(visited[child]==1)
            dfs2(child);
}
int main()
{
//    File();
    int a,b,n;
    while(cin>>a>>b>>n)
    {
        vector<string>ans;
        queue<pair<pair<int,int>,vector<string>>>q;
        q.push( {{0,0},ans} );
        map<  pair<int,int> , bool  >visited;
        while(q.size())
        {
            int aa=q.front().F.F;
            int bb=q.front().F.S;
            vector<string>v=q.front().S;
            // do not forget to pop from the queue
            q.pop();
            if(bb==n)
            {
                for(auto&it:v)cout<<it<<endl;
                cout<<"success"<<endl;
                break;
            }
            // you should ask your self a question
            // when can i execute the command
            //      empty a   empty b  , full a , full b,    pour a to b ,    pour b to a
            //      aa!=0      bb!=a     aa!=a     bb!=b       a&&bb!=b         b&&aa!=a

            // empty A
            if(aa!=0&&not visited[ {0,bb} ])
            {
                v.push_back("empty A");
                q.push({{0,bb},v});
                visited[ {0,bb}]=1;
                v.pop_back();
            }
            // empty B
            if(bb!=0&&not visited[ {aa,0} ])
            {
                v.push_back("empty B");
                q.push({{aa,0},v});
                visited[ {aa,0}]=1;
                v.pop_back();
            }
            // fill B
            if(bb!=b&&not visited[ {aa,b} ])
            {
                v.push_back("fill B");
                q.push({{aa,b},v});
                visited[ {aa,b}]=1;
                v.pop_back();
            }
            // fill A
            if(aa!=a&&not visited[ {a,bb} ])
            {
                v.push_back("fill A");
                q.push({{a,bb},v});
                visited[ {a,bb}]=1;
                v.pop_back();
            }
            // pour A B
            if(aa&&bb!=b)
            {
                int mn=min(aa,b-bb);
                int aaa=aa-mn;
                int bbb=bb+mn;
                if(not visited[ {aaa,bbb}])
                {
                    v.push_back("pour A B");
                    q.push({{aaa,bbb},v});
                    visited[ {aaa,bbb}]=1;
                    v.pop_back();
                }
            }


            // pour B A
            if(bb&&aa!=a)
            {
                int mn=min(bb,a-aa);
                int bbb=bb-mn;
                int aaa=aa+mn;
                if(not visited[ {aaa,bbb}])
                {
                    v.push_back("pour B A");
                    q.push({{aaa,bbb},v});
                    visited[ {aaa,bbb}]=1;
                    v.pop_back();
                }
            }

        }
    }

}
// compete against problem set not the others //ZEZO
// test test && verify ur idea don't make the judge test for you
// make sure that u use a logic rule not a habd rules
// simplify any equation before useing in the problem
