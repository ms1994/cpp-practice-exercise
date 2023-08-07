#include <bits/stdc++.h>

using namespace std;

long long inf = 10e9;

class Solution
{
public:
    void airConditioner()
    {
        int n, k;
        cin >> n >> k;
        vector <int> a;
        vector <int> t;
        for (int i = 0; i < k; i++)
        {
            int ai;
            cin >> ai;
            a.push_back(ai);
        }
        for (int i = 0; i < k; i++)
        {
            int ti;
            cin >> ti;
            t.push_back(ti);
        }
        vector <long long> left(n+1, inf);
        vector <long long> right(n+1, inf);
        vector <long long> c(n+1, inf);
        for (int i = 0; i < k; i++)
        {
           c[a[i]] = t[i];
        }
        long long p = inf;
        for (int i = 0; i <= n; i++)
        {
            p = min(p+1, c[i]);
            left[i] = p;
        }
        for (int i = n; i >= 0; i--)
        {
            p = min(p+1, c[i]);
            right[i] = p;
        }
        for (int i = 1; i <= n; i++)
        {
            long long answer = min(left[i], right[i]);
            cout << answer << " ";
        }
        cout << endl;
    }
};


int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        Solution obj;
        obj.airConditioner();
    }
    return 0;
}
