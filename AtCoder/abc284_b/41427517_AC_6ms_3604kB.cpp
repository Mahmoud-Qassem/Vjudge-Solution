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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ans=0;
        while(n--)
        {
            cin>>cnt;
            ans+=(cnt&1);
        }
        cout<<ans<<endl;
    }



}
