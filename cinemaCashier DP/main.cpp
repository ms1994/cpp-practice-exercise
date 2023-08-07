#include <bits/stdc++.h>

using namespace std;
int seats[110][110];

class Solution
{
    vector <int> m;
public:
    void freeSeat()
    {
        int n,k;
        scanf("%d %d", &n, &k);
        m.resize(n);
        for (auto &x: m) scanf("%d", &x);
        int center = (k/2) + 1;
        for (int i = 0; i < n; i++)
        {
            int answer = 1e6;
            int ansx,ansy1,ansy2;
          for (int j = 1; j<= k; j++)
          {
              for (int t = 1; t <= k-m[i]+1;t++)//me aseguro que el yl y yr no pase los limites
              {//forma de no pasar los bounderies y probar todos lo casos por brutal force
                  int flag = 1;
                  int f = 0;
                  for (int l = t; l < t+m[i]; l++)
                  {
                      f += abs(center-j)+abs(center-l);
                      if (seats[j][l])
                      {
                          flag = 0;
                          break;
                      }
                  }
                  if (flag && f < answer)
                  {
                      ansx = j;
                      ansy1=t;
                      ansy2=t+m[i]-1;//formula dada por el problema
                      answer = f;
                  }
              }
          }
          if (answer < 1e6)
          {
              for (int j = ansy1; j<=ansy2; j++)
              {
                  seats[ansx][j] = 1;//memorization
              }
              printf("%d %d %d\n", ansx, ansy1, ansy2);
          }
          else puts("-1\n");
        }//printf("%d ", m[i]);
    }
};

int main()
{
    Solution obj;
    obj.freeSeat();
    return 0;
}
