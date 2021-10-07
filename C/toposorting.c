#include<stdio.h>
#include<stdlib.h>

int s[10],t=0;
void dfs(int n, int a[10][10], int u, int vis[]){
    int v;
    vis[u] = 1;

    s[t++]=u;
    printf("%d ",u);

    for(v=0;v<n;v++){

        if((a[u][v] == 1) && (vis[v]==0))
            dfs(n,a,v,vis);

    }
}
int main(){

    int n,i;
    int a[10][10], vis[10];
    \

    printf("Enter the number of nodes ");
    scanf("%d",&n);

    printf("Enter the adjacency matrix\n");

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            scanf("%d",&a[i][j]);

        }
    }

    for(int i=0;i<n;i++){

        vis[i] = 0;
    }

    printf("DFS order of reachable vertex are ");

    dfs(n,a,0,vis);


    for(int i=0;i<n;i++){

        if(vis[i] == 0){
            printf("\nGraph is disconnected\n");
            return 0;
        }

    }
    printf("\nGraph is connected\n");
    printf("The poping order is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",s[--t] );
    }
    printf("\n The topological ordering is:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ",s[i]);
    }
    return 0;
}

