#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long numberOfPapers()
    {
        int a, n;
        cin >> a >> n;
        long long papers = 0;
        for (int i = 0; i<n; i++)
        {
            papers += papersForYear(a++);
        }
        return papers;

    }
    long long papersForYear(int a)//no sirve porque tarda mucho O{n*squrt(n)}
    {
        int limit = sqrt(a) + 1;
        long long days = 1;
        for (int i = 1; i <= limit; i++)
        {
            long long aux = i*i;
            if (a%aux == 0)
            {
                days = max(days, aux);
            }
        }
        return a / days;
    }
    long long sieveThethorenes()
    {
        int a, n;
        cin >> a >> n;
        vector <int> x(a+n);
        for (int i = 0; i < a + n; i++)
        {
            x[i] = i;
        }
        int limit = sqrt(a+n) + 1;
        for (int i = 2; i <= limit; i++)
        {
            int cont = 0;
            for (int j = i*i; j < a + n; j+= i*i)
            {
                x[j] = ++cont;
            }
        }
        long long sum = 0;
        for (int i=a; i < a+n; i++)
        {
            sum += x[i];
        }
        return sum;
    }


};
int main()
{
    Solution obj;
    cout << obj.sieveThethorenes() <<endl;
    return 0;
}
