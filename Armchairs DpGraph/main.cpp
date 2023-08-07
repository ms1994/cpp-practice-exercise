#include <bits/stdc++.h>
using namespace std;


#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}


int main()
{
    send help
    int n;
    cin >> n;
    vector <int> arr(n);
    vector<int> ones;
    vector <int> zeros;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i]) ones.push_back(i);
        else zeros.push_back(i);
    }
    int ans = 0;
    sort(ones.begin(), ones.end());
    sort(zeros.begin(), zeros.end());
    for (int i = 0; i < ones.size(); i++)
    {
        ans += abs(ones[i] - zeros[i]);
    }
    /*
    set <int> zeros;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            int p1 = i - 1 < 0 ? 0 : i - 1;
            int p2 = i + 1 >= n ? n - 1: i + 1;
            while (true)
            {
                if (p1 != i && !arr[p1] && !zeros.count(p1))
                {
                    zeros.insert(p1);
                    ans = ans + abs(p1-i);
                    break;
                }
                else if (p2 != i && !arr[p2] && !zeros.count(p2))
                {
                    zeros.insert(p2);
                    ans = ans + abs(i-p2);
                    break;
                }
                p1 = p1 - 1 < 0 ? 0: p1 - 1;
                p2 = p2 + 1 >= n ? n - 1: p2 + 1;
            }
        }
    }*/
    cout << ans << '\n';
    return 0;
}
