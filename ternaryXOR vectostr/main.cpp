#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void ternary ();
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ternary();
    }
    return 0;
}

void ternary()
{
    int n;
    cin >> n;
    char arr[n];
    int j = n;
    for (int i = 0; i < n; i++)
    {
        char x;
        cin >> x;
        arr[i] = x;
    }
    string a = "", b = "";
    for (int i = 0; i < n; i++)
    {
       if (arr[i] == '2')
       {
           a += "1";
           b += "1";
       }
       else if (arr[i] == '0')
       {
           a += "0";
           b += "0";
       }
       else
       {
           a += "1";
           b += "0";
           j = i + 1;
           break;
       }
    }
    while (j < n)
    {
        a += "0";
        b += arr[j];
        j++;
    }
    cout << a << '\n';
    cout << b << '\n';
    return;
}
