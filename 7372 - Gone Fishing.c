#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int i, j, lake, time, left_t, max, count;
    int fish[30], de[30], spend[30], tmp[30], ans[30], l_fish[30];
    scanf("%d", &lake);
    while(lake){
        scanf("%d", &time);
        time=time*12;
        memset(fish, 0, sizeof(fish));
        memset(l_fish, 0, sizeof(l_fish));
        memset(de, 0, sizeof(de));
        memset(spend, 0, sizeof(spend));
        memset(ans, -1, sizeof(ans));
        for(i=1;i<=lake;i++)
            scanf("%d", &l_fish[i]);
        for(i=1;i<=lake;i++)
            scanf("%d", &de[i]);
        for(i=2;i<=lake;i++){
            scanf("%d", &spend[i]);
            spend[i]+=spend[i-1];
        }
        for(i=1;i<=lake;i++){
            left_t=time-spend[i];
            memset(tmp, 0, sizeof(tmp));
            for(j=1;j<=lake;j++)
                fish[j]=l_fish[j];
            for(count=0;count<left_t;count++){
                max=1;
                for(j=1;j<=i;j++)
                    if(fish[max]<fish[j])
                        max=j;
                tmp[max]++;
                tmp[0]+=fish[max];
                if(fish[max]-de[max]<0)
                    fish[max]=0;
                else fish[max]-=de[max];
            }
            if(tmp[0]>ans[0])
                for(j=0;j<=lake;j++)
                    ans[j]=tmp[j];
        }
        printf("%d", ans[1]*5);
        for(i=2;i<=lake;i++)
            printf(", %d", ans[i]*5);
        printf("\n");
        printf("Number of fish expected: %d\n", ans[0]);
        scanf("%d", &lake);
        if(lake)
            printf("\n");
    }
    return 0;
}
