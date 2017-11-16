#include<stdio.h>
#include<string.h>

int main(){
    char n1[101], n2[101];
    int i, j, k, len1, len2, carry;
    int N1[101], N2[101], ans[300];

    while(scanf("%s%s", n1, n2)!=EOF){
        memset(ans, 0, sizeof(ans));
        len1=strlen(n1);
        len2=strlen(n2);

        for(i=0;i<len1;i++)
            N1[i]=n1[len1-i-1]-'0';
        for(i=0;i<len2;i++)
            N2[i]=n2[len2-i-1]-'0';

        for(i=0;i<len1;i++)
            for(j=0;j<len2;j++){
                ans[i+j]=ans[i+j]+N1[i]*N2[j];
                k=i+j;
            }
        carry=0;
        for(i=0;i<=k+1;i++){
            ans[i]+=carry;
            carry=ans[i]/10;
            ans[i]%=10;
        }

        for(i=k+3;i>=0;i--)
            if(ans[i])
                break;
        k=i;
        for(i=k;i>=0;i--)
            printf("%d", ans[i]);
        printf("\n");
    }

    return 0;
}

/*************************************************************************************

Problem Description
Compute A*B.

Input
For each case a line, there will be two positive integers A and B < 10^100.

Output
For each case a line, output the answer A*B.

Sample Input
25 16
897 9945
123456789 987654321

Sample Output
400
8920665
121932631112635269

*************************************************************************************/
