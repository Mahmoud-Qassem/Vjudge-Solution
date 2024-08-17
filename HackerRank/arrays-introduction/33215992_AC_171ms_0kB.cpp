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
    int n;cin>>n;vi v(n);For(n)cin>>v[i];reverse(all(v));For(n)cout<<v[i]<<" ";
}







