#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int countSwap2(vector <int> *arr);
int countSwap(int n,vector <int> arr);
int secondPerm (int n, vector <int> arr);
int main()
{
    int n;
    vector <int> arr;
    cin >> n;
    for (int i = 0; i < 2*n; i++)
    {
        int k;
        cin >> k;
        arr.push_back(k);
    }
    int sol = countSwap(n, arr);
    /* int a = countSwap2(&arr);
    for (auto it : arr)
        cout << it << " "; */
    cout << sol << '\n';
    return 0;
}
int countSwap(int n, vector <int> arr)
{
    int cont = 0, temp = 0;
    int cont2 = secondPerm(n, arr);
    while(arr[0] != 1)
    {
         if (arr[0] != 1 )
        {
            cont++;
            for (int i = 0; i < 2*n; i+= 2)
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
        if (arr[0] != 1)
        {
            cont++;
            for (int i = 0; i < n; i++)
            {
                temp = arr[i];
                arr[i] = arr[n+i];
                arr[n+i] = temp;
            }
        }
    }
    for (int i = 0; i < 2*n - 1; i++)
    {
        if (arr[i] > arr[i+1]) return -1;
    }
    return cont < cont2 ? cont : cont2;
}
int secondPerm (int n, vector <int> arr)
{
    int cont = 0, temp = 0;
    while(arr[0] != 1)
    {
        if (arr[0] != 1)
        {
            cont++;
            for (int i = 0; i < n; i++)
            {
                temp = arr[i];
                arr[i] = arr[n+i];
                arr[n+i] = temp;
            }
        }
        if (arr[0] != 1 )
        {
            cont++;
            for (int i = 0; i < 2*n; i+= 2)
            {
                temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
    return cont;
}




int countSwap2(vector <int> *arr)
{
    arr->push_back(5); //como manipular pointers de array
    vector <int> &arr2 = *arr; //se dereferencia para poder usar el iterator
    arr2[0] = 76;
    for (auto it : arr2)
        cout << it << " ";
    return 0;
}
