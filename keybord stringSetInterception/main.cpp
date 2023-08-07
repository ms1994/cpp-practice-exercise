#include <bits/stdc++.h>

using namespace std; //brutal force n*k si se puede y el overflow se resuelve con esas lineas del debug

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;
    string s;
    vector <char> c;
    cin >> s;
    for (int i = 0; i < k; i++)
    {
        char ck;
        cin >> ck;
        c.push_back(ck);
    }
    int i = 0;
    long long answer = 0;
    int cont = 0;
    while (i < n)
    {
        for (int j = 0; j < k; j++)
        {
            if (s[i] == c[j])
            {
                cont++;
                i++;
                j = -1; //causa un retraso por tener que repetir el ciclo muschas veces
                if (i == n) break;
            }//por eso el otro codigo es mas limpio y rapido
        }
        if (cont > 0)
        {
            answer += cont * 1ll * (cont + 1) / 2;
            cont = 0;
        }
        i++;
    }
        cout << answer <<endl;
}
