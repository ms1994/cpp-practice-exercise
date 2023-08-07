#include<bits/stdc++.h>
using namespace std;
int n,k,x;
int mp[1002][1002];
void solve(int x)
{
    int px = (k+1)/2,py = (k+1)/2;
    int ans1=0,ans2=0,ans3=0,ans4=1e9;
    for(int i=1;i<=k;i++)//doble for para recorrer la matriz
    {
        for(int j=1;j<=k-x+1;j++)//este for es para asegurar no tomar un valor por encima de los limites
        {
            int sum = 0,flag=1;
            for(int t=j;t<j+x;t++)//los valores de la col, y se prueban todos los valores
            {
                if(mp[i][t])
                {
                    flag = 0;
                    break;//se usa un flag para romper cuando estoy en un lugar invalido
                }
                sum += abs(t-py)+abs(i-px);
            }
            if(flag==1&&sum<ans4)
                ans4=sum,ans1=i,ans2=j,ans3=j+x-1;//me aseguro que ans3 esta en los boundarys
        }
    }
    if(ans4==1e9)printf("-1\n");
    else
    {
        for(int i=ans2;i<=ans3;i++)
            mp[ans1][i]=1;//memorization
        printf("%d %d %d\n",ans1,ans2,ans3);
    }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&x),solve(x);
    return 0;
