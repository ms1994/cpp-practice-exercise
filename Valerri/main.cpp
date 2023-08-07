#include <bits/stdc++.h>

using namespace std;

/*You're given an array b of length n. Let's define another array a,
 also of length n, for which ai=2bi (1≤i≤n).

Valerii says that every two non-intersecting subarrays of a have different sums of elements.
You want to determine if he is wrong. More formally, you need to determine if there exist four integers
l1,r1,l2,r2 that satisfy the following conditions:

1≤l1≤r1<l2≤r2≤n;
al1+al1+1+…+ar1−1+ar1=al2+al2+1+…+ar2−1+ar2.
If such four integers exist, you will prove Valerii wrong. Do they exist?

An array c is a subarray of an array d if c can be obtained from d by deletion of several
(possibly, zero or all) elements from the beginning and several
(possibly, zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100).
Description of the test cases follows.

The first line of every test case contains a single integer n (2≤n≤1000).

The second line of every test case contains n integers b1,b2,…,bn (0≤bi≤109). */

/*Aprender a LEER E INTERPRETAR EL ENUNCIADO:
Resumen buscar dos sub arrays de "a" donde la suma de sus elementos sea distinto, la primera vez
que lo hize conte solo los sub arrays consecutivos mas no los independientes ejemplo un sub array
en la posicion [2,4] comparado con otro en la posicion [5,7], mi primer codigo no tomaba en cuanta estos
casos por eso y por el overflow estaba mal.

La respuesta es que si el array es "pairwise distinc" (los elementos del array no se repiten mas de 1 vez)
Podemos asegurar que la respuesta es NO debido a que se puede ver cada sub array como un numero bits
dentro de un numero binario de una longitud de 10¨9 (limite superio de n)y como cada representacion binaria es distinto
no habra suma igual (recordar que el array a es de forma 2^b es decir binario)*/
string valeriiArray();
int main()
{

    int t;
    vector <string> sol;
    cin >> t;
    for (int i = 0; i < t; i++)
        sol.push_back(valeriiArray());
    for (auto it : sol)
        cout << it << endl;

}

string valeriiArray()
{
    int n;
    unordered_map <int, int> a;
    cin >> n;
    bool ans = false;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        a[k]++;
        if (a[k] > 1) ans=true;
    }
    if (ans) return "YES";
    return "NO";
}
