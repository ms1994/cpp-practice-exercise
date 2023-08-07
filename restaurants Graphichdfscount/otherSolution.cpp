#include <bits/stdc++.h>
#define LL long long
using namespace std;

vector<int> v[11];
int sum[11], tot, f[11], g[11];

int dfs(int u, int fa, int tot){
    sum[tot]++;
    for(int i=0; i<v[u].size(); i++){
        if(v[u][i]!=fa){
            dfs(v[u][i], u, (fa==-1?++tot:tot));
        }
    }
    return tot;
}

int main(){

    int n, a, b, ans=0;
    scanf("%d", &n);
    for(int i=1; i<n; i++){
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        f[0]=1;
        int tot=dfs(i, -1, 0);
        for(int i=1; i<=tot; i++){
            for(int j=10; j>=sum[i]; j--){
                f[j]=max(f[j], f[j-sum[i]]);
            }
        }
        if(tot==1){
            continue;
        }
        f[n-1]=0;
        ans=0;
        for(int j=10; j>=1; j--){
            g[j]=max(g[j], f[j]);
            ans+=g[j];
        }
    }
    printf("%d\n", ans);
    for(int i=1; i<10; i++){
        if(g[i]){
            printf("%d %d\n", i, n-i-1);
        }
    }

    return 0;
}
