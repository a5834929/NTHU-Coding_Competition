#include<stdio.h>
#include<string.h>

int main(void)
{
    int str[1000]={0}, i, j, k, count;
    char ch;

    while(scanf("%d%c", &str[0], &ch)!=EOF)
    {
        count=0;
        i=1;
        while(ch!='\n')
        {
            scanf("%d%c", &str[i++], &ch);
        }

        for(j=0;j<i;j++)
        {
            for(k=j;k<i;k++)
            {
                if(str[j]>str[k]) count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}

/***********************************************************

Problem Description
假如在一個數列中，a的順序在b的前面，但是a比b還大，
那我們就稱(a, b)為逆序數對(Inversion Pair)。只要我們計算
一個數列Inversion Pair的數量，就可以知道這數列最少需要幾次
左右互換才能夠排序好。現在給你數列，請算出Inversion Pair數量。

Input
多組測資。
每組測資有一行，每一行中有多個整數(int範圍)表示一個數列。
相鄰兩個整數以一個空白隔開，每一行整數最多有1000個。

Output
對於每組測資請輸出Inversion Pair的數量

Sample Input
1 2 3
3 2 1
4 3 2 1
1 1 1 1

Sample Output
0
3
6
0

***********************************************************/
