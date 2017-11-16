#include<stdio.h>

int main(void)
{
    int num, rela, i, j, k, temp;

    scanf("%d", &num);

    for(i=0;i<num;i++)
    {
        int door[1000]={0}, door_max=0;
        int dist_sum=0, dist;

        scanf("%d", &rela);

        for(j=0;j<rela;j++)
        {
            scanf("%d", &door[j]);
            door_max=(door[j]>door_max)?door[j]:door_max;
        }

        for(j=rela-1;j>0;j--)
        {
            for(k=0;k<j;k++)
            {
                if(door[k]>door[k+1])
                {
                    temp=door[k];
                    door[k]=door[k+1];
                    door[k+1]=temp;
                }
            }
        }

        if(rela%2==1)
        {
            if(rela==1) printf("1\n");

            else
            {
                for(j=0;j<rela;j++)
                {
                    if(door[j]>door[rela/2]) dist=door[j]-door[rela/2];
                    else dist=door[rela/2]-door[j];
                    dist_sum+=dist;
                }
                printf("%d\n", dist_sum);
            }
        }

        else
        {
            for(j=0;j<rela;j++)
            {
                if(door[j]>door[(rela/2)-1]) dist=door[j]-door[(rela/2)-1];
                else dist=door[(rela/2)-1]-door[j];
                dist_sum+=dist;
            }
            printf("%d\n", dist_sum);
        }
    }

    return 0;
}

/***************************************************

Problem Description
世界聞名的黑社會老大Vito Deadstone要搬到紐約來了。
在那裡他有一個大家族，並且他們都住在Lamafia大道上。
因為Vito時常要拜訪所有的親戚，他想要找一間離他們最近的房子，
也就是說他希望從他的家到所有的親戚的家的距離的和為最小。

他恐嚇你寫一個程式來幫助幫助他解決這個問題。

Input
輸入的第一列有一個整數代表以下有多少組測試資料。

每組測試資料一列，第一個整數 r（0 < r < 500），代表他親戚的數目。
接下來的r個整數s1,s2,......sr為這些親戚房子的門牌號碼（0 < si <30000）。
注意：有些親戚的門牌號碼會相同。

Output
對每一組測試資料，輸出從他的新家到所有的親戚的家的距離的和為最小為多少。
2個門牌號碼si、sj的距離為si-sj的絕對值。

Sample Input
3
2 2 4
3 2 4 6
4 2 1 999 5

Sample Output
2
4
1001

****************************************************/
