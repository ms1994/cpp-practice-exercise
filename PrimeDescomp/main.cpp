#include <iostream>
#include <string>
#include <map>
#include "Solution.h"
using namespace std;

int main()
{
    Solution obj;
    cout << obj.factors(59) << endl;
    cout << obj.factors(16) << endl;
    cout << obj.factors(65443) << endl;
    cout << obj.factors(87653454) << endl;
    cout << obj.factors(175) << endl;
    return 0;
}
