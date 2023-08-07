#include <bits/stdc++.h>
using namespace std;
/*
Mi idea inicial no estaba tan alejada de la solucion, pero no se puede hacer porque no se como
acomodar todos los componentes en una.
Segun la editorial puedes hacer un hashmap con las coordenadas x o y y comparar el i con el i-1 porque estan
ordenadas, comparamos sus valores en "y" y en "x". Luego hallamos el menor tiempo para cada componente (sistema de varias minas)
y con ese nuevo vector podemos hacer el calculo de la respuesta.

Haciendo el max(sorted array con los compoenntes (a[i]), a.size() - i - 2) es minimo. (estudiar esta formula para entenderla)

Intentar hacer primero un map con un array o set de la otra coordenada para luego buscar por binary search entre todos los valores
de x o y iguales si el mas cercano a el puede formar un edge

map <int, set/vector> mx;

mx[points[i].f] = te devuelve un set o un vector segun lo que tengas
a eso le aplicas el lower bound para buscar su y mas cercano lowerboiund( begin(), end(), points[i].s + 1) Y mas cercano
si cumple tu condicion lo add a tu component, luego buscas el menor time para cada component y haces un vector "a" con cada
menor tiempo. Y al final para saber la sol haces un greedy diciendo que
tu best = a.size - 1 (porque el time es zero-index)
ahora con tu array ordenado de a buscas para cada ith de a el tiempo como:
timpo = max(a[i], a.size - 2 -i )
aqui el -2 simboliza el hecho de que en cada segundo puedes explotar un componente por tu cuenta y que un compoente explote
por el tiempo.
si el tiempo = a[i], simboliza el hecho de que ese componente no explotara a ese i-th por lo que habra que esperar esos a[i] segundos
hasta que explote.
Cuando tiempo = a.size - 2 - i, simboliza que explotan dos componentes.
Adicional: Si queremos hacer el programa mas rapido podemos finalizar el ultimo loop diciendo que si el tiempo > best (a.size - 1)
salir porque ya es un caso imposible de cumplir por lo que seguir viendo no se puede


map<int, set<pair<int,int>>> mx lo mismo con y, set para que este ya ordenado por defecto
o uso un vector y lo ordeno, pair para tener el valor de la otra coordenada y el tiempo
O el t en un array de t[n] y la otra coordenada guardo i-th
adj[n].push(i-th)
adj[i-th].push(n);
size_of_A = 0;
for (i = 0 hasta n)
    if (!used(i))
        min_time = dfs(i-th, time[i], parent)
        a[size_of_A++] = min_time

int dfs (i, parent)
    used[i] = true;
    res = time[i]/ time;
    for (auto x: adj[i])
        if (x == p) continue;
        res = min(res, dfs(x,i);
    return time;
*/

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
int used[200020];
int times[200020];
map <int, set <pair<int,int>>> mx;
map<int, set <pair<int,int>>> my;
int dfs(vector<int>adj[], int point)
{
    used[point] = 1;
    int res = times[point];
    for (auto x : adj[point])
    {
        if (used[x]) continue;
        res = min(res, dfs(adj, x));
    }
    return res;
}

void dfs2(vector<int>adj[], int i, int par)
{
    cout << " point " << i << " : ";
    for (auto x : adj[i])
        cout << x << " ";
    cout << endl;
}


void sol(int t=0)
{
    int n, k;
    cin >> n >> k;
    vector<int> adj[n+10];
    vector <pair <int, int>> points(n+1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y >> times[i];
        points[i] = make_pair(x,y);
        mx[x].insert(make_pair(y, i));
        my[y].insert(make_pair(x, i));
    }
    for (int i = 0; i < n; i++)
    {
        int x = points[i].first;
        int y = points[i].second;
        auto py = mx[x].lower_bound(make_pair(y+1, 0)); // valor de la coordenada y mas cercana a x
        if (py != mx[x].end() && abs(py->first - y) <= k)
        {
            //make an edge between these two points
            adj[i].push_back(py->second);
            adj[py->second].push_back(i);
        }
        auto px = my[y].lower_bound(make_pair(x+1, 0)); // valor de la coordenada x mas cercana a y
        if (px != my[y].end() && abs(px->first - x) <= k)
        {
            //make an edge between these two points
            adj[i].push_back(px->second);
            adj[px->second].push_back(i);
        }
    }/*
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        dfs2(adj,i,-1);
    }*/
    vector <int> min_times(n+1, 1e9 + 10);
    int sz_times = 0;
    for(int i = 0; i <n; i++)
    {
        if (!used[i])
        {
            int min_time = dfs(adj,i);
            min_times[sz_times++] = min_time;
        }
    }
    min_times.resize(sz_times);
    sort(min_times.begin(), min_times.end());
    int res = min_times.size() - 1;
    for (int i = 0; i < min_times.size() - 1; i++)
    {
        int b = min_times.size() - 2 - i;
        int aux = max(min_times[i], b);
        if (aux < res)
        {
            res = aux;
        }
        else if (aux > min_times.size()-1) break;
    }
    cout << res <<'\n';
}

int main()
{
    send help
    int t;
    cin >> t;
    while(t--)
    {
        mx.clear();
        my.clear();
        memset(used, 0, sizeof(used));
        memset(times, 0, sizeof(times));
        sol();
    }
    return 0;
}
