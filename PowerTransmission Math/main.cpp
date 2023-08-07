#include <bits/stdc++.h>
using namespace std;
//this solution is from Galen Colin.

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;

/*
Mi sol no esta mal, pero falta remover las rectas que son iguales, más no las rectas paralelas, para eso
se hace Max comun divisor entre los valores a, b y c. (editorial), y se cuenta normal, como lo estaba
haciendo, contar las rectas que se intersectan, restandole las rectas que son paralelas.

la recta se construye con la ec ax - by = c
donde a = delta y (entre 2 puntos)
b = delta x (entre dos puntos)
puedes deducir esta formula desde la ecu de la recta con dos puntos y = mx + c; m = a / b;

cuando haces gcd entre los valores a y b de la recta, lo llevas hasta su min expresion;
si dos rectas son iguales, entonces cuando calcules el termino c, te dara el mismo valor
si son parelelas el termino c sera distinto. Con eso en mente puedes hacer el filtro entre
las rectas que son paralelas y las que son iguales.

En la editorial usaron un map con un pair como key, el pair son los valores a y b;
mientras que el value era un set, donde guardabas el valor de c y ves si c ya se habia calculado o nó.

REVISAR LA ECUACION DE C, MI SOL NO PASABA PORQUE EL AUTOR TOMABA C COMO AX-BY, MIENTRAS QUE YO TOMABA C COMO
AX+BY; EL ERROR DE MI CODIGO FUE NO SABER CALCULAR EL PUNTO DE CORTE CON EL EJE Y. (TERMINO C)
PUDE HABER USADO LA EQ Y = MX + B, CALCULANDO LA PENDIENTE Y DANDOLE UN VALOR A C = X[I] CUANDO A = 0;
Y LO OTRO ERA USAR LA PENDIENTE Y EL PUNTO DE CORTE PARA FILTRAR LAS DISTINTAS RECTAS, ELIMINANDO LAS RECTAS IGUALES.
EL MEJOR USAR EL SLOPE COMO LO HICE LA PRIMERA VEZ Y CALCULAR C COMO C= Y-MX; Y YA.
CON ESO HUBIERA FUNCIONADO BIEN MI CODIGO ANTERIOR.

PARA TRABAJAR CON LA SLOPE Y EVITAR LOS PROBLEMAS CON X = 0, SE ASGNA UN VALOR INF AL M Y C = X[I].
Y EL M SI PUEDE TRABAJAR ASÍ NORMALMENTE, EN MI PREVIOUS CODE FALTO USAR EL C PARA FILTRAR LAS RECTAS.

*/
#define PI 3.14159265
struct point {
    int x;
    int y;

};

int gcd(int a, int b)
{
    if (a == 0) return b;
    return gcd(b % a, a);
}

int main()
{
    send help
    int n;
    cin >> n;
    vector<point> pts(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pts[i].x >> pts[i].y;
    }
    map <pair <int,int>,ll> pend;
    map<pair <int,int>, set<ll>> control;
    vector<pair <int,int>> pend_total;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int a =  pts[i].y - pts[j].y;
            int b =  pts[i].x - pts[j].x;
            if (a < 0 || (a == 0 && b < 0))
            {
                a = -1 * a;
                b = -1 * b;
            }
            int d = gcd(a,b);
            a /= d, b /= d;
            ll c = 1LL * a*pts[i].x - 1LL*b*pts[i].y;
            //double m = b == 0 ? (double) 90 : (double) atan(a / b) * 180/PI;//puedes calcular la pendiente pero para saber si son iguales dos rectas debes calcular el C
            //llevar a y b a su minima expresion usando GCD, luego ver como contar todos los puntos intercepción.
            //Primer problema por usar m, si lo llevamos a grados, si los numeros son muy grandes y la diferencia es solo una unidad
            //la m te dira que son iguales aunque no lo sean, debido a un error de aproximación, la funcion atan.
            // segundo debes transformar cada miembro de operacion en C en LL para mayor precision.
            pair <int, int> m = make_pair(a,b);
            if (!control[m].count(c))
            {
                pend_total.push_back(m);
                pend[m]++;//por el mismo problema de arriba cuando la diferencia de scope es solo 1 unidad los calculos los toma
                control[m].insert(c);//como si fueran los mismos, a pesar de tener diferente punto de corte
            }
        }
    }
    sort(pend_total.begin(), pend_total.end());
    ll total = pend_total.size();
    ll ans = 0;
    for (int i = 0; i < total; i++)
    {
        ll intersection = total - (i+1);
        ll correction = intersection - (--pend[pend_total[i]]);
        ans += correction;

    }
    cout << ans << endl;
    return 0;
}
