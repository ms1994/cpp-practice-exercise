#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

string odd_or_even(const vector<int> &arr);

int main()
{
    int a = -2;
    if (a % 2 == 0){
        cout << odd_or_even({1}) << endl;
    }
    return 0;
}
string odd_or_even(const vector<int> &arr){

    if (arr.size() == 0) return "even";
    int sum = 0;
    sum = accumulate(arr.begin(),arr.end(), sum); //retorna directamente el valor del acumulado
    return sum % 2 == 0 ? "even" : "odd";
}

std::string odd_or_even2(const std::vector<int> &arr) //otra solucion utilizando el bits a bits
{
    return std::accumulate(arr.begin(),arr.end(),0)&1?"odd":"even"; //se compara con el 1 en binario, si es true es odd
}
