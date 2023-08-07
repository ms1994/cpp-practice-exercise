#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dfs (int s, bool visited[], vector <int> adj[], stack <int> &sta);
bool cycle (stack <int> &sta, vector <int> &tsort, vector <int> adj[]);
int main()
{
    stack <int> sta;
    vector <int> adj[3];
    vector <int> tsort;
    bool visited[] = {false, false, false};
    map <char, int> m1 = {{'A', 0}, {'B', 1}, {'C', 2}};
    map <int, char> m2 = {{0,'A'}, {1, 'B'}, {2,'C'}};
    for (int i = 0; i < 3; i++)// CREAR LA ADJ LIST
    {
        string s;
        cin >> s; //EL SECRETO ES COLOCAR EL MENOR ANTES DEL MAYOR (SEGUN EL PROBLEMA) A>B
        if (s[1] == '>') adj[m1[s[2]]].push_back(m1[s[0]]);
        else adj[m1[s[0]]].push_back(m1[s[2]]);
    }
    for (int i = 0; i < 3; i++) //CODIGO PARA REALIZAR LA TOPOLOGICAL SORT EN TODOS LOS VERTICES/NODOS CON UN DFS
    {
        if (!visited[i]) dfs(i, visited, adj, sta);
    }
    bool resp = cycle(sta, tsort, adj);
    if (resp) cout << "Impossible" << endl;
    else
    {
        for (auto it : tsort)
            cout << m2[it];
    }
    /* while (!sta.empty()) { // SE GUARDAN LOS VALORES EN UN DATA STRUCTURE STACK Y SE PRINT DESDE ARRIBA HACIA ABAJP
        cout << sta.top();
        sta.pop();
    }*/

    return 0;
}



  void dfs (int s, bool visited[], vector <int> adj[], stack <int> &sta)
    {
        if (visited[s]) return;
        visited[s] = true;
        for (auto it: adj[s])
            dfs(it, visited, adj, sta);
        sta.push(s);//LA DIFERENCIA ENTRE EL DFS NORMAL Y EL TOPOLOGICAL SORT
    }

    bool cycle (stack <int> &sta, vector <int> &tsort, vector <int> adj[])
    {
        int pos = 0;
        map <int, int> control;
        while (!sta.empty()) { // SE GUARDAN LOS VALORES EN UN DATA STRUCTURE STACK Y SE PRINT DESDE ARRIBA HACIA ABAJP
            control[sta.top()] = pos++;//
            tsort.push_back(sta.top());
            sta.pop();
        }
        for (int i = 0; i < 3; i++)
        {
            for (auto it: adj[i]) //los padres(i) deben tener un menor valor que los hijos (it)
            {//se compara con el adj que es el que contiene la informacion de la grafica
                if (control[i] > control[it])
                    return true;
            }
        }
        return false;
    }

