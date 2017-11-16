#include<stdio.h>

int main(void)
{
    int num, height, freq;
    int cnt1,cnt2,cnt3,cnt4;

    scanf("%d", &num);

    for(cnt1=0;cnt1<num;cnt1++)
    {
        scanf("%d %d", &height, &freq);

        for(cnt2=0;cnt2<freq;cnt2++)
        {
            for(cnt3=0;cnt3<height;cnt3++)
            {
                for(cnt4=0;cnt4<cnt3+1;cnt4++)
                {
                    printf("%d", cnt3+1);
                }
                printf("\n");
            }

            for(cnt3=height;cnt3>1;cnt3--)
            {
                for(cnt4=0;cnt4<cnt3-1;cnt4++)
                {
                    printf("%d", cnt3-1);
                }
                printf("\n");
            }
            if(cnt2<freq-1) printf("\n");
        }
        if(cnt1<num-1) printf("\n");
    }
    return 0;
}

/************************************************

Problem Description
在這個問題中，根據所給的振幅(Amplitude)及頻率(Frequency)，
你的程式要產生這樣的波。

Input
輸入的第一列有一個整數n，代表有幾組測試資料。接下來每組測試資料有2列，
各有1個正整數（A、F），A代表振幅（A<=9），F代表頻率。

第一列以及各組測試資料間皆有一空白行。請參考Sample input。

Output
每組測試資料請輸出F個波，每個波振幅的水平高度為A。波本身是以其"高度"的
內容所組成。每個波之間以一空白行分隔開來。

測試資料間也以一空白行分開。

請參考sample output。

Sample Input
2

3
2

5
3

Sample Output
1
22
333
22
1

1
22
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1

1
22
333
4444
55555
4444
333
22
1
*************************************************/
