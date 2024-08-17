#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int cnt;
void divide(int&n,int d)
{
    int tmp=n/d;
    cnt+=tmp;
    n%=d;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int n,dsafjalfldskfjsdmnfkl=0;
    while(cin>>n)
    {
        if(not n)break;
        if(dsafjalfldskfjsdmnfkl)cout<<endl;
        vector<int>v(n),tmp;
        for(int i=0; i<n; ++i)
        {
            cin>>v[i];
        }
        int idx=1;
        stack<int>st;
        for(int i=0; i<n; ++i)
        {
            if(v[i]==idx)
            {
                tmp.push_back(idx);
                idx++;
                while(st.size() and st.top()==idx)
                {
                    tmp.push_back(st.top());
                    st.pop();
                    idx++;
                }
            }
            else st.push(v[i]);
        }
        if(idx==n+1 and is_sorted(tmp.begin(),tmp.end()))cout<<"yes";
        else cout<<"no";
        dsafjalfldskfjsdmnfkl=1;

    }



}
