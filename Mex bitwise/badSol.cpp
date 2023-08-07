#include <bits/stdc++.h>

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

long long MEX(int n, int m);

int main()
{
    send help
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        cout << MEX(n,m) << '\n';
    }
}

long long MEX(int n, int m)
{
    if (n > m) return 0;
    if (n == 0) return m + 1;
    long long p = m + 1;
    long long ans = 1e9;
    for (long long i = p; i<=p + 1000; i++)
    {
        long long a = n ^ i;
        if (a <= m)
        {
            ans = min(ans, a);
        }
    }
    //falta por hacer.
    return ans;
}
