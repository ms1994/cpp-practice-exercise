#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
 public:
    bool dfs (int s, bool visited[], vector <int> adj[], int parent)//devuelve verdadero o falso si hay un ciclo
     //o porque visito un nodo dos veces y el nodo obj es distinto al parent.
    {
        visited[s] = true;
        for (auto it: adj[s])//funcion para conseguir ciclos pero lo que necesitp es e
            //ver si puedo volver al mismo nodo
        {
            if (!visited[it])
            {
                if (dfs(it, visited, adj, s)) return true;
            }
            else if (s != parent) return true;
        }
        return false;
    }
    int countSnake()
    {
        int n;
        scanf("%d", &n);
        bool visited[n];
        int cont = 0;
        vector <int> adj[n];
        string s;
        cin >> s;
        for (size_t i = 0; i < s.length(); i++)
        {
            int next = (i+1) % n;
            switch(s[i])
            {
            case '-':
                if (find(adj[i].begin(), adj[i].end(), next) == adj[i].end()) adj[i].push_back(next);
                if (find(adj[next].begin(), adj[next].end(), i) == adj[next].end()) adj[next].push_back(i);
                break;
            case '<':
                if (find(adj[next].begin(), adj[next].end(), i) == adj[next].end()) adj[next].push_back(i);
                break;
            case '>':
                if (find(adj[i].begin(), adj[i].end(), next) == adj[i].end()) adj[i].push_back(next);
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            initialBool(visited, n);
            if (dfs(i,visited,adj,-1))
            {
                cont++;
            }
        }
        return cont;
    }
    int cycleRoom()
    {

        int n;
        scanf("%d", &n);
        bool visited[n];
        int cont = 0;
        set <int> adj[n];
        string s;
        cin >> s;
        for (size_t i = 0; i < s.length(); i++)
        {
            int next = (i+1) % n;
            switch(s[i])
            {
            case '-':
                adj[i].insert(next);
                adj[next].insert(i);
                break;
            case '<':
                adj[next].insert(i);
                break;
            case '>':
                adj[i].insert(next);
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            int next = (i+1) % n;
            int prev = i == 0 ? n - 1:i - 1;
            if (adj[i].empty()) cont++;
            else if (adj[next].find(i) == adj[next].end() && adj[prev].find(i) == adj[prev].end()) cont++;
        }
        return n - cont;
    }

    void initialBool(bool visited[], int n)
    {
        for (int i = 0; i < n; i++)
            if (visited[i])
                visited[i] = false;
    }
};


int main()
{
    int t;
    cin >> t;
    Solution obj;
    while (t--)
    {
        cout << obj.cycleRoom() << endl;
    }
    return 0;
}
