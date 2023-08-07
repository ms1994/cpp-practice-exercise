#include <bits/stdc++.h>
using namespace std;


#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}
typedef long long ll;
map <ll, ll> teams;
/*
MI SOLUCION INICIAL ES MEDIO CORRECTA: SE DEBE USAR DP SABIENDO QUE UN GRUPO MAYOR A 5 SE PUEDE FORMAR COMO UNION
ENTRE LOS DE 3, 4 Y 5. Y POR CALCULOS SE DEMUESTRA QUE SUM(GRUP(6 ELEMENTS)) > SUM(GRUP(3 ELEMENT)) + SUM(GRUP(3 ELEMENT))
EL DP[I+J] > DP[I] + DIFF SIRVE ADEMAS PARA REVISAR SI UN ELEMENTO DE 3 ES MAYOR A OTRO GRUPO COMPUESTO DE 4 0 5.

PARA SABER QUE GRUPO PERTENECE CADA NUMERO SE PUEDE UTILIZAR UN PARENT ARRAY (EDITORIAL) DONDE EL PARENT PARA CADA CALCULO
DEL CHILDREN SE GUARDARA LA POSICION ITH DE PARENT EJEMPLO: SUPONGAMOS QUE EL ARRAY QUE TENEMOS ES DE 14 ELEMENTOS.
COMO NOSOTROS CALCULAMOS PARA CADA I + J, I ES EL PARENT Y J LA CANTIDAD DE GENTE EN EL GRUPO (3, 4 0 5), EL DP PODEMOS USAR
ESO PARA SABER CADA VEZ QUE EL DP CAMBIA PORQUE ES MENOR GUARDAR LA POSICION DE PARENT (I) ASI CUANDO PARENT(14) N = 14
EL VALOR SERA P[14] = 11 (SI EL GRUPO CON EL VALOR MAS BAJO ES UNA DE 3), P[14] = 10 (SI ES GRUPO ES DE 4) O P[14] = 9 (SI ES 5)
ESE VALOR NOS DICE ES QUE DESDE EL 14 HASTA EL PARENT 11,10 0 9, HAY UN GRUPO DE 3,4 O 5 SEGUN CORRESPONDA AL PROBLEMA,
PODEMOS GUARDAR PARA CADA I+J DEL PARENT CUAL ES SU I. HASTA LLEGAR A 0. P[4] = 0, SIGNINFICA QUE EL PRIMER GRUPO ES DE 0 A 4.
LOS PARENT IRAN BAJANDO SEGUN CORRESPONDA AL PROBLEMA Y AL MENOR VALOR DE LOS GRUPOS.

LA SUMA DE LOS GRUPOS SUBDIVIDIDOS ES MENOR O IGUAL A EL GRUPO COMPUESTO.

PENDIENTE.

DP ENTRE GRUPOS DE 3, 4 Y 5 POR CADA I.
ll partitionArray(vector<ll> &arr, ll a, ll b, ll c, ll d) // donde partir
{
    ll n = d - a + 1;
    if (n < 5)
    {
        return d;
    }
    ll i = 0;
    bool ok = false;
    while (d -(c + i) + 1 >= 3)
    {
        ll prev = arr[a]-arr[b+i] + arr[c+i] -arr[d];
        ll newOne = arr[a]-arr[b + i + 1] + arr[c + i + 1] -arr[d];
        if (prev <= newOne)
        {
            ok = true;
            break;
        }
        else
        {
            i++;
        }
    }
    if (ok)
    {
        return b+i;
    }
    else
    {
        return b+i-1; // retorno b porque se supone que es donde
    }

};

pair <ll, ll> solution(vector<ll> &arr, ll a, ll d, ll team)
{
    ll n = d - a + 1;
    if (n < 6)
    {
        for  (int x = a; x <=d; x++)
        {
            teams[arr[x]] = team + 1;
        }
        return make_pair(arr[a]-arr[d], team + 1);
    }
    if (arr[a] - arr[d] <= arr[a] - arr[a+2] + arr[a+3] - arr[d])
    {
        for  (int x = a; x <=d; x++)
        {
            teams[arr[x]] = team + 1;
        }
        return make_pair(arr[a]-arr[d], team + 1);
    }
    else {
        ll cut = partitionArray(arr, a, a + 2, a + 3, d);
        for (ll i = a; i <= cut; i++)
        {
            teams[arr[i]] = team + 1;
        }
        pair <ll, ll> ans =  cut < d ? solution(arr, cut + 1, d, team + 1) : make_pair(ll (0),team + 1);
        return { ans.first + arr[a] - arr[cut], ans.second};
    }
}*/

pair <ll, ll> solution(vector<ll> &arr, ll a, ll d, ll team)
{
    ll n = d - a + 1;
    if (n < 6)
    {
        for  (int x = a; x <=d; x++)
        {
            teams[arr[x]] = team + 1;
        }
        return make_pair(arr[a]-arr[d], team + 1);
    }
    vector<ll> dp(n, 1e9 + 100);
    dp[0] = 0;
    for (int i =0; i < n; i++)
    {
        for (int j = 3; j <= 5 && i + j < n;j++)
        {
            ll diff = arr[i] - arr[i+j-1];
            if (dp[i+j] > dp[i] + diff)// salto el 1 y el 2, porque son INF y no los puedo evaluar
            //despues i = 3, evaluo para cada i,
            {
                dp[i+j] = min(dp[i+j], dp[i] + diff);
                //dp a futuro, cuando toque ese valor en el futuro veremos cual grupo le sigue, si 3, 4, o 5
                // pasa por todos los supestos grupos y se queda con el menor
            }
        }
    }
}


int main()
{
    send help
    int n;
    cin >> n;
    vector <ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<ll> sortArray(n);
    sortArray = arr;
    sort(sortArray.begin(), sortArray.end(), greater<int>());
    pair <ll, ll> ans = solution(sortArray, 0, n-1, 0);
    cout << ans.first << " " << ans.second <<'\n';
    for (int i = 0; i < n; i++)
    {
        cout << teams[arr[i]] << " ";
    }
    return 0;
}
