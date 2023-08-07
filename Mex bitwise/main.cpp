#include <bits/stdc++.h>

using namespace std;

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

long long MEX(int n, int m);

/* la logica esta casi bien pero el time complexity de N no es suficiente
    cuando son bitwise de max o min algo por lo general se estudia el primer bit del numero
    en la solucion se busca construir la respuesta bit a bit tomando el cuenta el XOR de n y m
    como answer tine que ser un numero k que con XOR de N sea mayor o igual a M, por eso tomamos un numero
    p >= m + 1, y construimos el numero k bit a bit con ayuda de N y P, de la sig manera:
    1. Si el bit Pi es uno y el de N es cero, para que el xor de N^K =P, el bit de K debe ser 1 porque N^k = Pi
    2. Si el bit Pi es uno y el de N es uno, entonces Ki debe ser 0, para que N^k = Pi.
    3. Si el bit Pi es cero y el bit N es uno, simboliza que ya N es mayor a P por lo que podemos poner ese Ki como
    0 junto con el resto de los bits, porque N siempre sera mayor a P.*/

int main()
{
    send help
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        cout << MEX(n,m) << '\n';
    }
}

long long MEX(int n, int m)
{
    if (n > m) return 0;
    if (n == 0) return m + 1;
    long long p = m + 1;
    long long ans = 0;
    for (long long i = 31; i>=0; i--)
    {
        if (p&(1<<i))
        {
            if (!(n&(1<<i)))
            {
                ans += (1<<i);
            }
        }
        else if (n&(1<<i)) break;
    }
    //falta por hacer.
    return ans;
}
