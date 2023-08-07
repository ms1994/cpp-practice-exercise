#include "Solution.h"
#include <string>
#include <map>
#include <sstream>
using namespace std;
Solution::Solution()
{

}
string Solution:: factors(int lst){
    map<int, int> primes;
    int n = 1;
    int a = 0;
    int b = 0;
    string result= "";
    while (a*a < lst && b*b < lst && lst > 1){
        if (lst % 2 == 0){
          primes[2]++;
          lst = lst/2;
        }
        else if (lst % 3 == 0){
            primes[3]++;
            lst = lst/3;
        }
        else {
            int a = 6*n -1;
            int b = 6*n +1;
            if (lst % a == 0) {
                primes[a]++;
                lst = lst/a;
            }
            if (lst % b == 0) {
                primes[b]++;
                lst = lst/b;
            }
            if (lst % a != 0 && lst % b != 0) n++;
        }
    }
    if (lst > 1) primes[lst]++;
    for (auto it: primes) {
        if (it.second == 1) {
           result += "(" + to_string(it.first) + ")";
        }
        else result+= "("+ to_string(it.first) +"**"+to_string(it.second)+ ")";
    }
    return result;
}
string Solution:: factors2(int n){ // Mejor solucion
    ostringstream res;//complejidad parece de O(n) busca todos los factores y los gyarda si se repiten
      for (int i = 2; n > 1; i++) {
        int k = 0;
        while (n % i == 0) {
          n /= i;
          k++;
        }
        if (k == 1)
          res << '(' << i << ')'; //forma de trabajar con el ostringstream, sin necesidad del string
        else if (k > 1)
          res << '(' << i << "**" << k << ')';
      }
      return res.str();
}
