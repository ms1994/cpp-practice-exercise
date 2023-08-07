#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector <int> possible;
public:
    void itRestaurants()
    {
        int n;
        cin >> n;
        vector <int> adj[n+1];
        possible.resize(n+1);
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,0,adj, n);
        int cont = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (possible[i]) cont++;
        }
        cout << cont << endl;
        for (int i = 1; i < n-1; i++)
        {
            if (possible[i]) cout << i << " "<< n - 1 -i << endl;
        }

    }
    int dfs(int s, int e, vector <int> adj[], int n)
    {
        int sizeNode = 1;
        vector <int> sizeAdjSubtrees;
        for (auto u: adj[s])
        {
            if (u == e) continue;
            int temp = dfs(u,s,adj,n);
            sizeNode += temp;
            sizeAdjSubtrees.push_back(temp);
        }

        if (!sizeAdjSubtrees.empty()) //evalua solo los nodos con hijos, es decir ignora las hojas
        {
            if (e != 0) //no es la root
            {
                int sizeParentTree = n - sizeNode;
                sizeAdjSubtrees.push_back(sizeParentTree);
            }
            //implement knapsack con el subset formado con los
            //tamaños del subtree
            vector <bool> local;
            for (int i = 0; i <= n; i++) local.push_back(false);
            local[0] = true;

            for (auto k:sizeAdjSubtrees)//desde los valores corresponientes al peso k, en este caso el
                //size de los suntrees
            {
                for (int x = n - 1; x >= 0; x--)//el x puede empezar desde la suma total de todo los sizes hasta o el maximo posible
             //hay que contar el 0 para que funcione
                {
                    if (local[x])
                    {
                        local[x + k] = true;
                        possible[x + k] = true;
                    }
                }
            }
        }

        return sizeNode;
    }
};

int main()
{
    Solution obj;
    obj.itRestaurants();
    return 0;
}
