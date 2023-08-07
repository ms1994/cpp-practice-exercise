#include <bits/stdc++.h>

using namespace std;

int main() //no sirve el algortimo porque tarda mucho O(n*q)
{
    int n,q;
    scanf("%d%d", &n,&q);
    vector <int> a(n);
    for (int &x: a) scanf("%d", &x);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        for (int i = 0; i < n; i++)
        {//es mejor usar el find poeque utiliza un algoritmo mas veloz que el lineal
            if (t != a[i]) continue;
            else
            {
                printf("%d ", i +1);
                a.erase(a.begin() + i);
                a.insert(a.begin(), t);
                break;
            }
        }
    }
}
