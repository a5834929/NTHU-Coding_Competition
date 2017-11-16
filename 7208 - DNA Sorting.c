#include<stdio.h>
#include<string.h>

typedef struct gene{
    char order[60];
    int count;
}DNA;

int main(void)
{
    int n, len, num;
    int i, j, k;

    scanf("%d\n\n", &n);

    while(n--)
    {
        int temp;
        DNA dna[110];
        char Temp[60];
        scanf("%d %d", &len, &num);

        for(i=0;i<num;i++) dna[i].count=0;

        for(i=0;i<num;i++) scanf("%s", dna[i].order);

        for(k=0;k<num;k++)
        {
            for(i=0;i<len;i++)
            {
                for(j=i;j<len;j++)
                {
                    if(dna[k].order[i]>dna[k].order[j]) dna[k].count++;
                }
            }
        }

        for(i=0;i<num-1;i++)
        {
            for(j=0;j<num-1-i;j++)
            {
                if(dna[j].count>dna[j+1].count)
                {
                    temp=dna[j+1].count;
                    dna[j+1].count=dna[j].count;
                    dna[j].count=temp;

                    strcpy(Temp, dna[j+1].order);
                    strcpy(dna[j+1].order, dna[j].order);
                    strcpy(dna[j].order, Temp);
                }
            }
        }

        for(i=0;i<num;i++) printf("%s\n", dna[i].order);

        if(n) printf("\n");
    }

    return 0;
}

/**********************************************************

Problem Description
在一個字串中，「未排序」的程度是以各字元間彼此的大小關係來計算的。
例如在字串 DAABEC中，「未排序」的程度為 5，因為D比它右邊的4個字元大，
E比它右邊的1個字元大。而字串AACEDGG「未排序」的程度為 1（幾乎是快排序好的，
唯一的未排序發生在E和D之間），字串ZYXW「未排序」的程度為 6（剛好是完全排序的相反）。

現在你的任務是為許多的DNA字串來做排序。每個字串中僅含有A,C,G和T這4種字元。
排序的原則是根據各字串「未排序」的程度，由小到大輸出。在這裡每個字串的長度均相同。

Input
輸入的第一列有一個整數代表以下有幾組測試資料。每組測試資料的第一列含有2個正整數
n（0 < n <= 50）和 m（0 < m <= 100），n 代表字串的長度，m 代表字串的數目。
接下來的 m 列，每列有一個長度為 n 的字串。

第一列及第一組測試資料，以及各組測試資料間均有一空白列。請參考Sample Input。

Output
對每組測試資料按照「未排序」的程度，由小到大輸出各字串。假如有不只2個字串「未排序」
的程度相同，則按照它們在輸入中的順序輸出。

各組測試資料之間請輸出一空白列，輸出格式請參考Sample Output。

Sample Input
2

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
CCCGGGGGGA
AACATGAAGG
GATCAGATTT
ATCGATGCAT
TTTTGGCCAA
TTTGGCCAAA

TT
TC
TA

**********************************************************/
