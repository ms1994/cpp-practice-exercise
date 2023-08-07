#include <bits/stdc++.h>
using namespace std;
//this solution is from Galen Colin.

#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;


const ll MOD = 1e9 + 7;


ll mpow(ll base, ll exp);

const ll FACTORIAL_SIZE = 1.1e6;
ll factorial[FACTORIAL_SIZE], invFactorial[FACTORIAL_SIZE];
bool __factorials_generated__ = 0;

void generateFactorial(int n);

ll nck(int n, int k);

ll n,k, miquel;
void solve(int tc);
int main()
{
	send help

	generateFactorial(200010);
	int tc=1;
	cin >> tc;
	for (int t = 0; t < tc; t++) solve(t);

}

ll mpow(ll base, ll exp) {//binary exponentiation
	  ll res = 1;
	  while (exp) {
		if (exp % 2 == 1){
			res = (res * base) % MOD;
		}
		exp >>= 1;//se divide entre 2, por cada bitwise
		base = (base * base) % MOD;//en numeros binarios para saber la otra potenia lo elevo al cuadrado
	  }//es decir se multiplica por si mismo
	  return res;
}



void generateFactorial(int n)
{

    __factorials_generated__ = 1;
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
    if (!__factorials_generated__) {
			cerr << "Call gen_factorial you dope" << endl;
			exit(1);
		}
    if (k < 0 || k > n) return 0;
    ll divisor = (invFactorial[k] * invFactorial[n-k]) % MOD;
    return (factorial[n]*divisor) % MOD;
}


void solve(int tc)
{
        cin >> n >> k;
        if (n % 2 == 1)
        {
            ll ans = 1;//begin with one because the case when n == 1.
            for (int i = 0; i<n; i+=2)
            {
                ans = (ans + nck(n,i)) % MOD;
            }
            ans = mpow(ans, k);
            cout << ans << '\n';
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
            cout << ans<< '\n';
        }
}
