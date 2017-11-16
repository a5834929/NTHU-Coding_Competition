#include<stdio.h>

int main(){
    int val[7]={0, 5, 10, 20, 50, 100, 200};
    int time[7]={0};
    int dp[502][502], i, j, dol, cen, mon;

    scanf("%d%d%d%d%d%d", &time[1], &time[2], &time[3], &time[4], &time[5], &time[6]);
    while(time[1]!=0 && time[2]!=0 && time[3]!=0 && time[4]!=0 && time[5]!=0 && time[6]!=0){
        scanf("%d.%d", &dol, &cen);
        mon=dol*100+cen;
        for(i=0;i<=500;i++)
            dp[1][i]=1;
        for(i=0;i<=7;i++)
            dp[i][0]=1;


        scanf("%d%d%d%d%d%d", &time[1], &time[2], &time[3], &time[4], &time[5], &time[6]);
    }

    return 0;
}
