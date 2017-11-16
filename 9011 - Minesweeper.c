#include<stdio.h>
#include<string.h>

int main(){
    int N, i, j, k;
    int mat[101][101], ans[101][101];
    int move[8][2]={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    while(scanf("%d", &N)!=EOF){
        memset(ans, 0, sizeof(ans));
        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                scanf("%d", &mat[i][j]);

        for(i=0;i<N;i++)
            for(j=0;j<N;j++)
                for(k=0;k<8;k++)
                    if(i+move[k][0]>=0 && i+move[k][0]<N && j+move[k][1]>=0 && j+move[k][1]<N)
                        if(mat[i+move[k][0]][j+move[k][1]])
                            ans[i][j]++;
        for(i=0;i<N;i++){
            printf("%d", ans[i][0]);
            for(j=1;j<N;j++)
                printf(" %d", ans[i][j]);
            printf("\n");
        }
    }
    return 0;
}

/**************************************************************************

Problem Description
 The problem is about minesweeper. Given an N*N matrix A whose elements are either 0 or 1.
 Output the another N*N matrix B. Every element in B is the sum of the adjacency ¡§8¡¨ elements
 in the same location in A. If an element is on the boundary, the adjacency elements may not be ¡§8¡¨.

Input
The input includes multiple test cases. In each test case, the first line contains one integer N.
The next N lines follow. Every line contains N elements which are either 1 or 0.

1 <= N <=100

Output
Output N lines. Every line contains N integers. Every two numbers are separated by single space.

Sample Input
3
0 1 1
1 1 0
0 1 0

Sample Output
3 3 2
3 4 4
3 2 2

**************************************************************************/
