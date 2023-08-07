#include <bits/stdc++.h>

using namespace std;
void valeriiArray();
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        unordered_map <int, int> a;
        bool ans = false;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            unsigned int k;
            cin >> k;
            a[k]++;
            if (a[k] > 1) ans = true;
        }
        if (ans) {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

}

void valeriiArray()
{
    int n;
    unordered_map <int, int> a;
    bool ans = false;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        unsigned int k;
        cin >> k;
        a[k]++;
        if (a[k] > 1) ans = true;
    }
    if (ans) {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
