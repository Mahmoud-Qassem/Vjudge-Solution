
#include "iostream"
#include "iostream"
#include "iomanip"
#include "map"
#include "cmath"
#include "algorithm"
#include "string"
#include "vector"
#include "queue"
#include "set"
#include "deque"
#include "stack"
#include "bitset"
#include "fstream"
#include "map"
#include "unordered_map"
//#include<bits/stdc++.h>
#include<stack>
#include<set>
using namespace std;
typedef long long int  ll;
typedef unsigned long long ull;
void fast()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
#define T int t;cin>>t;while(t--)
#define fast fast()
#define ff(a,b,i) for (int i = a; i < b; i++)
#define nf(a,b,i) for (int i = b-1; i >= a; i--)
#define vi vector<int>
#define vl vector<ll>
#define li list<int>
#define dqi deque<int>
#define endl '\n'
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(),v.rend()
#define sz(v) v.size()
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;
	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;
	return true;
}
///*work smart not hard  :) E.MS*/

int main()
{
    fast;
    ll n,x,tmp,cnt=0;
    cin>>n>>x;
    char c;
    for(ll i=0;i<n;i++)
    {
        cin>>c>>tmp;
        if(c=='+')
        x+=tmp;
        else
        {
            if(x>=tmp)x-=tmp;
            else cnt ++;
        }
    }
    cout<<x<<" "<<cnt;
    
}