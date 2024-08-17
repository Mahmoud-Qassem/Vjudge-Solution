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
bool isvowel(char c)
{
    if(c=='a'||c=='A')
        return 1;
    if(c=='o'||c=='O')
        return 1;
    if(c=='Y'||c=='y')
        return 1;
    if(c=='E'||c=='e')
        return 1;
    if(c=='U'||c=='u')
        return 1;
    if(c=='I'||c=='i')
        return 1;
    return 0;
}
///*  cout << fixed << setprecision(7);
///*  work smart not hard  :) E.MS
int main()
{
    GO
    string s;
    cin>>s;
    For(sz(s))
    {
        if(!isvowel(s[i]))
        {
             cout<<'.'<<char(tolower(s[i]));

        }
    }


}







