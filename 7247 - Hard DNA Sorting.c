#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

int main(void)
{
    int level[10010];
    int n, m, i, j;
    int A, C, G, T;
    char dna[1000];

    scanf("%d %d", &n, &m);
    while(1)
    {
        memset(level, 0, sizeof(level));
        A=C=G=T=0;
        for(i=0;i<m;i++)
        {
            scanf("%s", dna);
            for(j=0;j<n;j++)
            {
                if(dna[j]=='A') A++;
                else if(dna[j]=='C') C++;
                else if(dna[j]=='G') G++;
                else if(dna[j]=='T') T++;
            }

            for(j=0;j<n;j++)
            {
                if(dna[j]=='A') A--;
                else if(dna[j]=='C')
                {
                    C--;
                    level[i]+=A;
                }
                else if(dna[j]=='G')
                {
                    G--;
                    level[i]=level[i]+A+C;
                }
                else if(dna[j]=='T')
                {
                    T--;
                    level[i]=level[i]+A+C+G;
                }
            }
        }

        qsort(level, m, sizeof(int), cmp);

        for(i=0;i<m;i++)
            printf("%d\n", level[i]);

        if(scanf("%d %d", &n, &m)!=EOF)
            printf("\n");
        else
            break;
    }

    return 0;
}

int cmp(const void*p, const void*q)
{
    int a=*(int*)p, b=*(int*)q;
    if(a!=b) return (a<b)?-1:1;
    return 0;
}

/************************************************

Problem Description
在一個字串中，「未排序」的程度是以各字元間彼此的大小關係來計算的。
例如在字串 DAABEC中，「未排序」的程度為 5，因為D比它右邊的4個字元大，
E比它右邊的1個字元大。而字串AACEDGG「未排序」的程度為 1（幾乎是快排序好的，
唯一的未排序發生在E和D之間），字串ZYXW「未排序」的程度為 6（剛好是完全排序的相反）。
現在你的任務是為許多的DNA字串來做排序。每個字串中僅含有A,C,G和T這4種字元。
排序的原則是根據各字串「未排序」的程度，由小到大輸出。在這裡每個字串的長度均相同。

Input
多組測資。每組測試資料的第一列含有2個正整數 n（0 < n <= 600）和 m（0 < m <= 10000），
n 代表字串的長度，m 代表字串的數目。接下來的 m 列，每列有一個長度為 n 的字串。

Output
對每組測試資料按照「未排序」的程度，由小到大輸出。各組測試資料之間請輸出一空白列。

Sample Input
10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT
2 3
TC
TT
TA

Sample Output
9
10
11
17
36
37

0
1
1

**************************************************/
