#include <bits/stdc++.h>
using namespace std;
//this solution is from Galen Colin.

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
/*
Intente hacerlo por BF usando un greedy aproach, intentando contar todos los valores, pero esto no funciono.

La solucion es ver el problema como un chess table, es decir "Pintar" cada cuadro de negro y blanco. Como es un domino
la solución será el pair negro con blanco. es decir hay que contar cuantos negros y cuantos blancos hay, y hacer que ambos
sean iguales y esa es la solucion.

El algoritmo lo que hara sera contar los cuadros negros y los blancos. El min valor entre los dos sera la solucion
porque los mayores a el minimo no tinen pareja por lo que quedaran solos.

*/
ll solution(int n, vector<int> &cols); //My first solution and don't work.

ll countBlackAndWhite(int n, vector<int> & cols);


int main()
{
    send help
    int n;
    cin >> n;
    vector<int> cols(n+1);
    for (int i = 0; i < n; i++)
    {
        cin >> cols[i];
    }
    long long ans = countBlackAndWhite(n,cols);
    cout << ans << endl;
    return 0;
}

ll countBlackAndWhite(int n, vector<int> & cols)
{
    ll black = 0;
    ll white = 0;
    for (int i = 0; i < n; i++)
    {
        ll aux = (cols[i]/2 + (cols[i] % 2));
        if (i % 2 == 0)
        {
            white += aux;
            black += (cols[i] - aux);
        }
        else
        {
            black += aux;
            white += (cols[i] - aux);
        }
    }
    //cout << "white: " << white << " black: " << black << endl;
    return min(black, white);
}

long long solution(int n, vector<int> &cols)
{
    long long ans = 0;
    ans += cols[0] / 2;
    int isLeft = cols[0] % 2;
    int hor, vert, freeUp = 0;
    for (int i = 1; i < n; i++)
    {
        hor = 0;
        vert = 0;
        if (isLeft && !freeUp)
        {
            hor = 1;
            int aux = cols[i] - 1;
            vert = aux / 2;
            isLeft = aux % 2;
            freeUp = isLeft ? 1 : 0;
        }
        else if (freeUp && cols[i] == cols[i-1])
        {
            hor = 1;
            int aux = cols[i] - 1;
            vert = aux / 2;
            isLeft = aux % 2;
            freeUp = 0;
        }
        else if (freeUp && cols[i]< cols[i-1])
        {
                freeUp = 0;
                vert = cols[i] / 2;
                isLeft = cols[i] % 2;
        }
        else
        {
            vert = cols[i] / 2;
            isLeft = cols[i] % 2;
        }
        ans += (long long) (hor + vert);
    }
    return ans;
}
