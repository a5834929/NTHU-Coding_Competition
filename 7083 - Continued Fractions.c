#include<stdio.h>

int main(void)
{
    int numer, denom, temp;
    int i, count;
    int table[10000]={0};

    while(EOF!=scanf("%d %d", &numer, &denom))
    {
        count=0;

        for(i=0;denom>0;i++)
        {
            table[i]=numer/denom;
            temp=denom;
            denom=numer-table[i]*temp;
            numer=temp;
            count++;
        }

        printf("[%d;", table[0]);

        for(i=1;i<count;i++)
        {
            printf("%d", table[i]);

            if(i!=count-1) printf(",");
        }

        printf("]");
        printf("\n");
    }

    return 0;
}

/****************************************************

Problem Description
令b0, b1, b2, ......, bn為一整數序列，其中b0大於等於0，其他數皆大於0。我們定義n階層的連續分數為：

以簡寫 [b0; b1, b2, ......, bn]來表示。舉例說明：對n=3的連續分數的簡寫 [2;3,1,4] 表示以下的式子：

寫一個程式讀入最後的分數的分子及分母，輸出此連續分數的簡寫。為了確保唯一性，bn > 1。

Input
每組測試資料一列，有2個整數a,b，分別代表分數的分子及分母（a,b > 0）。

Output
對每組測試資料，請輸出對應的連續分數的簡寫。

Sample Input
43 19
1 2

Sample Output
[2;3,1,4]
[0;2]

****************************************************/

