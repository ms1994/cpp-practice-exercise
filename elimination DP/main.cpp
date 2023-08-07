#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int elimination()
    {
        int n,m,c,k,d;
        cin >> c >> d;
        cin >> n >> m;
        cin >> k;
        if (k >= n*m) return 0;
        int answer = 1e9;
        for (int i = 0; i < m+1; i++)
        {
            for (int j = 0; j <= n*m; j++)
            {
                int f = n*i+j;
                if (f >= n*m-k)
                {
                    answer = min(answer, i*c+j*d);
                }
            }
        }
        return answer;
    }
};

int main()
{
    Solution obj;
    cout << obj.elimination() << endl;
    return 0;
}
