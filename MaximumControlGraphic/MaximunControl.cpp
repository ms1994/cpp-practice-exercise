#include <vector>
#include <iostream>

int maximumControl();
int main()
{
    int result = maximumControl();
    std::cout << result << '\n';

}
int maximumControl()
{
    int N, u, v;
    int cont = 0;
    std::cin >> N;
    std::vector <int> adj[N + 1];
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= N; i++)
    {
        for (auto it : adj[i])
        {
            if (adj[i].size() == 1) cont++;
        }
    }
    return cont;
}
