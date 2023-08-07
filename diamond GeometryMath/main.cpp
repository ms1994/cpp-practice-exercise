#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    void calcDist()
    {
        int n;
        scanf("%d", &n);
        vector <double> diamonds;
        vector <double> miners;
        double answer = 0;
        for (int i = 0; i < 2*n; i++)
        {
            double px,py;
            scanf("%lf %lf", &px,&py);
            if (px == 0)
            {
                miners.push_back(abs(py));
            }
            else if (py == 0)
            {
                diamonds.push_back(abs(px));
            }
        }
        sort(diamonds.begin(), diamonds.end());
        sort(miners.begin(), miners.end());
        for (int i = 0; i < n; i++)
        {
            double a = pow(miners[i],2);
            double b = pow(diamonds[i],2);
            answer += sqrt(a + b);
        }
        printf("%.16lf\n", answer);
    }

};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Solution obj;
        obj.calcDist();
    }
    return 0;
}
