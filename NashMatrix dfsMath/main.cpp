#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
int visited[1010][1010];
int reach[1010][1010];
pair <int,int> dashboard[1010][1010];
int sol[1010][1010];
vector<pair <int,int>> nodes[1010][1010];
/*
    Tendría que hacer al menos 3 dfs uno para los componentes conectados con una casilla fija, otro para los
    componentes conectados con una casilla de -1,-1, y el ultimo dfs para conectar componentes sueltos con los -1,-1
    o con los componentes fijos.

    Preguntar si el reach cuando es negativo, hay componentes a su lado que tenga reach true, si los tiene ver
    si se pueden conectar.

    Mi dfs esta bien, luego del refactoring desde el sol = 5, esta mal era el calculo de los
    infinities. Ver los valores para cambiar lo que haya que cambiar.
    Refactorizar check_connection.

*/


void generate_nodes(int n)
{
    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            if (i - 1 > 0)
            {
                nodes[i][j].push_back(make_pair(i-1, j));
            }
            if (i + 1 <= n)
            {
                nodes[i][j].push_back(make_pair(i+1, j));
            }
            if (j - 1 > 0)
            {
                nodes[i][j].push_back(make_pair(i, j-1));
            }
            if (j + 1 <= n)
            {
                nodes[i][j].push_back(make_pair(i, j+1));
            }
        }
    }
}
//buscalo para los valores distintos a -1,-1

//revisar dfs.

void generate_sol(int row, int col, int row2, int col2)
{
    if (col == col2)
    {
        if (row > row2)
        {
            sol[row2][col2] = 2;
        }
        else if (row < row2)
        {
            sol[row2][col2] = 1;
        }
    }
    if (row == row2)
    {
        if (col > col2)
        {
            sol[row2][col2] = 4;
        }
        else if (col < col2)
        {
            sol[row2][col2] = 3;
        }
    }
}

void dfs(int row, int col)
{
    visited[row][col] = 1;
    pair <int, int> finish = dashboard[row][col];
    if (finish.first == row & finish.second == col)
    {
        sol[row][col] = 5;
        reach[row][col] = 1;
    }
    for (auto pr : nodes[row][col])
    {
        if (visited[pr.first][pr.second]) continue;
        if (dashboard[pr.first][pr.second]  == finish && pr != make_pair(-1, -1))
        {
            dfs(pr.first,pr.second);
            reach[pr.first][pr.second] = 1;
            generate_sol(row,col,pr.first,pr.second);
        }
    }
    return;
}
//or check_connection
bool check_connection(int row, int col, int n)
{
    visited[row][col] = 1;
    pair <int, int> finish = dashboard[row][col];
    bool is_infinity = false;
    if (row - 1 > 0)
    {
        if (dashboard[row-1][col] == finish )
        {
            reach[row-1][col]  = 1;
            visited[row-1][col] = 1;
            sol[row][col] = 1;
            sol[row-1][col] = 2;
            //aqui va el dashborad sol
            return true;
        }

    }
    if (row + 1 <= n)
    {
        if (dashboard[row + 1][col] == finish)
        {
            reach[row+1][col]  = 1;
            visited[row+1][col]  = 1;
            sol[row][col] = 2;
            sol[row+1][col] = 1;
            return true;
        }
    }
    if (col - 1 > 0)
    {
        if (dashboard[row][col - 1] == finish)
        {
            reach[row][col - 1]  = 1;
            visited[row][col - 1]  = 1;
            sol[row][col] = 3;
            sol[row][col-1] = 4;
            return true;
        }
    }
    if (col + 1 <= n)
    {
        if (dashboard[row][col + 1] == finish)
        {
            reach[row][col - 1]  = 1;
            visited[row][col - 1]  = 1;
            sol[row][col] = 4;
            sol[row][col+1] = 3;
            return true;
        }
    }
    return is_infinity;
}

bool connect(int row,int col,int row2,int col2,int value,int value2)
{
	if(dashboard[row2][col2] == make_pair(-1,-1))
	{
		sol[row][col] =  value;
		reach[row][col] = 1;
		visited[row][col] = 1;
		if(sol[row2][col2] == 0)
		{
		  sol[row2][col2] = value2;
		  reach[row2][col2] = 1;
		  visited[row2][col2] = 1;
		}
		return 1;
	}
	else
		return 0;
}

int main()
{
    send help
    //auto start = high_resolution_clock::now();
    int n;
    cin >> n;
    generate_nodes(n);
    map<int, char> guide {
        {1, 'U'},
        {2, 'D'},
        {3, 'L'},
        {4, 'R'},
        {5, 'X'}
    };
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            int u,v;
            cin >> u >> v;
            dashboard[i][j] = make_pair(u,v);
        }
    }
    //auto stop = high_resolution_clock::now();
    //auto duration = duration_cast<milliseconds>(stop - start);
    //cout << duration.count() << endl;
    bool is_valid = true;
    bool infinity_check = true;
    for (int i = 1; i <= n; i++)
    {
        if (!is_valid) break;
        for (int j = 1; j <=n; j++)
        {
            if (!visited[i][j])
            {
                if (dashboard[i][j] != make_pair(-1, -1))
                {
                    if (dashboard[i][j] == make_pair(i,j))
                        dfs(i,j);
                }
                else {
                    infinity_check = (sol[i][j] != 0);
                    if (!infinity_check) infinity_check = connect(i,j,i+1,j,2,1);
                    if (!infinity_check) infinity_check = connect(i,j,i,j+1,4,3);
                    if (!infinity_check) infinity_check = connect(i,j,i-1,j,1,2);
                    if (!infinity_check) infinity_check = connect(i,j,i,j-1,3,4);
                }
                if (!infinity_check)
                {
                    is_valid = false;
                    break;
                }
            }
        }
    }
    if (!is_valid)
    {
        puts("INVALID");
    }
    else {
        bool is_connect = true;
        for (int i = 1; i <=n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                 if (!reach[i][j]) is_connect = false;
            }
        }
        if (!is_connect)
        {
            puts("INVALID");
        }
        else {
            cout << "VALID" << '\n';
            for (int i = 1; i <=n; i++)
            {
                for (int j = 1; j <=n; j++)
                {
                    cout << guide[sol[i][j]];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
