#include "bits/stdc++.h"
using namespace std;

//solution saw in the tutorial DP
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

typedef long long ll;
int dp[10][20];
class Solution{

const int N = 200;
int INF = 1e9;
public:
    void sol()
    {
        int n;//los minutos van hasta un rango max de 2*n
        cin >> n;
        vector <int> t(n);
        for (int i = 0; i < n; i++)
        {
            cin >> t[i];
            --t[i];
        }
        sort(t.begin(), t.end());
        //vector <vector<int>> dp(n+1, vector <int>(2*n, INF));
        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j < 2*n; j++)
            {
                dp[i][j] = INF;
            }
        }
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < 2*n-1; j++)
            {
                if (dp[i][j] < INF)//no repites J, es decir tomas los dp desde i=j, cuando vayas por el i=3,
                    //j sera inf hasta j = 3, simbolizando que ya tome ese valor de j en cuenta para la resga
                    //por eso es importante que el vector este ordanado, un valor pequeno restado con un valor tj
                    //mas pequeno siempre sera menor a uno restado con un tj mas grande (ver tutorial para la explicacion)
                {
                    if (i < n)
                    {
                        dp[i+1][j+1] = min(dp[i+1][j+1],dp[i][j] + abs(t[i] -j));//para el prox i veo cual es el
                        //MENOR entre el menor valor de la row actual + el diferencia entre los j restantes y el T
                        //Este valor se ira incrementando a medida que se incrementa j, el valor menor de la row
                        //es constante y se calcula con la linea de abajo
                    }
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j]);//evalua y busca el menor valor entre la row
                    //va arrastrando el valor, entre el los calculados en el paso i-1, y su valor minimo
                    //se utiliza el j+1 para buscar el min y utilizarlo en la formula de arriba como dp[i][j]
                }
            }
        }
        cout << dp[n][2*n-1]  << '\n';
    }
};


int main()
{
    send help
    int q = 0;
    cin >> q;
    while (q--)
    {
        Solution obj;
        obj.sol();
    }
    return 0;
}
