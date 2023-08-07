#include <bits/stdc++.h>

using namespace std;
long long sameDifferences();
long long sumatory(int a);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cout << sameDifferences() << endl;
    }

    return 0;
}

long long sameDifferences()
{
    int n;
    cin >> n;
    map <int, int> diff;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        diff[a-i]++;
    }
    long long answer = 0;
    for (auto it:diff)
    {
        if (it.second > 1)
            answer += sumatory(it.second);
    }
    return answer;

};

long long sumatory(int a)
{
    long long cont = 0;
    for (int i = 1; i < a; i++)
    {
        cont += i;
    }
    return cont;
};

