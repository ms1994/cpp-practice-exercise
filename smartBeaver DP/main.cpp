#include<bits/stdc++.h>
using namespace std;
int n,m,a[1010],b[1010];
bool ans[1010];//esta es la solucion usa dinamic programming y frecuencia de datos
int main()//no entendi el problema por eso salto a otro ejercicio
{
	cin>>n>>m;
	ans[0]=true;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	int t=0;
	for(int i=1;i<=n;++i)
	{
		if(!b[i])
		{
			int cnt=0;
			bool ok=false;
			for(int j=i;j;j=a[j],cnt++)//empieza en j = i y luego al comenzar un nuevo ciclo j
			{//pasa a tomar el valor de a[j]
				if(j==m)
				{
					ok=true;
				}
				if(ok)
				{
					t++;
				}
			}
			if(!ok)
			{
				for(int j=n;j>=cnt;j--)
				{
					ans[j]|=ans[j-cnt];
				}
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(ans[i])
		{
			cout<<i+t<<endl;
		}
	}
	return 0;
}
