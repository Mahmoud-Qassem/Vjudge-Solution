#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
vector<int>pf;
void SieveOfAtkin(int limit)
{
    bool sieve[limit];
    for (int i = 0; i <= limit; i++)
        sieve[i] = false;
    if (limit > 2)
        sieve[2] = true;
    if (limit > 3)
        sieve[3] = true;
    for (int x = 1; x * x <= limit; x++)
    {
        for (int y = 1; y * y <= limit; y++)
        {

            // Condition 1
            int n = (4 * x * x) + (y * y);
            if (n <= limit
                    && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            // Condition 2
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            // Condition 3
            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit
                    && n % 12 == 11)
                sieve[n] ^= true;
        }
    }
    for (int r = 5; r * r <= limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r * r; i <= limit; i += r * r)
                sieve[i] = false;
        }
    }
    for (int a = 1; a <= limit; a++)
        if (sieve[a])
            pf.push_back(a);

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    SieveOfAtkin(1000000);
    vector<vector<int>>res(1000005,vector<int>(6));
    for(int i=2; i<1000001; ++i)
    {
        int x=i,idx=0;
        res[i][4]=1,res[i][5]=1;
        int lll=upper_bound(pf.begin(),pf.end(),sqrt(i))-pf.begin();
        for(int j=0;j<lll; j++)
        {
            int d=pf[j];
            if(x%d==0)
            {
                if(not res[i][0])res[i][0]=d;

                res[i][1]=d;
                res[i][2]++;
            }
            int tmpsum=1;
            idx=1;
            int cnt=0;
            while(x%d==0)
            {
                x/=d,res[i][3]++,cnt++;
                tmpsum+=powl(d,idx++);
            }
            cnt++;
            res[i][4]*=cnt;
            res[i][5]*=tmpsum;

        }
        //cout<<x<<endl;
        if(x>1)
        {
            if(not res[i][0])res[i][0]=x;
            res[i][4]*=2;
            res[i][5]*=(1+x);
            res[i][1]=max(res[i][1],x);
            res[i][2]++;
            res[i][3]++;
        }
    }
    int n,ff;
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>ff;
        for(auto&it:res[ff])cout<<it<<" ";
        cout<<endl;
    }

}
