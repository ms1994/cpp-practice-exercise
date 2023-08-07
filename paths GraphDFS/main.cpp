#include <bits/stdc++.h>

using namespace std;

class Solution
{

    set <int> gov;
public:
    int pathAdds()//pudiera funcionar el problema es que construyo toda la grafica
    //y en el peor de los caso la grafica contendria 100000*99999/2 edges
    //mas de un billon de datos por lo que supera la cantidad de memoria necesaria
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> adj[n+1];
        int paths = 0;
        while (k--)
        {
            int ki;
            cin >> ki;
            gov.insert(ki);
        }
        for (int i = 0; i<m; i++)
        {
            int x,y;
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for (int i = 1; i <=n; i++)
        {
            int number1, number2;
            if (gov.count(i)) number1 = i;
            else number1 = dfs(i,0,0,adj);
            for (int j = i+1; j <= n; j++)
            {
                int check = dfs(j,i,0,adj);
                if (check == -1) continue;
                number2 = gov.count(j)==1 ? j: dfs(j,i,0,adj);
                if (number1 == 0 || number2 == 0 || number1 == number2)
                {
                    paths++;
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        return paths;
    }
    int dfs(int s, int i, int p, vector<int> adj[])
    {
        int answer = 0;
        for (auto x: adj[s])
        {
            if (x == i) return -1;
            if (!answer)
            {
                if (x == p && !gov.count(x)) continue;
                answer = gov.count(x)==1 ? x: dfs(x,0,s,adj);
            }
        }
        return answer;
    }
};

int main()
{
    Solution obj;
    cout << obj.pathAdds()<<endl;
    return 0;
}
