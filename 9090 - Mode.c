#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*p, const void*q);

typedef struct _P{
    int num, time;
}COUNT;
COUNT data[1001];

int main(){
    int N, n, i, max;
    while(scanf("%d", &N)!=EOF && N){
        max=0;
        memset(data, 0, sizeof(data));
        while(N--){
            scanf("%d", &n);
            data[n].num=n;
            data[n].time++;
            if(n>max)
                max=n;
        }
        qsort(data, max+1, sizeof(COUNT), cmp);
        printf("%d\n", data[0].num);
    }
    return 0;
}

int cmp(const void*p, const void*q){
    COUNT a=*(COUNT*)p, b=*(COUNT*)q;
    if(a.time!=b.time) return (a.time>b.time)?-1:1;
    else return (a.num<b.num)?-1:1;
}

/***********************************************************************************************

Problem Description
Mode means the most frequent value in a data set. Given a sequence of integers, find out their mode.

Input
There are several numbers of test cases.  Each case begins with an integer N (1 <= N <= 107).
The next line contains N integers separated by a blank space. Each number is less than 1000 and greater than 0.
The input is terminated if N = 0.

Output
For each test case, print the mode of the sequence.  If the mode is not unique, print the smallest one.

Sample Input
5
1 1 2 3 4
8
5 4 3 5 5 3 3 2
0

Sample Output
1
3

*********************************************************************************************/
