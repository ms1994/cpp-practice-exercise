#include <iostream>
#include <stdlib.h>

using namespace std;

bool isPrime(int num);
bool isPrime2(int num);
int main()
{
   int n = 100003;
   cout << 29 % 10 << '\n';
   cout << isPrime(n) << '\n';
}

bool isPrime(int num){
    if (num <= 1) return false;
    if (num == 2 || num == 3 ) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    int n = 1;
    int a = 0;
    int b = 0;
    while (n*n < num){ //or squrt(num)
        int a = 6*n +1;
        int b = 6*n -1;
        n++;
        if (num == a || num == b) return true;
        if (num % a == 0 || num % b == 0) return false;
    }
    return true;
}
bool isPrime2(int num){
    if (num <= 1) return false;
    if (num == 2 || num == 3 || num == 5 || num == 7) return true;
    if (num % 2 == 0 || num % 3 == 0 || num % 5  == 0 || num % 7  == 0) return false;
    for (int i = 11; i*i <= n; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}
