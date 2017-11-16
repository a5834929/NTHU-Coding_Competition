#include<stdio.h>
#include<string.h>
typedef struct{
    int fac, num;
}FAC;
FAC factor[100000];

int main(){
    int i ,j, N, n;

    while(scanf("%d", &N)!=EOF){
        memset(factor, 0, sizeof(factor));
        i=2;
        j=0;
        n=N;
        while(n>=i*i){
            if(n%i==0){
                if(factor[j-1].fac==i)
                    factor[j-1].num++;
                else{
                    factor[j].fac=i;
                    factor[j].num++;
                    j++;
                }
                n/=i;
            }
            else
                i++;
        }

        if(factor[j-1].fac==n)
            factor[j-1].num++;
        else{
            factor[j].fac=n;
            factor[j].num=1;
        }

        printf("%d = ", N);
        for(i=0;i<=j;i++){
            if(factor[i].fac!=0){
                printf("%d", factor[i].fac);
                if(factor[i].num>1){
                    printf("^");
                    printf("%d", factor[i].num);
                }
                if(factor[i+1].num!=0)
                    printf("*");
            }
        }
        printf("\n");
    }
    return 0;
}

/***************************************************************************

Problem Description
Given an integer N, do the prime factor decomposition of N.
If there are k prime numbers, print the format as N = p1^x1*p2^x2*p3^x3....pk^xk.

Input
There are several test cases. In each test case, there is an integer N
( 2 <= N < 1000000 ) occupied a newline.

Output
Print the given integer's prime factor decomposition in the format,
which is N = p1^x1*p2^x2...pk^xk if N has k primes.

Sample Input
3
20
100

Sample Output
3 = 3
20 = 2^2*5
100 = 2^2*5^2

***************************************************************************/
