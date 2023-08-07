#include <bits/stdc++.h>
using namespace std;


#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;

void solved(int n);
/*
Para relacionar los dos parametros en el knapsack se usa un dp[k][As] = Bs

y luego busco el mayor valor para cada row de ese dp sabiendo que no puede ser menor al As

la formula para saber la cantidad de agua es (Bt + Bs)/2, el min entre eso y la cantidad de agua total

Ejercicio muy confuso, perfecto para estudiar knapsack y el dp dentro del knapsack, esta vez no se usa para
saber si es possible la suma y ya, sino se utiliza para saber si es posible sumar tomando en cuenta la capacidad total de vaso
llevando la cuenta de cuantos vasos he tomado(tamano del subset), y el valor de la suma de As como parametro del dp
y el resultado no es boolean sino Bs, la cantidad de agua inicial, para cada valor de A[i] cuando es positivo el dp(knapsack)

aumento el rango en A, con a[i] y al resultado le sumo b[i]. El At lo tomamos greedy con el valor max para cada vaso (100);

ver codigo.

*/

int main()
{
    send help
    cout << setprecision(10);
    int n;
    cin >> n;
    solved(n);
    return 0;
}
void solved(int n)
{
    vector<double> a(n);
    vector<double> b(n);
    double totalWaterIn = 0;
    for (int i = 0; i < n; i++)
    {
        cin>> a[i] >> b[i];
        totalWaterIn += b[i];
    }
    vector<vector<double>>dp(n+1, vector<double> (n*100 + 10, -1));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int k = i; k >= 0; k--)
        {
            for (int val = 0; val <= i*100; val++)
            {
                if (dp[k][val] >=0)//si es valor is possible
                {
                    dp[k+1][val + a[i]] = max(dp[k+1][val + a[i]], dp[k][val] + b[i]);
                    // asi se juntan dos valores que estan relacionados usando un Knpapsack
                }
            }
        }
    }
    vector<double> ans(n+1, -1);
    for (int i = 1; i <= n; i++)
    {
        for (int val = 0; val <= i*100; val++)
        {
            if (dp[i][val] >= 0)
            {
                ans[i] = max(ans[i], min((double) val, (totalWaterIn + dp[i][val])/2));// el max entre todos los posibles valores con
                //un vaso, dos vasos, tres vasos...n vasos
            }
        }
        printf("%.10f ", ans[i]);
    }









}
