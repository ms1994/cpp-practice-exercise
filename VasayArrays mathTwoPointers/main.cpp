#include <bits/stdc++.h>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
/*
Dos pointers y aumento el ans cada vez que el acumulado entre ambos arrays sean iguales
O(n + m || max(n,m)), mi codigo solo funciona cuando la suma total de los dos arrays es la
misma.
*/


int main()
{
    send help
    int n, m;
    vector <int> arr1;
    vector <int> arr2;
    ll cont1 = 0, cont2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        arr1.push_back(a);
        cont1 += a;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int b;
        cin >> b;
        arr2.push_back(b);
        cont2 += b;
    }
    if (cont1 == cont2)
    {
        int ptr1 = 0,ptr2 = 0;
        int ans = 0;
        ll aux1 = arr1[ptr1], aux2 = arr2[ptr2];
        while (true)
        {
            if (ptr1 >= n || ptr2 >= m) break;
            if (aux1 == aux2)
            {
                ans++;
                ptr1++;
                ptr2++;
                aux1 = arr1[ptr1 < n ? ptr1:n-1];
                aux2 = arr2[ptr2 < m ? ptr2 : m-1];
            }
            else if (aux1 > aux2)
            {
                ptr2++;
                aux2 += arr2[ptr2];
            }
            else if (aux1 < aux2)
            {
                ptr1++;
                aux1 += arr1[ptr1];
            }
        }
        cout << ans << '\n';
    }
    else cout << -1 << '\n';
    return 0;
}
