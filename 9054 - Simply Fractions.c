#include<stdio.h>

int main(){
    int n, a, b, A, B;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d", &a, &b);
        A=a;
        B=b;
        while((a%=b) && (b%=a));
        printf("%d/%d\n", A/(a+b), B/(a+b));
    }
    return 0;
}

/*********************************************************************************

Problem Description
Given a fraction, find its simplest fraction representation.

Input
The first line contains an integer t (1 <= t <= 20),
which indicates the number of test cases in the input.
In each case, each line contains two integers a and b (a, b <= 100000),
which represent the numerator and the denominator of a fraction.

Output
For each case, output a line with the simplest fraction.

Sample Input
2
7 3
4 2

Sample Output
7/3
2/1

*********************************************************************************/
