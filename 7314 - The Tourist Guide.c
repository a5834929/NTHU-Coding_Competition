#include<stdio.h>
#include<string.h>
int map[200][200];
int max(int a, int b);
int min(int a, int b);
void Floyd(int n);

int main(){
    int I=1, N, M, a, b, c, i;
    int s, e, tour, ans;

    while(scanf("%d%d",&N,&M)!=EOF && !(N==0 && M==0)){
        memset(map,0,sizeof(map));
        for(i=0;i<M;i++){
            scanf("%d%d%d", &a, &b, &c);
            map[a][b]=map[b][a]=max(map[a][b], c);
        }
        Floyd(N);
        scanf("%d%d%d", &s, &e, &tour);
        ans=(tour+map[s][e]-2)/(map[s][e]-1);

        printf("Scenario #%d\n",I);
        printf("Minimum Number of Trips = %d\n", ans);
        printf("\n");
        I++;
    }
    return 0;
}


int max(int a, int b){
    return (a>b)?a:b;
}
int min(int a, int b){
    return (a<b)?a:b;
}
void Floyd(int n){
    int i, j, k;
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                map[i][j]=max(map[i][j], min(map[i][k], map[k][j]));
}
