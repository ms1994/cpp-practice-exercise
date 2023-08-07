#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%d%d", &n,&q);
    vector <int> a(n);
    for (int &x: a) scanf("%d", &x);
    while (q--)
    {
        int t;
        scanf("%d", &t);
        int pos = find(a.begin(), a.end(), t) - a.begin();
        printf("%d ", pos+1);
        rotate(a.begin(), a.begin() + pos, a.begin() + 1 + pos);
    }
}
