#include <bits/stdc++.h>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;

void sieve ( vector <int> arr[])
{
    for (int i = 1; i <= 10000; i++)
    {
        for (int j = 1; j * i <= 10000; j++)
        {
            arr[i].push_back(i*j);
        }
    }
}

void sol(vector <int> arr[])
{
    int a,b,c;
    cin >> a >> b >> c;
    int best = 1e6;
    int a_good = 1e6,b_good = 1e6, c_good = 1e6;
    for (int i =1; i <= b; i++)
    {
        int aux_b_up = 1e6, aux_b_lower = 1e6, aux_c_up = 1e6, aux_c_lower = 1e6;
        int val_b_up = 1e6, val_b_lower = 1e6, val_c_up = 1e6, val_c_lower = 1e6;
        int best_b = 1e6, best_c = 1e6;
        int sum = abs(a-i);
        int b_up = upper_bound(arr[i].begin(), arr[i].end(), b) - arr[i].begin();
        int b_lower = lower_bound(arr[i].begin(), arr[i].end(), b) - arr[i].begin();
        int c_up = upper_bound(arr[i].begin(), arr[i].end(), c) - arr[i].begin();
        int c_lower = lower_bound(arr[i].begin(), arr[i].end(), c) - arr[i].begin();
        if (arr[i].size() > b_up && arr[i][b_up] <= c)
        {
            aux_b_up = abs(b -arr[i][b_up]);
            val_b_up = arr[i][b_up];
        }
        if (arr[i].size() > b_lower && arr[i][b_lower] >= a)
        {
            aux_b_lower = abs(b  - arr[i][b_lower]);
            val_b_lower = arr[i][b_lower];
        }
        if (val_b_up == 1e6 && val_b_lower == 1e6) continue;
        if (aux_b_lower < aux_b_up)
        {
            best_b = val_b_lower;
            sum += aux_b_lower;
        }
        else
        {
            best_b = val_b_up;
            sum += aux_b_up;
        }
        if (arr[i].size()> c_up && arr[i][c_up] <= 10000)
        {
            aux_c_up = abs(c-arr[i][c_up]);
            val_c_up = arr[i][c_up];
        }
        if (arr[i].size()  > c_lower && c_lower >= b)
        {
            aux_c_lower = abs(c-arr[i][c_lower]);
            val_c_lower = arr[i][c_lower];
        }
        if (val_c_lower == 1e6 && val_c_up == 1e6) continue;
        if (aux_c_lower < aux_c_up)
        {
            best_c = val_c_lower;
            sum += aux_c_lower;
        }
        else
        {
            best_c = val_c_up;
            sum += aux_c_up;
        }
        if (sum < best)
        {
            a_good = i;
            b_good = best_b;
            c_good = best_c;
            best = sum;
        }
    }
    cout << best << '\n';
    cout << a_good << " " << b_good << " " << c_good << '\n';
}
int main()
{
    send help
    vector <int> arr[10010];
    sieve(arr);
    int t;
    cin >> t;
    while(t--)
    {
       sol(arr);
    }
    return 0;
}
