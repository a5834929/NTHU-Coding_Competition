#include<stdio.h>
#include<string.h>
typedef struct howmany{
    int num;
    int count;
}Hmany;

Hmany numb[100000];

int main(void)
{
    int n, q, temp;
    int i, k, b;
    int left, right, mid, flag;

    while(scanf("%d %d", &n, &q)!=EOF)
    {
        memset(&numb,0,sizeof(numb));

        k=0;
        for(i=0;i<n;i++)
        {
            if(i==0)
            {
                scanf("%d", &numb[k].num);
                numb[k].count=1;
                k++;
            }
            else if(i>0)
            {
                scanf("%d", &temp);
                if(temp!=numb[k-1].num)
                {
                    numb[k].num=temp;
                    numb[k].count=1;
                    k++;
                }
                else numb[k-1].count++;
            }
        }

        for(i=0;i<q;i++)
        {
            left=0;
            right=k-1;
            flag=0;

            scanf("%d", &b);

            while(left<=right)
            {
                mid=(left+right)/2;
                if(numb[mid].num==b)
                {
                    flag=1;
                    break;
                }
                if(numb[mid].num>b) right=mid-1;
                if(numb[mid].num<b) left=mid+1;
            }
            if(flag) printf("%d\n", numb[mid].count);
            else printf("0\n");
        }
    }

    return 0;
}

/*******************************************************

Problem Description
給一個排序好(從小到大)的數列，然後會有多個問題，每個問題會問一個數字在這個數列出現幾次。

Input
多組測資，每組測資第一行有兩個正整數，n(n<100000)表示數列的數量，以及q(q<100000)表示問題數量。
接下來n行，有n個整數(int範圍)表示這個數列。
接下來q行，每行有一個整數(int範圍)代表一個問題

Output
對於每個問題請輸出這個數字出現在數列中幾次(沒出現是0次)

Sample Input
5 3
1
2
5
5
5
1
5
6

Sample Output
1
3
0



********************************************************/
