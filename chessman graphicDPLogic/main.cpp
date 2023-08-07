#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    string chessboard[n];
    for (int i = 0; i < n; i++)
    {
        string symbol;
        cin >> symbol;
        chessboard[i] = symbol;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (chessboard[i][j] == '.')
            {
                if ( (i + j) % 2 == 0) chessboard[i][j] = 'B';
                else chessboard[i][j] = 'W';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << chessboard[i][j];
        }
        cout << '\n';
    }
    return 0;
}
