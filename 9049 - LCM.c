#include<stdio.h>

int main(){
    int n, A, B, a, b, gcd;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &A, &B);
        a=A;
        b=B;
        while((A%=B)&&(B%=A));
        gcd=A+B;
        printf("%d\n", gcd*(a/gcd)*(b/gcd));
    }

    return 0;
}

/****************************************************************************

Problem Description
Given two positive integers a and b, compute their least common multiple (LCM).
The LCM of a and b is the smallest positive integer that can be divided by a
and b with no reminder.

Input
First line contains a positive integer t (t<=1000), which indicates the number
of test cases in the input. In the next t line, each line contains two positive
integers a, b, which are smaller or equal to 106.

Output
For each case, output the LCM of a and b in a line.

Sample Input
3
2 4
6 9
10 15

Sample Output
4
18
30

*****************************************************************************/
