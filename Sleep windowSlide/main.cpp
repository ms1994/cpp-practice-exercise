#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int lectureSleep()
    {
        int n, k;
        cin >> n >> k;
        vector <int>  lectures, sleep;
        for (int j = 0; j < n; j++)
        {
            int l;
            cin >> l;
            lectures.push_back(l);
        }
        for (int j = 0; j < n; j++)
        {
            int slp;
            cin >> slp;
            sleep.push_back(slp);
        }
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < k; i++)
        {
            if (sleep[i]) sum1 += lectures[i];
            else sum2+=lectures[i];
        }
        int best = sum2;
        for (int i = k; i < n; i++)
        {
            if (sleep[i]) sum1 += lectures[i];
            else sum2+=lectures[i];
            if (!sleep[i-k]) sum2-=lectures[i-k];
            best = max(best,sum2);
        }
        return sum1 + best;
    }
};


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    Solution obj;
    int answer = obj.lectureSleep();
    cout << answer << endl;
}
