#include<stdio.h>
#include<string.h>

int main(){
    int N, i, j, exp, n, len, num;
    int ans[10000], carry[10000];

    scanf("%d", &N);
    while(N--){
        memset(ans, 0, sizeof(ans));
        memset(carry, 0, sizeof(carry));
        scanf("%d%d", &n, &exp);
        len=0;
        num=n;
        while(n){
            ans[len]=n%10;
            n/=10;
            len++;
        }
        while(exp>1){
            for(i=0;i<len;i++){
                ans[i]=ans[i]*num+carry[i];
                carry[i+1]=ans[i]/10;
                ans[i]%=10;
                if(carry[len])
                    len++;
            }
            exp--;
        }
        for(i=len;i>=0;i--)
            if(ans[i])
                break;
        for(;i>=0;i--)
            printf("%d", ans[i]);
        printf("\n");
    }
    return 0;
}

/***************************************************************************************

Problem Description

Compute ab for the given integers a and b.
Input

The first line of input contains a positive integer t (t <= 100), which indicates the number of test cases.
For each case, there are two positive number a, b in a line (0 < a, b <= 250).
Output

For each test case, output in a single line.
Sample Input

2
2 3
10 10
Sample Output

8
10000000000

***************************************************************************************/
