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
    int n;
    cin>>n;
    for(int i=5;i>=1;--i)
    {
        divide(n,i);
    }
    cout<<cnt<<endl;





}
