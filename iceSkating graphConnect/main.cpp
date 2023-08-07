#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector <pair <int, int>> points;
    set <int> px;
    set <int> py;
    vector <bool> visited;
public:

    int iceSkiting()
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int x,y;
            cin >> x >> y;
            points.push_back(make_pair(x, y));
        }
        sort(points.begin(), points.end());
        int cont = 0;
        px.insert(points[0].first);
        py.insert(points[0].second);
        for (int i = 1; i < n; i++)
        {
            if (px.count(points[i].first)==0 && py.count(points[i].second)==0)
            {
                cont++;
                px.insert(points[i].first);
                py.insert(points[i].second);
            }
            else
            {
                px.insert(points[i].first);
                py.insert(points[i].second);
            }
        }
        return cont;
    }
    int trueSolution()
{
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            int x,y;
            cin >> x >> y;
            points.push_back(make_pair(x, y));
            visited.push_back(false);
        }
        int cont = 0;
        for (int i = 0; i < n; i++)
        {//en las soluciones vistas se usa un dfs para ver si el vertice fue visitado y si esta conectado
            if (!visited[i])
            {
                dfs(i,n);
                cont++;
            }
        }//para conectar solo necesitan que el eje x se intercepte con el eje y de los otros puntos
        //la solucion seria esas conexiones menos 1 ya que la primera vez que se ejecuta, se
        //suma uno por defecto ya que el programa
        //del dfs no ha corroborado la conectividad de los nodos
        //el programa con el dfs siempre dejara en falso los nodos que no esten conectados
        //por eso cada vez q un punto es falso se suma uno, como al princcipio no sabemos que puntos estan
        //conectados habra que restarle al final ese nodo inicial.
        return cont == 0 ? 0: cont - 1;
}

void dfs(int i, int n)
{
    visited[i] = true;
    for (int j = 0; j < n; j++)
    {
        if (!visited[j] && (points[i].first == points[j].first || points[i].second == points[j].second))
            dfs(j, n);
    }
    return;
}
};
int main()
{
    Solution obj;
    cout << obj.trueSolution() << endl;

    return 0;
}


