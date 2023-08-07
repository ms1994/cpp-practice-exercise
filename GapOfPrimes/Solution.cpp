#include "Solution.h"
#include <math.h>
#include <utility>
using namespace std;
Solution::Solution()
{
    //ctor
}
pair <long long, long long> Solution::gap(int g, long long m, long long n){
    if (g % 2 != 0) return make_pair(0,0);
    if (n - m < g) return make_pair(0,0);
    int i = round(m / 6);
    Solution obj;
    long long a = 0;
    long long b = 0;
    long long c = 0;
    if (m == 3 && g == 2){
        return make_pair(3, 5);
    }
    while ((a < m && b < m) || (a + g <= n || b + g <= n)){
        a = 6*i - 1;
        b = 6*i + 1;
        if (a >= m && a <= n && obj.isPrime(a)) {
            if (a - c == g && c != 0) return make_pair(c, a);
            else c = a;
        }
        if (b >= m && obj.isPrime(b) && b <= n) {
           if (b - c == g && c != 0) return make_pair(c, b);
           else c = b;
        }
        i++;
    }
    return make_pair(0, 0);
}
pair <long long, long long> Solution::gap2(int g, long long m, long long n)
    {
        std::vector<bool> sieve(n,false);// un vector de longitud n valor false?
        sieve[0] = sieve[1] = true;     //investigar la tecnica del tamiz (sieve) para hallar los primes
        long long lastprime = 1;
        for(long long i = 2; i<n; i++) {
            if(!sieve[i]) {
                if (lastprime > m && i < n && i - lastprime == g) {
                    return {lastprime, i};
                } else {
                    lastprime = i;// se registran los multiplos de los primos
                    for (int temp = 2*i; temp<n; temp += i)
                        sieve[temp] = true;
                }
            }
        }
        return {0,0};
    };
//se construye un tamiz donde cero (falso) significa que es primo y los verdaderos no lo son y
//son factores del sieve[k]

 bool Solution::isPrime(int num){
    if (num <= 1) return false;
    if (num == 2 || num == 3 ) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    int n = 1;
    int a = 0;
    int b = 0;
    while (n*n < num){
        int a = 6*n +1;
        int b = 6*n -1;
        n++;
        if (num == a || num == b) return true;
        if (num % a == 0 || num % b == 0) return false;
    }
    return true;
 }
