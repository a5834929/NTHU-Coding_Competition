#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int cmp(const void*p, const void*q);

typedef struct _p
{
    char num[105];
    int len;
}P;
P pnum[100010];
P nnum[100010];

int main(void)
{
    char str[10000];
    int N, p, n, i;

    scanf("%d", &N);
    while(1)
    {
        n=0;
        p=0;
        memset(pnum, 0, sizeof(P));
        memset(nnum, 0, sizeof(P));
        while(N--)
        {
            scanf("%s", str);

            if(isdigit(str[0]))
            {
                strcpy(pnum[p].num, str);
                pnum[p].len=strlen(str);
                p++;
            }
            else
            {
                strcpy(nnum[n].num, str);
                nnum[n].len=strlen(str);
                n++;
            }
        }
        qsort(pnum, p, sizeof(P), cmp);
        qsort(nnum, n, sizeof(P), cmp);

        if(n)
            for(i=n-1;i>=0;i--)
                printf("%s\n", nnum[i].num);
        if(p)
            for(i=0;i<p;i++)
                printf("%s\n", pnum[i].num);
        if(scanf("%d", &N)!=EOF)
            printf("\n");
        else
            break;
    }
    return 0;
}
int cmp(const void*p, const void*q)
{
    P a=*(P*)p, b=*(P*)q;
    if(a.len!=b.len) return (a.len<b.len)?-1:1;
    else if(strcmp(a.num, b.num)!=0) return (strcmp(a.num, b.num)<0)?-1:1;
    return 0;
}

/**********************************************************************

Problem Description
請將輸入的整數依照大小排列。

Input
有多組測資。每組測資第一行，有一個整數N (1<=N <=10^5)代表有幾個數字，接下來有
N 行，每行有一個整數Ai(-10^100<=Ai<=10^100)代表要排序的數字(不會有無效0 開頭或-0)

Output
對於每組測資請由小到大輸出所有數字，測資間請空一行

Sample Input
5
9999999999999999999999999999999999999999999999999999999999999999
1
2
3
4
3
9
-99
-9

Sample Output
1
2
3
4
9999999999999999999999999999999999999999999999999999999999999999

-99
-9
9

*********************************************************************/
