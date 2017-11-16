#include<stdio.h>

int main(void)
{
    int N, S, palin, num, check;
    int i, j, k, numo, count;

    while(scanf("%d %d", &N, &S)!=EOF)
    {
        numo=S+1;
        count=0;

        while(count<N)
        {
            int numb[100]={0};
            palin=0;


            for(i=2;i<=10;i++)
            {
                check=1;
                num=numo;
                j=0;
                while(num)
                {
                    numb[j]=num%i;
                    j++;
                    num/=i;
                }

                for(k=0;k<j;k++)
                {
                    if(numb[k]!=numb[j-1-k])
                    {
                        check=0;
                        break;
                    }

                }
                if(check) palin++;

                if(palin==2) break;

            }

            if(palin==2)
            {
                printf("%d\n", numo);
                count++;
            }
            numo++;
        }
    }
    return 0;
}

/**************************************************

Problem Description
如果一個數字從左往右讀和從右往左讀都是一樣，那麼這個數字就叫做“回文數”。
例如，12321就是一個回文數，而77778就不是。當然，回文數的首和尾都應是非零的，因此0220就不是回文數。

事實上，有一些數（如21），在十進制時不是回文數，但在其它進制（如二進制時為10101）時就是回文數。

寫一個程式，讀入兩個十進制數N(1≤N≤15),S(0 < 𝑆 < 10000)然後找出前 N 個滿足大於 S 且
在兩種或兩種以上進制(二進制至十進制)上是回文數的十進 制數,輸出到文件上。

本問題的解決方案不需要使用大於 4 Bytes 的整數

Input
有多組測資，每組測資有用空格隔開的兩個數N和S。

Output
N行, 每行一個滿足上述要求的數，並按從小到大的順序輸出。

Sample Input
3 25

Sample Output
26
27
28

****************************************************/
