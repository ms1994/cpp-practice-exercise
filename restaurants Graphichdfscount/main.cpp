#include <bits/stdc++.h>

using namespace std;

class Solution
{
    vector <int> contV;
public:
    void itRestaurants()
    {
        int n;
        cin >> n;
        vector <int> adj[n+1];
        contV.resize(n+1);
        set <pair <int,int>> response;
        for (int i = 0; i < n - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        dfs(1,0,adj);
        for (int i = 1; i <= n; i++)
        {
            if (contV[i] == n || contV[i] - 1 == 0) continue;
            int a = contV[i] -1;
            int b = n - 1 - a;
            response.insert(make_pair(a,b));
            response.insert(make_pair(b,a));
        }
        if (response.size() == 0)
        {
            for (int i = 1; i <= n; i++)
            {
                if (contV[i] == 1) continue;
                for(int j = 1; j < contV[i] - 1; j++)
                {
                    response.insert(make_pair(j,n-j-1));
                    response.insert(make_pair(n-1-j,j));
                }
            }
        }
        cout << response.size() << '\n';
        for (auto x: response)
        {
            cout << x.first << " " << x.second << endl;
        }
    }
    void dfs(int s, int e, vector <int> adj[])
    {
        contV[s] = 1;
        for (auto u: adj[s])
        {
            if (u == e) continue;
            dfs(u,s,adj);
            contV[s] += contV[u];
        }
        return;
    }
};

int main()
{
    Solution obj;
    obj.itRestaurants();
    return 0;
}
