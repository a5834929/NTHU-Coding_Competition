#include<stdio.h>

int main(void)
{
    int numer, denom, remain, quot, record1, record2;
    int i, j, count, cycle, cyclen, nondec;

    while(EOF!=scanf("%d %d", &numer, &denom))
    {
        int dec[10000]={0}, repeat[10000]={0}, countRemain[10000]={0};
        i=0;
        cycle=0;
        quot=numer/denom;
        remain=numer%denom;
        record1=quot;
        record2=numer;

        while(!cycle)
        {
            if(repeat[remain])
            {
                count=countRemain[remain];
                cyclen=i-count;
                cycle=1;
            }

            else
            {
                repeat[remain]=1;
                countRemain[remain]=i;
            }

            numer=remain*10;
            quot=numer/denom;
            remain=numer%denom;
            dec[i]=quot;
            i++;
        }

        printf("%d/%d = %d.", record2, denom, record1);

        nondec=(count>50)?50:count;
        for(j=0;j<nondec;j++) printf("%d", dec[j]);

        if(cyclen<50)
        {
            printf("(");
            for(j=count;j<(((i-1)<50)?(i-1):50);j++) printf("%d", dec[j]);
            printf(")");
        }

        else
        {
            printf("(");
            for(j=0;j<50;j++) printf("%d", dec[j]);
            printf("...)");
        }

        printf("\n");
        printf("   %d = number of digits in repeating cycle\n", cyclen);
        printf("\n");
    }

    return 0;
}

/**********************************************

Problem Description
1/33=0.030303030303…為一個循環小數，在這裡03這2個數字會永遠循環下去(cycle length=2)。

寫一個程式輸入分數的分子和分母然後算出其十進位小數表示法的循環節。
在此我們定義循環節為最先出現之最小長度的不斷重 複數字串。所以，
1/250=0.04000000…的循環節為（0），其cycle length=1。655/990=0.6616161616161616161…的循環節為（61），
其cycle length=2。

Input
每組測試資料一列，包含有2個數x,y，分別代表分子和分母。x為非負整數，y為正整數，且x,y<=3000

Output
對每一組測試資料，輸出其十進位的表示法及循環節的長度。以刮號將循環節表示出來。
如果循環節長度大於50，則只要輸出前50個，後面用...表示即可。每組測試資料後請輸出一空白列。
詳細格式請參考Sample Output。

Sample Input
76 25
5 43
1 397
1 1
0 558

Sample Output
76/25 = 3.04(0)
   1 = number of digits in repeating cycle

5/43 = 0.(116279069767441860465)
   21 = number of digits in repeating cycle

1/397 = 0.(00251889168765743073047858942065491183879093198992...)
   99 = number of digits in repeating cycle

1/1 = 1.(0)
   1 = number of digits in repeating cycle

0/558 = 0.(0)
   1 = number of digits in repeating cycle

**********************************************/
