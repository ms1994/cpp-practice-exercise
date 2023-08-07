#include "Solution.h"
#include <string>
#include<sstream>
using namespace std;

Solution::Solution()
{
}
string Solution::createPhoneNumber(const int arr [10]){
    ostringstream os1, os2,os3;
    for (int i=0; i < 10 ; i++){
        if (i < 3) os1 << arr[i];
        if (i >= 3 && i < 6) os2 << arr[i];
        if (i >= 6) os3 << arr[i];
    }
    string s1(os1.str()), s2(os2.str()), s3(os3.str());
    string phone = "(" + s1 + ") " + s2 + "-"+s3;
    return phone;
}
string createPhoneNumber2(const int digits[10]) { //otra forma de parse un int a string
  std::string res = "(...) ...-....";//sin usar nada especial
  for (unsigned is = 0, id = 0; is < res.length(); is++)
    if (res[is] == '.')
      res[is] = '0' + digits[id++];//el cero no lo cuenta en la transformacion
  return res;
}
