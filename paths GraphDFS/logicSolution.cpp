#include<bits/stdc++.h>

using namespace std;

const int mx=1e3+1;
bool vis[mx];
vector<int>adj[mx];//forma de initializar el vector
int count_connected=0;//no es recomendable trabajar con global variables
int total_connected=0;
int max_connected=0;
int total_pair_edges=0;

void dfs(int u)
{
    count_connected++;
    vis[u]=true;//en este ejemplo el autor utilizo el visited y no paso el node anterior, el node anterior el preferible
    //usarlo cuando la grafica es un tree por que los child components solo tienen un parent directo
    //ya he usado esta variacion antes sirve para saber la longitud del path de componentes conectados
    for(int i=0;i<adj[u].size();i++)
    {
        if(!vis[adj[u][i]])
        {
            dfs(adj[u][i]);
        }
    }
}

int main()

{
    int n,m,k,u,v;
    cin>>n>>m>>k;
    int special[k];
    for(int i=0;i<k;i++)
    {
        cin>>special[i];
    }
    for(int i=0;i<m;i++)//armar el grafico
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int j=0;j<=n;j++)//inicializar el vector visited
    {
        vis[j]=false;
    }
    for(int i=0;i<k;i++)//la funcion de este bloque es determinar cuantos componentes estan conectados(que haya un edge entre ellos)
    {//cuanto vale la cadena max de componentes conectados y cuantos edges hay entre esos pares de componentes(un edge se forma
    // cuando hay un par de componentes) todo esto se logra con el dfs.
        count_connected=0;
        dfs(special[i]);
        max_connected=max(count_connected,max_connected);
        total_connected+=count_connected;
        total_pair_edges+=(count_connected*(count_connected-1))/2;
    }
    //viene la matematica
    n=n-total_connected+max_connected;//el resultado de esto es dejar los componentes que conforman la max cadena
    //y los componentes solitarios (no conectados)
    total_pair_edges=total_pair_edges-((max_connected*(max_connected-1))/2)+(n*(n-1))/2;
    //con la de arriba tenemos el total edges en el grafico menos las del camino mas largo
    //sumando los hipoteticos edges que agregaria entre la cadena mas larga y el componente solitario

    total_pair_edges=total_pair_edges-m;//a ese total le restamos los edges dados anteriormente(los ya construidos)
    cout<<total_pair_edges<<endl;
}
