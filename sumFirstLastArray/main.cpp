#include <bits/stdc++.h>

using namespace std;
void sumElements();
int main()
{
    sumElements();
    return 0;
}
void sumElements()
{
    int n;
    cin >> n;
    vector <int> arr;
    unordered_set <int> guide;
    for (int i = 0; i < 2*n; i++)
    {
        int a;
        cin >> a;
        guide.insert(a);
        arr.push_back(a);
    }
    if (guide.size() == 1)
        cout << -1 << endl;
    else {
        sort(arr.begin(), arr.end());
        for (auto it : arr)
            cout << it << " ";
    }
}
