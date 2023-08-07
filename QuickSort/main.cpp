#include <bits/stdc++.h>
using namespace std;


#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
/*
En quickSort escojemos un pivot que puede ser el ultimo, el primero, o un elemento del medio del array.
Entonces debemos ordenar el array en base al pivot. Las particiones no son a la mitad del array sino que se hacen
dependiendo de donde quede el pivot ubicado en el array, el Worst sceneraio es N^2 pero es muy díficil llegar a el
porque tenemos varias opciones de pivot. Por lo que lo normal es n*log n. Ex: arr 6 2 1 7 8 5.
Pivot el ultimo valor del array.
pivot = 5 (array[hight]), comenzamos a traverse el array desde el low hasta el high - 1 (hight es el indice mayor del array)
necesitamos 2 indices el i para saber en que posicion quedara el pivot luego del calculo y el j que servira de guia para recorrer
el array.
inicialmente i apunta al principio. i = low, j=low, si array[j] es menor que el pivot significa que ese valor arr[j] va
antes del pivot por lo que debemos swap las posiciones entre ese arr[j], y el arr[i]. Luego del swap aumentamos i. Es como
buscar la posicion (i) del pivot en el array, empujando los valores mayores al pivot a la der del array.
for (j = low; j < high; j++)
    if (arr[j] < pivot)
        swap(arr[i], arr[j])
        i++;
del ejemplo, luego de la primera corrida quedaria:
arr = 2 1 6 7 8 5 (el 2 y el 1 como son pmenores que el pivot van de primero, el 6 swap sus posiciones con los menores al pivot)
luego de ver todos los valores hacemos un ultimo swap entre el pivot y la posicion que nos quedo de i, en este caso i = 2
porque hicimos 2 swap(entre 2 y 6, 1 y 6).
arr 2 1 5 7 8 6. (partimos el arr entre los valores antes del pivot y despues del pivot)
arr1 = 2 1
arr2 = 7 8 6
arr1 = pivot = 1, como 2 no es menor a 1 no hay swap solo el ultimo cuando cambiamos el pivot con i
1 2 (swap final entre el pivot e i)
arr2 = pivot = 6 (i = 0 poruqe 7 y 8 no son menores a 6)
6 7 8 (swap final entre i y el pivot)

luego arr1 lo dividimos entre los valores antes del pivot y despues del pivot antes = () , despues = 2 return 2 porque low = hight
arr2 queda antes del pivot () = despues 7 8, el 7 8 queda igual luego de todas las operaiones, 7 8 se dvide y quede () y 8 y listo
arr final = 1 2 5 6 7 8
*/

void quicksort(int arr[], int low, int high);
int pivotPart(int arr[], int low, int high);

int main()
{
    send help
    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort(arr, 0, n-1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
// initial: 5 3 7 2 6 4
// 3 5 7 2 6 4
// 3 2 7 5 6 4
// final: 3 2 4 5 6 7
int pivotPart(int arr[], int low, int high)
{
    int i = low - 1;
    int pivot = arr[high];
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            int aux = arr[j];
            arr[j] = arr[i];
            arr[i] = aux;
        }
    }
    i++;
    arr[high] = arr[i];
    arr[i] = pivot;
    return i;
}

void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = pivotPart(arr, low,high);// calcula la posicion i del pivot en el array, siempre ordena el pivot, y partitioon desde el
        quicksort(arr, low, pivot - 1); //quicksort antes del pivot
        quicksort(arr, pivot + 1,  high);//despues del pivot
    }
}
