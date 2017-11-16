#include<stdio.h>
#include<string.h>
#include<math.h>
int vill[301], dis[301][301], dp[301][301];
int main(){
    int V, P, i, j, k, mid;

    while(scanf("%d%d", &V, &P)!=EOF){
        memset(dis, 0, sizeof(dis));
        memset(dp, -1, sizeof(dp));
        for(i=1;i<=V;i++)
            scanf("%d", &vill[i]);
        for(i=1;i<=V;i++){
            for(j=i;j<=V;j++){
                mid=(i+j)/2;
                for(k=i;k<=j;k++)
                    dis[i][j]+=fabs(vill[k]-vill[mid]);
            }
        }
        for(i=1;i<=V;i++)
            dp[1][i]=dis[1][i];
        for(i=2;i<=P;i++)
            for(j=i;j<=V;j++)
                for(k=1;k<=j;k++)
                    if(dp[i][j]==-1 || dp[i][j]>dp[i-1][k]+dis[k+1][j])
                        dp[i][j]=dp[i-1][k]+dis[k+1][j];
        printf("%d\n", dp[V][P]);
    }
    return 0;
}
