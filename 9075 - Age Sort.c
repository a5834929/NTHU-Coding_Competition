#include<stdio.h>
#include<string.h>

int main(){
    int n, time[101], i, max, a;
    while(scanf("%d", &n)!=EOF && n){
        max=0;
        memset(time, 0, sizeof(time));
        while(n--){
            scanf("%d", &a);
            time[a]++;
            if(a>max)
                max=a;
        }
        for(i=1;i<=max;i++){
            if(time[i]){
                while(time[i]--){
                    if(i==max && !time[i])
                        printf("%d", i);
                    else
                        printf("%d ", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}

/****************************************************************

Problem Description
You are given the ages (in years) of all people of a country
with at least 1 year of age. You know that no individual in that
country lives for 100 or more years. Now, you are given a very
simple task of sorting all the ages in ascending order.

Input
There are multiple test cases in the input file. Each case starts
with an integer n (0<n<=2000000), the total number of people.
In the next line, there are n integers indicating the ages.
Input is terminated with a case where n = 0. This case should not be processed.

Output
For each case, print a line with n space separated integers.
These integers are the ages of that country sorted in ascending order.


Sample Input
5
3 4 2 1 5
5
2 3 2 3 1
0

Sample Output
1 2 3 4 5
1 2 2 3 3

*****************************************************************/
