#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DFS(int now);
int adj[1001][1001];

int main(void)
{
    int i, rela;
    int root, a, b;

    while(scanf("%d", &rela)!=EOF && rela)
    {
        memset(adj, 0, sizeof(adj));
        for(i=0;i<rela;i++)
        {
            scanf("%d %d", &a, &b);
            adj[a][b]=1;
        }
        scanf("%d", &root);
        printf("%d", root);
        for(i=root;i<=1000;i++)
            DFS(i);

        printf("\n");

    }

    return 0;
}

void DFS(int now)
{
    int i;
    for(i=1;i<=1000;i++)
    {
        if(adj[now][i])
        {
            adj[now][i]=0;
            printf(" %d", i);
            DFS(i);
        }
    }
}

/******************************************************
Problem Description
Given the relationship of the nodes in a tree, construct
the tree and output it in the pre-order.  Each node has
unique integer identification (ID), but all IDs may not
be consecutive.

Input
There are multiple test cases.  Each test case begins with
an integer N (1 <= N <=1000), denoting the number of relations
in the tree.  In the following N lines, each line contains
two integers a and b (1 <= a,b <= 1000), which means node a
is node b¡¦s parent.   After that, the next line contains an
integer R, which represents the root of the tree.
You can assume that all the nodes will be on the same tree.
The input is terminated by N = 0.

Output
For each test case, print the pre-order of the tree.
In each level, traverse the node with smaller ID first.

Sample Input
3
1 2
1 4
1 3
1
5
7 3
3 4
3 5
3 6
7 2
7
0

Sample Output
1 2 3 4
7 2 3 4 5 6
************************************************************/
