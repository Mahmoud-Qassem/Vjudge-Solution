#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define T     \
	int t;    \
	cin >> t; \
	while (t--)
#define GO ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(b) for (int i = 0; i < b; i++)
#define ff(a,b,i) for (int i = a; i < b; i++)
#define nf(a, b, i) for (int i = b - 1; i >= a; i--)
#define vi vector<int>
#define vl vector<ll>
#define li list<int>
#define dqi deque<int>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define sz(v) v.size()
#define NO  cout<<"NO";
///*  cout << fixed << setprecision(7);
///*  work smart not hard  :) E.MS
int main()
{
    GO
    int cnt=0,n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=97;i<=122;++i)
    {
        char c=char(i);
        char cc=char(i)-32;
        if(s.find(c)!=string::npos||s.find(cc)!=string::npos)cnt++;
    }
    if(cnt==26)cout<<"YES";
    else cout<<"NO";



}







