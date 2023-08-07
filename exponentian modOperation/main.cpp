#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    long long answer = 1;
    for (int i = 0; i < b;i++)
    {
        answer = (answer*a)%c;
    }
    cout << answer%c << endl;
    return 0;
}
