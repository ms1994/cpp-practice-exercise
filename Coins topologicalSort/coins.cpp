#include <bits/stdc++.h>

using namespace std;

class Solution {
    stack <int> sta;
    vector <int> adj[3];
    vector <int> tsort;
    bool visited[3] = {false, false, false};
    map <char, int> m1 = {{'A', 0}, {'B', 1}, {'C', 2}};
    map <int, char> m2 = {{0,'A'}, {1, 'B'}, {2,'C'}};
    public:
    void coinsSol()
    {
         for (int i = 0; i < 3; i++)
        {
            string s;
            cin >> s;
            if (s[1] == '>') adj[m1[s[2]]].push_back(m1[s[0]]);
            else adj[m1[s[0]]].push_back(m1[s[2]]);
        }
        for (int i = 0; i < 3; i++)
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
    }
    void dfs (int s, bool visited[], vector <int> adj[], stack <int> &sta)
    {
        if (visited[s]) return;
        visited[s] = true;
        for (auto it: adj[s])
            dfs(it, visited, adj, sta);
        sta.push(s);
    }
     bool cycle (stack <int> &sta, vector <int> &tsort, vector <int> adj[])
    {
        int pos = 0;
        map <int, int> control;
        while (!sta.empty()) {
            control[sta.top()] = pos++;//
            tsort.push_back(sta.top());
            sta.pop();
        }
        for (int i = 0; i < 3; i++)
        {
            for (auto it: adj[i])
            {
                if (control[i] > control[it])
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    Solution obj;
    obj.coinsSol();

}
