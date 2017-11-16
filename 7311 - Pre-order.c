#include<stdio.h>
typedef struct _P{
    int left, right;
}TREE;
TREE tree[105];
void dfs(int p);

int main(){
    int n, root, i, x;

    while(scanf("%d%d", &n, &root)!=EOF){
        for(i=0;i<n;i++){
            scanf("%d", &x);
            scanf("%d%d", &tree[x].left, &tree[x].right);
        }
        printf("%d", root);
        dfs(root);
        printf("\n");
    }
    return 0;
}

void dfs(int p){
    if(tree[p].left!=-1){
        printf(" %d", tree[p].left);
        dfs(tree[p].left);
    }
    if(tree[p].right!=-1){
        printf(" %d", tree[p].right);
        dfs(tree[p].right);
    }
    return;
}

/****************************************************************************************

Problem Description
Giving a binary tree, please find the pre-order traversal of the tree

Input
The first line of each case consists of two positive integers n (n<=100)
and r denoting the number of nodes and the root of the tree.
The next n line consists of three integers denoting the number of the node,
left child, and right child (-1 denoting NULL).

Output
Print the pre-order traversal of the tree.

Sample Input
4 1
1 2 3
2 -1 -1
3 4 -1
4 -1 -1

Sample Output
1 2 3 4

*****************************************************************************************/
