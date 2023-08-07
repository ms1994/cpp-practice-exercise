#include <bits/stdc++.h>
using namespace std;


#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
/*
Se utiliza el kadane algoritmo.

El kadane algoritmo trata de encontrar el mayor suma de sub array posible (Max sumArray problem)
 en un tiempo de O(N) y un espacio O(N) (Optimal solucion)

 El editorial muestra una solucion O(n*30);

 pruebas todos los numeros desde 1 hasta 30, usas el kardena para obtener el max valor de un sub array, y le restas ese
 valor de i, este algoritmo funciona de forma que los valores >= a i sean considerados como infinito. por exm

 i = 20

 1 2 4 -5 18 22 6 4 6 0 -3 23 3 5 6;

 divide el array como 1 2 4 -5 18, antes de valor mayor a i
 b = 6 4 6 0 -3 y c =  3 5 6;

 la solucion sera el max valor entre ellos al haber restado ese i;

 se calcula el kadena entre esos array y se resta i al final de cada valor, no te preocupes si el i no esta presente
 en ese segmento, porque el programa iterara por todas las posibles soluciones y cuando toque el valor elegido
 la respuesta sera el max entre todos los valores y al final el valor real sera la solucion porque el max valor
 dentro del subarray tiene que ser siempre <=i
 ejemplo max sum c = 14, si i = 20 resp = -6
 i = 21 resp = -7 y asi
 pero cuando i = 7 resp = 7
 i = 6 resp = 8;
 para i = 5, ya cambia la composicion de c ha = 3 5, el 6 no perteneceria al array c por ser mayor a i

 es como probar todas las particiones a partir de cierto numero.

 Nota: mi codigo es una combinacion de kadena algoritmo y eliminando el elemento, un algoritmo busca el valor del kadene
 entre segmentos y otro entre el total array, y combina ambas respuesta. No tiene mucha logica, fue hecho entre el
 ensayo y el error. Cosa que esta mal hecha

 CODIGO DEL EDITORIAL

 int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	forn(i, n) scanf("%d", &a[i]);
	long long ans = 0;
	forn(mx, 31){
		long long cur = 0;
		long long best = 0;
		forn(i, n){
			int val = (a[i] > mx ? -INF : a[i]);// pusieron los valores mayores i(mx) como infinito
			cur += val;
			best = min(best, cur);// variacion del kadene algorithm
			ans = max(ans, (cur - best) - mx);max sum - i
		}
	}
	printf("%lld\n", ans);
	return 0;
}
*/


int anotherTask(vector<int> &arr)
{
    const int n = arr.size();
    int value = 0;
    int best = -1000;
    int element = -1000;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        value = max(value + arr[i], arr[i]);//if value = arr[i]
        best = max(best, value);
        if (value == arr[i] && best == value)
        {
            element = arr[i];
        }
        else
        {
            element = max(element, arr[i]);
            ans = max(ans,best - element);
        }
    }
    return ans;
}

int other(vector<int> &arr)
{
    const int n = arr.size();
    int cont = 0;
    int best = 0;
    int element = -1000;
    for (int i = 0; i < n; i++)
    {
        element = max(element, arr[i]);
        cont += arr[i];
        if (arr[i] > 0)
        {
            if (cont-element < 0 && element > 0)
            {
                cont = arr[i];
                element = arr[i];
            }
            best = max(best, cont - element);
        }
        best = max(best, cont - element);
    }
    return best;
}


int main()
{
    send help
    int n,t;
    cin >> n;
    vector <int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sol = other(arr);;
    int sol2 = anotherTask(arr);
    int ans = max(sol, sol2);
   // int ans = other(arr);
    cout << ans << '\n';
    return 0;
}
