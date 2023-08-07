#include <bits/stdc++.h>

using namespace std;
string solve();
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
       cout << solve() << endl;
    }

    return 0;
}
string solve()//no sirve falta estudiar un caso en los test
{
    int n;
    cin >> n;
    vector <vector <int>> vec;
    vector <int> a;
    multiset <int> b;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        int ai;
        cin >> ai;
        a.push_back(ai);
        b.insert(ai);
    }
    vec.push_back(a);
    while (vec[i].size() > 2)
    {
        a.clear();
        for (int j = 0; j < vec[i].size() - 1; j++)
        {
            if (j == 0 && vec[i].size() % 2 == 1) a.push_back(vec[i][0]);
            else
            {
                int xorC = vec[i][j]^vec[i][j+1];
                a.push_back(xorC);
                j++;
            }
        }
        vec.push_back(a);
        i++;
    }
    return vec[i][0] == vec[i][1] ? "YES":"NO";
}
