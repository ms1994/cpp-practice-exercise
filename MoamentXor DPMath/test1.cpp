#include <bits/stdc++.h>
//this solution is from Galen Colin.
typedef long long ll;

const ll MOD = 1e9 + 7;
ll factorial[500000];
ll invFactorial[500000];


using namespace std;


ll mpow(ll base, ll exp) {//binary exponentiation
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res *1LL* base) % MOD;
		}
		exp >>= 1;//se divide entre 2, por cada bitwise
		base = (base *1LL* base) % MOD;//en numeros binarios para saber la otra potenia lo elevo al cuadrado
	  }//es decir se multiplica por si mismo
	  return res;
}
void generateFactorial(int n);
ll nck(int n, int k);

int main()
{
	int t;
	cin >> t;
	generateFactorial(200010);
	while (t--)
    {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 1)
        {
            ll ans = 1;//begin with one because the case when n == 1.
            for (int i = 0; i<n; i+=2)
            {
                ans = (ans + nck(n,i)) % MOD;
            }
            ans = mpow(ans, k);
            cout << ans << endl;
        }
        else
        {
            ll aux = 0;
            for (int i = 0; i < n; i+=2)
            {
                aux = (aux + nck(n,i)) %MOD;
            }
            ll ans = 0;
            for (int i = 0; i <= k; i++) //iterate until k for considerer the case when k is 1 and never
                //reach the condition when and > xor.
            {
                ll current = 1;
                current = (current * mpow(aux, i)) % MOD;
                if (i < k - 1) //(when And > XOR exist numbers that in any combinations is always and > xor in the k-1 buts)
                {
                    current = (current * mpow(2, n*(k-1-i)))%MOD;
                }
                ans = (current + ans) % MOD;
            }
            cout << ans<< endl;
        }
    }
}


void generateFactorial(int n)
{
    factorial[0] = factorial[1] = invFactorial[0] = invFactorial[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial[i] = (i * factorial[i - 1]) % MOD;
    }
    invFactorial[n] = mpow(factorial[n], MOD-2);//fermat theory para calcular el inverso del factorial n!^-1 mod m
    for (int i = n-1; i>= 2; i--)
    {
        invFactorial[i] = ((i + 1) * invFactorial[i + 1]) % MOD;
    }
}

ll nck(int n, int k)
{
    if (k < 0 || k > n) return 0;
    ll divisor = (invFactorial[k] * invFactorial[n-k]) % MOD;
    return (factorial[n]*divisor) % MOD;
}
