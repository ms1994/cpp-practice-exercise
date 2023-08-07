#include <bits/stdc++.h>

using namespace std;

int wrath ();
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test = wrath();
    cout << test << endl;
}

int wrath()
{
    int n;
    cin >> n;
    vector <int> claws;
    int answer = 0;
    int point = 0;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        claws.push_back(l);
        if (i <= l) point = i;
    }
    int num = n;
    for (int i = n-1; i >= point; i--)
    {
        if (i < num) answer++;//se utiliza el min o el max de esa forma para guardar un track de los valores
        //que se llevan calculando luego de realizar una operacion de expansion o reduccion en el intervalo
        num = min(num,i - claws[i]);
    }
    return answer;
}
