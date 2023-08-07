#include <bits/stdc++.h>
using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
/*
En un tree el numero de simple Path viene dado por la formula de: n*(n-1)/2
que se explica de la siguiente manera. En un tree de "n" nodes sabemos que tiene n-1 edges, es decir que habra
un simple path por cada edge y por cada node, eso matematicamente viene representado por n*(n-1), y como ese numero
me representa todos los caminos, hay caminos que son el mismo pero invirtiendo los nodes, hay que extraer los caminos
repetidos, para eso se divide entre 2. ejm n = 3, 1 - 2 - 3. esta el camino 123 y tambien el camino 321. como son el
mismo path debemos dividir el numero final entre 2.

Ahora para este problema como solo hay un edge adicional sabemos que se formara un ciclo (propiedades del tree)
el grafico lo podemos ver entonces como un ciclo donde cada uno de los vertices del ciclo forman un independent tree.
por cada independent tree su numero de caminos vendra representada por la formula de arriba, solo tendremos que conocer
el numero de caminos fuera de cada tree, Ese valor seria contv(n-contv) contv = size de cada independent subtree

Segun el editorial con sumar solo eso basta y no es necesario sumarlo dos veces por cada vertice (cuando hay ciclos en un
tree significa que ahora hay dos caminos diferentes para llegar a un node, antes solo existia un solo camino)
la solucion es sumar todo por cada vertice que pertenece al ciclo.

Por propositos educativos, halle los vertices que pertenecen al ciclo. El editorial utiliza otra forma de resolver el ejercicio
mas facil. Calculan contv con un queue, sumando 1 por cada leaf en el cycle y eliminando los vetcies hasta que solo quedan
los vertices que pertenecen al cycle.

Metodo de colores (hallar los vertices que pertenecen al ciclo, utilizando un parent array y colores array)
*/
class Solution {
public:
    int n;
    vector<int>cycleNodes;
    vector<int> isCycle;
    vector<int> parent;
    vector<int> colors;
    vector<int> countSize;
    Solution(int n) {
        this->n = n;
      /*  this->parent.clear();
        this->colors.clear();
        this->cycleNodes.clear();
        this->isCycle.clear();
        this->countSize.clear();*/
        this->parent.resize(n+5);
        this->colors.resize(n+5, 0);
        this->isCycle.resize(n+5, 0);
        this->countSize.resize(n+5, 0);
    }

    void dfs_cycle(vector<int> adj[], int u,int p)// O(N)
    {
        if (colors[u] == 2)
        {
            return;
        }
        if (colors[u] == 1)
        {
            int current = p;
            cycleNodes.push_back(current);
            isCycle[current] = 1;
            while (u != current)
            {
                current = parent[current];
                cycleNodes.push_back(current);
                isCycle[current] = 1;
            }
            return;
        }
        parent[u] = p;
        colors[u] = 1;
        for (auto x: adj[u])
        {
            if (x == parent[u]) continue;
            dfs_cycle(adj,x,u);
        }
        colors[u] = 2;
    }
    void printCycleNodes()
    {
        cout << cycleNodes.size() << '\n';
        for (auto x: cycleNodes)
            cout << x << " ";
        cout << '\n';

    }
    void dfs_size(vector<int> adj[],int u, int p)
    {
        countSize[u] = 1;
        for (auto x: adj[u])// O(N)
        {
            if (x == p || isCycle[x] == 1) continue;
            dfs_size(adj,x,u);
            countSize[u] += countSize[x];
        }
    }
    void sol(vector<int> adj[])
    {
        ll ans = 0;
        for (auto x : cycleNodes) // O(k*contV)  ~= N
        {
            dfs_size(adj,x,0);
            int contv = countSize[x];
            ll  tree_paths = (ll) contv * (contv-1) / 2;
            ll outside_paths = (ll) contv * (n - contv);
            ans += (tree_paths + outside_paths);
        }
        cout << ans << '\n';
    }
};

int main()
{
    send help
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> adj[n+5];
        for (int i = 0; i < n; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj(n);
        obj.dfs_cycle(adj,1,0);
        obj.sol(adj);
    }
    return 0;
}
