#include<stdio.h>
#include<string.h>
int time[20010], path[20010], dp[50][20010];
int main(){
    int N, T, i ,j, max, max_i, p;

    while(scanf("%d", &N)!=EOF){
        scanf("%d", &T);
        memset(dp, 0, sizeof(dp));
        for(i=1;i<=T;i++)
            scanf("%d", &time[i]);
        for(i=1;i<=T;i++){
            for(j=0;j<=N;j++){
                if(time[i]>j)
                    dp[i][j]=dp[i-1][j];
                else if(dp[i-1][j]<=dp[i-1][j-time[i]]+time[i])
                    dp[i][j]=dp[i-1][j-time[i]]+time[i];
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        max=0;
        for(i=1;i<=N;i++){
            if(max<dp[T][i]){
               max=dp[T][i];
               max_i=i;
           }
        }
        for(i=T;i>=1;i--){
            if(dp[i][max_i]==dp[i-1][max_i-time[i]]+time[i]){
                path[i]=1;
                max_i=max_i-time[i];
            }
            else
                path[i]=0;
        }
        for(i=1;i<=T;i++)
            if(path[i])
                printf("%d ", time[i]);
        printf("sum:%d\n", max);
    }
    return 0;
}
