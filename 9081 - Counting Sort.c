#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int vis[10001];
long long int time[10001];

int main(){
    int n, i, a, max;
    while(scanf("%d", &n)!=EOF){
        max=0;
        memset(vis, 0, sizeof(vis));
        memset(time, 0, sizeof(time));
        for(i=0;i<n;i++){
            scanf("%d", &a);
            if(!vis[a])
                vis[a]=1;
            time[a]++;
            if(a>max)
                max=a;
        }
        for(i=0;i<=max;i++){
            if(vis[i]){
                printf("%lld %d", time[i], i);
                if(i!=max)
                    printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
/*************************************************************************************

Problem Description
Given N integers X1, X2, ..., Xn. Please output the sorted result. (Increasing order)

Input
The input includes multiple test cases. In each test case, the first line contains one integers N.
The next line contains N integers.

Hint:
The sorting algorithms in O(n lg n)  don¡¦t work.
To avoid Time Limit Exceeded in Input/Output process, try to use scanf / printf to replace cin / cout.

1 <= N <= 2*10^6
0 <= Xi <= 10^4

Output
The one line conatins many pairs. Every pair (pi,qi) means there are pi numbers whose value are qi.

Sample Input
5
1 4 1 1 4

Sample Output
3 1 2 4

****************************************************************************************/
