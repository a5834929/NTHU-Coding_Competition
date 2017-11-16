#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int num[50001], dp[50001], Ans[50001];
int max(int a, int b);
int main(){
    int T, i, j, x, n;
    int len, ans, tmp;
    char str[1000];
    scanf("%d", &T);
    getchar();
    getchar();
    while(T--){
        len=1;
        n=0;
        while(gets(str)){
            if(strlen(str)==0)
                break;
            sscanf(str, "%d", &x);
            num[len]=x;
            dp[len]=1;
            len++;
        }
        ans=0;
        for(i=1;i<len;i++)
            for(j=i+1;j<len;j++)
                if(num[i]<num[j])
                    dp[j]=max(dp[j], dp[i]+1);
        for(i=1;i<len;i++)
            if(dp[i]>ans)
                ans=dp[i];
        printf("Max hits: %d\n", ans);
        tmp=ans;
        for(i=len-1;i>0;i--){
            if(dp[i]==tmp){
                Ans[n]=num[i];
                tmp--;
                n++;
            }
        }
        for(i=n-1;i>=0;i--)
            printf("%d\n", Ans[i]);
        if(T)
            printf("\n");
    }
    return 0;
}

int max(int a, int b){
    return (a>b)?a:b;
}
