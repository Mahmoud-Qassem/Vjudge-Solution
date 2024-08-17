#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>v;
map<int,int>row;
void emptyBlock(int x)
{
    int xx=row[x];
    while(v[xx].size() and v[xx].back()!=x)
    {
        int c=v[xx].back();
        v[xx].pop_back();
        v[c].push_back(c);
        row[c]=c;
    }
}
void moveOnTo(int b,int a)
{
    int x=row[a];
    int y=row[b];
    if(x==y)return;
    emptyBlock(a);
    emptyBlock(b);
    v[y].pop_back();
    v[x].push_back(b);
    row[b]=x;
}
void moveOver(int a,int b)
{
    int x=row[a];
    int y=row[b];
    if(x==y)return;

    emptyBlock(a);

    v[x].pop_back();
    v[y].push_back(a);
    row[a]=y;
}
void pileOver(int a,int b)
{
    int x=row[a];
    int y=row[b];
    if(x==y)return;
    bool flag=0;
    vector<int>tmp;
    do
    {
        int c=v[x].back();
        if(c==a)flag=1;

        v[x].pop_back();
        tmp.push_back(c);
    }while(v[x].size() and flag==0);
    reverse(tmp.begin(),tmp.end());
    for(auto&c:tmp)
        v[y].push_back(c),row[c]=y;


}
void pileOnTo(int a,int b)
{
    emptyBlock(b);
    pileOver(a,b);
}


int32_t main ( )
{

    int n;
    cin>>n;
    v=vector<vector<int>>(n);
    string s;
    for(int i=0; i<n; ++i)
    {
        v[i].push_back(i);
        row[i]=i;
    }
    int a, b;
    while(cin>>s)
    {
        if(s=="quit")break;

        if(s=="move")
        {
            cin>>a>>s>>b;
            if(s=="onto")moveOnTo(a,b);
            else moveOver(a,b);
        }
        else
        {
            cin>>a>>s>>b;
            if(s=="onto")pileOnTo(a,b);
            else pileOver(a,b);
        }
    }
    for(int i=0; i<n; ++i)
    {
        cout<<i<<":";
        for(int j=0; j<v[i].size(); ++j)
        {
            cout<<" "<<v[i][j];
        }
        cout<<endl;
    }














}
