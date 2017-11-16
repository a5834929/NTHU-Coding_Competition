#include<stdio.h>

int main(){
    long long int dp[45];
    int T, i, len;

    scanf("%d", &T);
    while(T--){
        dp[0]=1;
        dp[1]=1;
        dp[2]=5;
        scanf("%d", &len);
        for(i=3;i<=len;i++)
            dp[i]=dp[i-1]+dp[i-2]*4+dp[i-3]*2;
        printf("%lld\n", dp[len]);
    }
    return 0;
}
