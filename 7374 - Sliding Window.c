#include<stdio.h>
#include<stdlib.h>
int arr[200010], mina[200010], maxa[200010];
int minI, maxI, range;
int main(){
    int N, i, j, min, max;

    while(scanf("%d", &N)!=EOF){
        minI=maxI=0;
        scanf("%d", &range);
        for(i=1;i<=N;i++)
            scanf("%d", &arr[i]);
        for(i=1;i+range-1<=N;i++){
            j=0;
            min=arr[i];
            max=arr[i];
            while(j<range){
                min=(min<arr[i+j])?min:arr[i+j];
                max=(max>arr[i+j])?max:arr[i+j];
                j++;
            }
            mina[minI++]=min;
            maxa[maxI++]=max;
        }
        for(i=0;i<minI;i++)
            printf("%d%c", mina[i], (i<minI-1)?' ':'\n');
        for(i=0;i<maxI;i++)
            printf("%d%c", maxa[i], (i<maxI-1)?' ':'\n');
    }
    return 0;
}
