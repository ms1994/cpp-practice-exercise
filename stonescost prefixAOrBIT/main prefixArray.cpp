#include <bits/stdc++.h>

using namespace std;

void prefixNormal(int n, long long prefix1[], vector <int> v);
void countSort(int l, int r, vector <int> v);
int main()
{
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for (int &i : v) scanf("%d", &i);
    long long prefix1[n];
    long long prefix2[n];
    prefixNormal(n,prefix1,v);
    sort(v.begin(),v.end());
    prefixNormal(n,prefix2,v);
    int m;
    scanf("%d", &m);
    while (m--) //complexity n*q muy grande
    {
        int  type,l,r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
        {
            if (l != 1) cout << prefix1[r-1] - prefix1[l-2] << endl;
            else cout << prefix1[r-1] << endl;
        }
        else
        {
            if (l != 1) cout << prefix2[r-1] - prefix2[l-2] << endl;
            else cout << prefix2[r-1] << endl;
        }
    }
    return 0;
}

void prefixNormal(int n, long long prefix1[], vector <int> v)
{
    prefix1[0] = v[0];
    for (int i = 1; i < n; i++) //prefix array
    {
            prefix1[i] = prefix1[i-1] + v[i];
    }
};

void countSort(int l, int r, vector <int> v)
{
    sort(v.begin(),v.end());//no sirve el accumulate porque trabaja es lineal
    long long result = accumulate(v.begin() + l - 1, v.begin() + r, 0LL);
    printf("%d\n", result);
    return;
};
