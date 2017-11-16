#include<stdio.h>
int queue[1001], stack[1001], order[1001], ans[1001];
int n_ans, front, top;

int main(){
    int N, n, i, j, m, flag;
    scanf("%d", &N);
    i=1;
    while(N--){
        n_ans=0;
        flag=1;
        scanf("%d", &n);
        for(j=0;j<n;j++)
            scanf("%d", &queue[j]);
        for(j=0;j<n;j++)
            scanf("%d", &order[j]);
        front=top=m=0;

        while(front<n){
            if(queue[front]!=order[m]){
                if(stack[top-1]!=order[m]){
                    stack[top]=queue[front];
                    front++;
                    top++;
                }
                else{
                    ans[n_ans]=stack[top-1];
                    top--;
                    n_ans++;
                    m++;
                }
            }
            else{
                if(stack[top-1]!=order[m]){
                    ans[n_ans]=queue[front];
                    front++;
                    n_ans++;
                    m++;
                }
                else{
                    ans[n_ans]=stack[top-1];
                    top--;
                    n_ans++;
                }
            }
        }
        while(top){
            if(order[m]==stack[top-1]){
                ans[n_ans]=stack[top-1];
                top--;
                n_ans++;
                m++;
            }
            else{
                flag=0;
                break;
            }
        }

        for(j=0;j<n;j++)
            if(ans[j]!=order[j]){
                flag=0;
                break;
            }

        printf("Case %d: ", i++);
        if(flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}

/*********************************************************************************************

Problem Description
Given a positive integer sequence a1, a2... an, whose elements are initially put in a queue Q in the given order.
Determine that if it is possible, using a stack S and two operations:

(1) pop the first element in Q and push it into S, and

(2) pop the top element in S,

to obtain the other given sequence b1, b2… bn, where bi represents the i-th element popped from S.
Note that “pop the first element in Q and push it into S” is considered as a single operation.

Input
The first line of the input contains an integer indicating the total number of test cases to follow.
Each test case is composed of three lines. The first line contains a single integer n (n ≤ 1000),
and each of the next two lines contains n integers, which respectively represents a1, a2… an, and b1, b2… bn.
The numbers in the sequence are distinct integers from 1 to n.

Output
For each test case, print the sequence number “Case i:” and then “Yes” or “No” following a single space
character to indicate if it is possible or not, in a line.

Sample Input
2
4
1 2 3 4
2 4 3 1
3
2 1 3
3 2 1

Sample Output
Case 1: Yes
Case 2: No

*********************************************************************************************/
