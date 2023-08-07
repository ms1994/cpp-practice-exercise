#include <bits/stdc++.h>
using namespace std;


#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

/*
    Practice the merge sort algorithm

 */
void merge_sort(int arr[], int low, int high);

void merge_arr(int arr[], int low, int mid, int high);

int main()
{
    send help
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    merge_sort(arr,0,n-1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}

void merge_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge_arr(arr, low, mid, high);
    }
}

void merge_arr(int arr[], int low, int mid, int high)
{
    int i = low;// arr1 index (first halve)
    int k = low;// index for the new array
    int j = mid + 1;// arr2 index second half
    int aux[high+1];
    // 1 2 3 4 5 6 7 8 9
    while(i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            aux[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            aux[k] = arr[j];
            j++;
            k++;
        }
    }
    // store remaining element
    while (i <= mid)
    {
        aux[k] = arr[i];
        i++;
        k++;
    }
    while(j <= high)
    {
        aux[k] = arr[j];
        j++;
        k++;
    }
    for (int i = low; i < k; i++)
    {
        arr[i] = aux[i];
    }
}
