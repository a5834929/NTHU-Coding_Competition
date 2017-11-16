#include<stdio.h>

int main(){
    int ans[50000];
    int n, num, base, i, j;

    scanf("%d", &n);
    while(n--){
        i=0;
        scanf("%d %d", &num, &base);
        while(num>=base){
            ans[i]=num%base;
            num=num/base;
            i++;
        }
        ans[i]=num;
        for(j=i;j>=0;j--)
            printf("%d", ans[j]);
        printf("\n");
    }
    return 0;
}

/*******************************************************************************

Problem Description
 Given a decimal integer n and a base k, translate n to the corresponding k-based number.

Input
The first line contains an integer t (1 <= t <= 20),
which indicates the number of test cases in the input.
Each test case is given in a line, containing two integers n and k
(n <= 10000000, k<=9).

Output
Output the number in base k.

Sample Input
1
30 5

Sample Output
110

*******************************************************************************/
