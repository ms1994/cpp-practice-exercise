#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,q;
    scanf("%d%d", &n,&q); //se guarda los valores en la direccion
    vector <int> a(n); //uso del scanf para append value al vector
    for (int &x: a) scanf("%d", &x);
    vector <int>::iterator it;
    it = find(a.begin(), a.end(), 3); //debe usar un iterator, el find te devuelve el valor si lo consigue,
    //sino esta, te devuelve el a.end()
    int p =find(a.begin(), a.end(), 3) - a.begin(); //resta las direcciones y  luego hace la conversion a int;
    //te deja la posicion del elemento
    printf("%d %d %d\n", *a.begin(), *it, p); //al hacer un pointer a la direccion podemos ver el valor que esta dentro
    //de la variable, como las respuestas estan en base 1 y no cero se le suma +1 al p al final;

    a.erase(a.begin()+p);
    a.insert(a.begin(), 3);
    //rotate(a.begin(), a.begin()+p, a.begin() + p + 1);//mueve a la izquierda los elementos dentro del rango
    //y los coloca en la posicion -1 asignada en el ultimo parametro (contando desde cero);
    //con ese codigo mueve los valores que estan desde el inicio hasta p (rango), y los coloca a la izquierda de p
    //p no es el que se mueve sino los valores que estan antes que el.
    for (auto it: a) cout << it << " ";


    return 0;

    //la respuesta que pense de colocar insertar el valor al inicio y luego borrarlo no esta tan mal,
    //solo que esta hace gala de las funciones pre fabricadas de los vectores.
}
