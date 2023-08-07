#include <bits/stdc++.h>
using namespace std;

class Solution
{
 public:
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
}
