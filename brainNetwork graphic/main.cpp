#include <bits/stdc++.h>

using namespace std;
class BrainNetwork
{
public:
    void diameter()
    {
        int n,m;
        cin >> n >> m;
        vector <int> adj[n+1];
        for (int i = 0; i < m; i++)
        {
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //int node = dfsNode(1,0,adj);
        pair <int, int> answer = dfsDistance(1,0,0,adj);
        answer = dfsDistance(answer.first,0,0,adj);
        cout << answer.second  << endl;
    }
    int dfsNode(int s, int parent, vector <int> adj[])//no es necesaria
    {
        int node = 0;
        int maxLen = 0;
        for (auto u: adj[s])
        {
            if (u==parent) continue;
            pair <int, int> temp = dfsDistance(u,s,1, adj);
            if (temp.second > maxLen)
            {
                maxLen =  temp.second;
                node = temp.first;
            }
        }
        return !node ? s : node;
    }
    pair <int,int> dfsDistance(int s, int p, int dist, vector <int> adj[])
    {
        int cont = dist + 1;
        int maxLen = dist;
        int node = s;
        for (auto u: adj[s])
        {
            if (u==p) continue;
            pair <int, int> temp  = dfsDistance(u,s,cont,adj);
            if (temp.second > maxLen)
            {
                maxLen = temp.second;
                node = temp.first;
            }
        }
        return make_pair(node,maxLen);
    }
};
int main()
{
    /*int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
    }
    if (m != n-1) cout << "no" << endl;
    //dfs para ver que todos los componentes esten conectados*/

    BrainNetwork obj;
    obj.diameter();
    return 0;
}
