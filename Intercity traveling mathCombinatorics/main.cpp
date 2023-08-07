#include <bits/stdc++.h>
using namespace std;
//this solution is from Galen Colin.

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
/*
Este ejercicio solo hay que ver como aumenta en cada paso la p, al principio no lo ví y lo tome mal, despues de leer
el editorial y ver otra paginas te das cuentas como se debe contar, en resumen se cuenta desde el 2^(n-1), entonces
el primer valor p[0] aparece en el tramo 0-1 en todos los subset, en el segundo tramo 1-2 aparece 2^(n-2) * 2^(i)
calculabas eso para cada p-ith, dandote la formula final de:
p[i] = 2^(n-i) + 2^(n-1-i) o algo así
en mi caso tomé en cuenta el n-i y le sume el acumulado de los indices previos por ejemplo
n = 4
i = 4 p[4] = 2^(n-4) =  1;
i = 3 p[3] = 1 + 2^(n-3) = 3
i = 2 p[2] = 1 + 3 + 2^(n-2) = 8;
i = 1 p[1] = 1 + 3 + 8 + 2^(n-1);

lo que hice fue llevar el accumulado y se lo sumaba a cada 2^(n-i)
la respuesta por ser valor esperado es la suma de todos los valores esperados
sum(p[i] * a[i]) para todos los i;

*/



const ll MOD = 998244353;
 ll mpow(ll base, ll exp) {//binary exponentiation
	  ll res = 1;
	  while (exp) {//1 0 1
		if (exp % 2 == 1){
			res = (res * base) % MOD;
		}
		exp >>= 1;//se divide entre 2, por cada bitwise
		base = (base * base) % MOD;//en numeros binarios para saber la otra potenia lo elevo al cuadrado
	  }//es decir se multiplica por si mismo
	  return res;
}

int main()
{
    send help
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<ll> p(n);
    int exp = n - 1;
    ll acc = 0;
    for (int i = n-1; i >=0; i--)
    {
        p[i] = mpow(2,exp-i) + acc;
        p[i] %= MOD;
        acc += p[i];
        acc %= MOD;
    }
    ll ans = 0;
    for (ll i = 0; i < n; i++)
    {
        ans += (p[i] * a[i]);
        ans %= MOD;
    }
    cout << ans <<'\n';
    return 0;
}
