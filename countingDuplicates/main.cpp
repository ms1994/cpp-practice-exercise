#include <iostream>
#include <ctype.h>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
using namespace std;
size_t duplicateCount(const char* in);
int main()
{
    const char* str = "aabBcde";
    string s;
    for (int i = 0; i< strlen(str); i++){
        s += toupper(str[i]);
    }
    sort(s.begin(), s.end());
    cout << duplicateCount(str) << endl;
    return 0;
}
size_t duplicateCount(const char* in)
{
    if (strlen(in)<= 1) return 0;
    string s;
    for (int i = 0; i< strlen(in); i++){
        s += toupper(in[i]);
    }
    sort(s.begin(), s.end());
    size_t result = 0;
    for (int i = 1; i < s.length() - 1; i++){
        if (s[i] == s[i-1] && s[i] != s[i+1]){
            result++;
        }
        if (i + 1 == s.length()-1 && s[i] == s[i+1]) result++;
    }
    return result;
}


#include <unordered_map>
#include <algorithm> //count_if para contor los key/values del unordered map siguiendo una condicion especifica

#include <cctype>
//estudiar otra solucion
std::size_t duplicateCount(const char* in) {
  std::unordered_map<char, unsigned> counts;  // Unorded map contain a pair key value
  for (const char* c = in; *c != '\0'; ++c) {// Se construye con una hash table y permite el
    ++counts[tolower(*c)];                   //rapido acceso a los values
  }//guarda cada char en un undorded map
  //la key son las letras de valor 1, primero suma y luego asigna (++counts),ejm counts[a] = 1, ..counts[a] = 2
  //suma si hay otra letra igual

  //count_if pasa el rango del map y una funcion para evaluar en cada key value pair
  return std::count_if(cbegin(counts), cend(counts), [](const auto& count) {//se pasa una funcion como argumento
      return count.second > 1; //second es el value count.first es el key
    });// Como en JS estoy construyendo la funcion count dentro del count_if
    //    diciendole que solo cuente los key/value pairs con valores mayores a 1,
    //es decir las letras que se repiten
    //el count_if retorna un integer que cuenta los valores que no sean falsos en el predicator (la funcion)
//del tercer parametro
}
