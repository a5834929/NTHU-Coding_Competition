#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DFS(int s);
void Union(int a, int b);
int find(int a);
int set[1010], met[1010][1010];
int N;

int main(void){

    int M, Q, i, a, b;
    freopen("pd-ttime.in", "r", stdin);
    freopen("out.txt", "w+", stdout);
    while(scanf("%d%d%d", &N, &M, &Q)!=EOF){

        memset(met, 0, sizeof(met));
        for(i=1;i<=N;i++)
            set[i]=i;
        for(i=1;i<=M;i++){
            scanf("%d%d", &a, &b);
            met[a][b]=1;
            met[b][a]=1;
            Union(a, b);
        }
        for(i=1;i<=N;i++)
           DFS(i);

        for(i=1;i<=Q;i++){
            scanf("%d%d", &a, &b);
            if(find(a)==find(b))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    return 0;
}

void Union(int a, int b){
    int x, y;
    x=find(set[a]);
    y=find(b);

    if(x!=y)
        set[y]=x;
}

int find(int a){
    if(set[a]==a)
        return a;
    else
        return set[a]=find(set[a]);
}

void DFS(int s){
    int i;
    for(i=1;i<=N;i++)
        if(met[s][i] && find(s)!=find(i))
            Union(s, i);
}
