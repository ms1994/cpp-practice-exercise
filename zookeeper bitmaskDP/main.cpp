#include <bits/stdc++.h>

using namespace std;
#define send {ios_base::sync_with_stdio(false);}
#define help {cin.tie(NULL);}

typedef long long ll;

/*
ESTE PROBLEMA PARA QUE UN NUMERO U, LLEGUE A VALER LO DE V SUMANDO, SE DEBE CUMPLIR LO SIGUIENTE
1) LOS BITS (1) DE U DEBEN SER IGUAL O MAYORES A V, SINO ES ASI ES IMPOSIBLE FORMAR LA SUMA PARA LLEGAR A V
PORQUE FALTARIAN BITS PARA QUE SEAN IGUALES, Y CUANDO SUMAS LOS BITS NO SE INCREMENTAN (PARA ESTE CASO EN PARTICULAR)
2) PARA ESTE CASO EN PARTICULAR, SE PUEDE ALCANZAR A V, SIEMPRE Y CUANDO LA POSICION DEL MENOR BIT EN U, SEA MENOR A
LA POSICION DEL MENOR BIT EN V, YA QUE EN ESTE PROBLEMA CUANDO VAMOS SUMANDO SIMPLEMENTE HACEMOS UN BITSHIFT A LA IZQ
Y NO SE PODRIA LLEGAR AL BIT EN V HACIENDO BITSHIFT A LA IZQ SI EL BIT DE V ESTARIA A LA DERECHA DEL BIT DE U
CON COMPROBAR ESAS 2 PREMISAS, PODEM0S ASEGURAR QUE PODEMOS ALCANZAR A V.
*/

void sol(ll u, ll v)
{
    bool flag = false;
    if (u == v) flag = true;
    if (u < v)
    {
        int onesInU = __builtin_popcount(u);
        int onesInV = __builtin_popcount(v);
        flag = onesInU >= onesInV ? true:false;
        vector<int> bitsInU;
        vector <int> bitsInV;
        for (int i = 0; i < 31; i++)
        {
            if (u&(1<<i)) bitsInU.push_back(i);
            if (v&(1<<i)) bitsInV.push_back(i);
        }
        if (flag)
        {
            for (int i = 0; i < bitsInV.size(); i++)
            {
                if (bitsInU[i] > bitsInV[i])
                {
                    flag &= false;
                    break;
                }
            }
        }
    }
    if (flag) cout << "YES" << '\n';
    else cout << "NO" << '\n';;
}

int main()
{
    send help
    int q = 0;
    cin >> q;
    while (q--)
    {
        ll u,v;
        cin >> u >> v;
        sol(u,v);
    }
//    cout << "Hello world!" << endl;
    return 0;
}
