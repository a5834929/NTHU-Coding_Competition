#include<stdio.h>
void DFS(int i);
int n, m, num;
int comb[12]={0};

int main(void)
{
    int i;

    scanf("%d %d", &n, &m);
    while(n && m)
    {
        num=0;
        for(i=1;i<=n;i++) DFS(i);

        scanf("%d %d", &n, &m);
        if(n&&m) printf("\n");
    }

    return 0;
}

void DFS(int i)
{
    int j;
    comb[num++]=i;

    if(num==m)
    {
        for(j=0;j<num;j++) printf("%d%c", comb[j], (j<num-1)?' ':'\n');
        num--;
        return;
    }

    for(j=i+1;j<=n;j++) DFS(j);
    num--;
}


/***************************************************

Problem Description
有n個東西，編號由1至n，請輸出n個東西取m個東西的所有組合

Input
有多組測資，每組測資有兩個正整數n(0<n<=10)與m(0<m<=n)，當n=0且m=0的時候結束測資。



Output
對每一筆測試資料，輸出其所有可能的組合，每個組合一行。
請注意輸出組合的順序需由小到大排列。測試資料之間請空一行。請參考Sample Output。

Sample Input
3 2
5 5
2 1
0 0

Sample Output
1 2
1 3
2 3

1 2 3 4 5

1
2

******************************************************/
