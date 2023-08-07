#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <cctype>
#include <sstream>
#include <cassert>
#include <bitset>
#include <memory.h>
#include <complex>

using namespace std;

#pragma comment(linker, "/STACK:200000000")

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define fore(i, a, n) for(int i = (int)(a); i < (int)(n); i++)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) (int(a.size()) - 1)
#define all(a) a.begin(), a.end()

const double EPS = 1E-9;
const int INF = 1000000000;
const int64 INF64 = (int64) 1E18;
const double PI = 3.1415926535897932384626433832795;

int a[110], n, n2, s, b[10][10];
bool u[110];

bool check() {
    {
        int sum = 0;
        forn(i, n)
            sum += b[i][i];
        if (sum != s)
            return false;
    }
    return true;
}

bool bad_col(int x, int y) {//su funcion es asegurar que los valores intermedios de la col, su sumatoria sea menor a S
    if (x == 0)//primera fila todos los valores pueden ir
        return false;
    int sum = 0;
    forn(i, x + 1)//x + 1 por que empieza desde cero sin tocar el valor de x, por eso el mas 1
        sum += b[i][y];//sumatoria del valor de la columna
    if (x == n - 3)//caso para n = 4
        forn(i, n2)
            if (!u[i])//check si el valor no lo he utilizado ya, la posicion
                forn(j, i)
                    if (!u[j] && s - sum == a[i] + a[j])//dos valores que su suma sea menor a S, si ese valor no se ha
                        return false;//encontrado lo busco
    if (x == n - 2)//el primer valor de n = 3, el segundo para n = 4
        forn(i, n2)
            if (!u[i] && s - sum == a[i])//buscoo especificamente un valor menor a S
                return false;
    if (x < n - 3)
        return false;//si ya ese valor esta seleccionado en la col
    return true;
}

void rec(int x, int y) {
    if (x == n - 1 && y == 1) {//evalua la diagonal secundaria
        int sum = 0;//si es igual a s
        forn(i, n)
            sum += b[i][n - i - 1];
        if (sum != s)
            return;
    }
    if (x == n - 1 && y) {//evalua la suma de columnas
        int sum = 0;//si la col es igual a s
        forn(i, n)
            sum += b[i][y - 1];
        if (sum != s)
            return;
    }
    if (x < n - 1 && y)
        if (bad_col(x, y - 1))//evalua las columnas antes de llegar a la ultima fila
            return;//si bad col es true busca otro valor, si es false me aseguro que la suma de los valores es
            //menor a S

    if (x == n) {
        if (!check()//la diagonal principal), si es falso busco otro valor
            return;
        forn(i, n) {
            forn(j, n)
                printf("%d ", b[i][j]);
            puts("");//cierro todo y print la matriz se supone que al llegar aqui valido todo lo de arriba
        }
        exit(0);
    }
    if (y == n) {
        int sum = 0;
        forn(i, n)
            sum += b[x][i];//verifico las row
        if (sum != s)
            return;
        return rec(x + 1, 0);//una row lista busco la otra
    }

    int last = INF;
    forn(i, n2)//backstracking de todos los valores
        if (!u[i] && last != a[i]) {
            last = a[i];
            u[i] = true;
            b[x][y] = a[i];
            rec(x, y + 1);//empiezo de derecha a izquierda llenado las row luego las col
            u[i] = false;
        }
}

int main() {
#ifdef RADs_project
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    cin >> n;
    n2 = n * n;
    forn(i, n2)
        cin >> a[i];
    sort(a, a + n2);

    forn(i, n2)
        s += a[i];
    s /= n;

    printf("%d\n", s);

    rec(0, 0);

    return 0;
}
