#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int beats[50010]={0};
int note[50001]={0};

int main(void){
    int N, Q, i, j, x;

    freopen("pc-mnotes.in", "r", stdin);
    freopen("out.txt", "w+", stdout);
    while(scanf("%d %d", &N, &Q)!=EOF){
        for(i=1;i<=N;i++){
            scanf("%d", &x);
            beats[i]=beats[i-1]+x;
            for(j=beats[i-1];j<beats[i];j++)
                note[j]=i;
        }
        while(Q--){
            scanf("%d", &x);
            printf("%d\n", note[x]);
        }
    }
    return 0;
}
