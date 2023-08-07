#include <bits/stdc++.h>

using namespace std;

void initBIT(long long BITArr[], int n);
void updateBIT(long long BITArr[], int n, int index, int value);
long long sumBIT (long long BITArr[], int index);
int main()
{
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for (int &i : v) scanf("%d", &i);
    long long BIT1[n+1];
    long long BIT2[n+1];
    initBIT(BIT1, n);
    initBIT(BIT2, n);
    for (int i = 0; i < n; i++) updateBIT(BIT1, n, i, v[i]);
    sort(v.begin(),v.end());
    for (int i = 0; i < n; i++) updateBIT(BIT2, n, i, v[i]);
    int m;
    scanf("%d", &m);
    while (m--)
    {
        int  type,l,r;
        scanf("%d %d %d", &type, &l, &r);
        if (type == 1)
        {
            cout << sumBIT(BIT1, r) - sumBIT(BIT1, l-1) << endl;
        }
        else
        {
           cout << sumBIT(BIT2, r) - sumBIT(BIT2, l-1) << endl;
        }
    }
}

void initBIT(long long BITArr[], int n)
{
    for (int i = 1; i < n + 1; i++)
    {
        BITArr[i] = 0;
    }
};

void updateBIT(long long BITArr[], int n, int index, int value)
{
    index++;
    while (index <= n)
    {
        BITArr[index] += value;
        index += index & (-index);
    }
};
long long sumBIT (long long BITArr[], int index)
{
    long long result = 0;
    while (index > 0)
    {
        result += BITArr[index];
        index -= index&-index;
    }
    return result;
};
