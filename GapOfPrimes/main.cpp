#include <iostream>
#include "Solution.h"
#include <math.h>
#include <utility>
using namespace std;

int main()
{
    Solution obj;
    pair <long long, long long> s = obj.gap(10,300,400);
    cout << s.first<< " "<< s.second << endl;
    cout << obj.isPrime(331) << " "<< obj.isPrime(329) << endl;
    return 0;
}
