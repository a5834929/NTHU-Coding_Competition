#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
    char s[150];
    int n[150], m[150], ans[250];
    int i, j, carry, len;

    while(scanf("%s", s)!=EOF){
        memset(ans, 0, sizeof(ans));
        memset(n, 0, sizeof(n));
        memset(m, 0, sizeof(m));
        len=strlen(s);
        for(i=len-1;i>=0;i--){
            n[len-i-1]=s[i]-'0';
            m[len-i-1]=s[i]-'0';
        }
        n[0]+=1;
        for(i=0;i<=len;i++)
            for(j=0;j<len;j++)
                ans[i+j]=ans[i+j]+n[i]*m[j];
        carry=0;
        for(i=0;i<=2*len+2;i++){
            ans[i]+=carry;
            carry=ans[i]/10;
            ans[i]%=10;
        }
        for(i=2*len+2;i>=0;i--)
            if(ans[i])
                break;
        for(;i>=0;i--)
            printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}
