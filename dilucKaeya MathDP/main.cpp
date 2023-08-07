#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void frequency()
    {
        int n;
        cin >> n;
        int freqD = 0;
        int freqK = 0;
        map <double, int> point;
        for (int i= 0; i < n; i++)
        {
            char c;
            cin >> c;
            if (c == 'D') freqD++;
            if (c == 'K') freqK++;
            if (freqD == 0)
            {
                ++point[-1];
                cout << point[-1]<< " ";
            }
            else
            {
                double m = (double) freqK/freqD;
                //se puede ver tambien como el GCD gratest commund division
                //funcion ya establecida en c++ creo
                point[m]++;
                cout << point[m] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solution obj;
        obj.frequency();
    }
    return 0;
}
