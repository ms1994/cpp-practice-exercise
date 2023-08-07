#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string j)
    {
        string lowerWord;
        for (int m = 0; m < j.length(); m++)
        {
            lowerWord += tolower(j[m]);
        }
        return lowerWord;
    }
    int repostMaxChain ()
    {
        unordered_map <string, int> names;
        int n;
        cin >> n;
        int id = 0;
        vector <int> adj[2*n];
        bool visited[2*n];
        queue <int> q;
        for (int i=0; i < 2*n; i++)
            visited[i] = false;
        for (int i = 0; i < n; i++){
            string j, reposts, k;
            cin >> j >> reposts >> k;
            string name1 = toLowerCase(j);
            string name2 = toLowerCase(k);
            if (!names.count(name1)) names[name1] = id++;
            if (!names.count(name2)) names[name2] = id++;
            adj[names[name2]].push_back(names[name1]);
            q.push(names[name2]);
    }
        int sol = bfs(names["polycarp"], n, adj, visited, q);
        return sol;

    }
    int bfs(int x,int n, vector <int> adj[], bool visited[], queue <int> q)//earching and distance
    {                                                                      //from choose node to node
        int distance[2*n];
        visited[x] = true;
        for (int i = 0; i < 2*n; i++)
            distance[i] = 0;
        q.push(x);
        int maxV = 0;
        while (!q.empty())
        {
            int s = q.front(); q.pop();
            for (auto u : adj[s])
            {
                if (visited[u]) continue;
                visited[u] = true;
                distance[u] = distance[s] + 1;
                q.push(u);
            }
        }
        for (int i = 0; i < 2*n; i++)
        {
            if (maxV < distance[i]) maxV = distance[i];
        }
        return maxV+1;

    }


    void dfs (int s, bool visited[], int cont, vector <int> adj[]) // no me sirve para hallar la distancia
    {//buscar por todos los nodos conectados a "s"; deepth search
        if (visited[s]) return;
        visited[s] = true;
        cont++;
        for (auto it: adj[s])
            dfs(it, visited, cont, adj);
    }
};

int main()
{
    Solution obj;
    cout << obj.repostMaxChain() << endl;
}

