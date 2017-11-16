#include<stdio.h>
#include<string.h>
int main(){
    int N, T, i, j, k, sum, half, ans;
    int dp[1004], vote[30];

    scanf("%d", &T);
    while(T--){
        sum=0;
        scanf("%d", &N);
        for(i=1;i<=N;i++){
            scanf("%d", &vote[i]);
            sum+=vote[i];
        }
        half=sum/2+1;
        for(i=1;i<=N;i++){
            memset(dp, 0, sizeof(dp));
            dp[0]=1;
            for(j=1;j<=N;j++){
                if(i!=j){
                    for(k=sum-vote[j];k>=0;k--)
                        dp[k+vote[j]]+=dp[k];
                }
            }
            ans=0;
            for(j=half-vote[i];j<half && j>=0;j++)
                    ans+=dp[j];
            printf("party %d has power index %d\n", i, ans);
        }
        printf("\n");
    }
    return 0;
}
