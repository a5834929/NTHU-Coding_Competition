#include<stdio.h>
#include<string.h>
long long int dp[1001][1001];
int main(){
    int n, m, i, j;

    memset(dp, 0, sizeof(dp));
    for(i=1;i<=1000;i++){
        for(j=1;j<=1000;j++){
            if(i==1 || i==j)
                dp[i][j]=1;
            else
                dp[i][j]=((dp[i-1][j-1])%10007+(i*dp[i][j-1])%10007)%10007;
        }
    }
    while(scanf("%d%d", &n, &m)!=EOF && (n+m)){
        printf("%lld\n", dp[m][n]);
    }
    return 0;
}
