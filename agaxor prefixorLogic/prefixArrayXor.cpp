#include <bits/stdc++.h>
using namespace std;
int pre[2005];
int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {//first of all construimos un prefix sub array de xor
            int a;
            scanf("%d",&a);
            pre[i]=(pre[i-1]^a);
        }//como el problema pide dejar dos numeros significa que podemos construir
        //un sub array de 3 o 2 elementos, por propiedad de los xor
        //5^5^5 = 5, basta con corroborar por nrutalforce la construccion de esos tres
        //sub elementos y que sean iguales entre ellos, los intervalos serian
        //[0,i] ^[i+1, j] ^[j+1, n-1] (cero index)
        //que es lo que hace el codigo siguiente,
        bool yes=!pre[n];//si es igual a cero serian dos intervalos que son iguales y es solucion
        //si es distinto de cero hay que buscar los 3 intervalos y ver que sean iguales
        //con el prefix sub array la solucion es O(n^2)
        for (int i=1;i<=n;i++)
        {
            for (int j=i+1;j<n;j++)
            yes|=(pre[i]==(pre[j]^pre[i]) && pre[i]==(pre[n]^pre[j]));
        }
        puts(yes? "YES":"NO");
    }
}
