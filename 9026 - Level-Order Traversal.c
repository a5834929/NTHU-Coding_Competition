#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int matrix[1100][1100];
int queue[1100], visited[1100];

int main(void)
{
    int N, i, j;
    int n, root, a, b;
    int front, rear;

    scanf("%d", &N);

    for(i=1;i<=N;i++)
    {
        front=0;
        rear=0;
        memset(matrix, 0, sizeof(matrix));
        memset(visited, 0, sizeof(visited));
        scanf("%d %d", &n, &root);

        for(j=0;j<n-1;j++)
        {
            scanf("%d %d", &a, &b);
            matrix[a][b]=1;
            matrix[b][a]=1;
        }

        visited[root]=1;
        queue[rear]=root;
        rear++;
        while(front<rear)
        {
            for(j=1;j<=n;j++)
            {
                if(!visited[j])
                {
                    if(matrix[queue[front]][j])
                    {
                        visited[j]=1;
                        queue[rear]=j;
                        rear++;
                    }
                }
            }
            front++;
        }
        printf("Case %d:", i);
        for(j=0;j<rear;j++)
            printf(" %d", queue[j]);
        printf("\n");
        if(i<N)
            printf("\n");
    }

    return 0;
}

/***************************************************************

Problem Description
Given a tree G(V, E) and its root, print its level-order traversal,
where we visit all of the nodes at the same level before going to
the lower ones. Each node is labeled by a unique integer number,
and in case that the node has more than one child, the one who is
labeled by smaller number should be visited first.

Input
The first line of input is a single integer T (T ≤ 100),
denoting the number of test cases. Each test case started
with an integer pair N (N ≤ 1000) and R, indicating the
number of nodes and the root number respectively.
The following N - 1 lines contain pairs of integers
ui and vi (1 ≤ ui, vi ≤ N), each in a line,
which means ui and vi are adjacent.

Output
For each test case, output “Case i:” denoting the traversal
of i-th test case on a line. Then, for each visited node,
started from the root, print the labeled number.
Every two successive numbers are separated by a space characters.
Print a blank line between test cases.

Sample Input
2
3 1
1 2
1 3
5 5
1 2
4 5
3 5
5 2

Sample Output
Case 1: 1 2 3

Case 2: 5 2 3 4 1
***************************************************************/
