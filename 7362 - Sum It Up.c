#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DFS(int sum, int len, int x);
int S, N, flag, num[20], ans[20];
int main(){
    int i;

    while(scanf("%d%d", &S, &N)!=EOF && !(S==0 && N==0)){
        memset(ans, 0, sizeof(ans));
        for(i=0;i<N;i++)
            scanf("%d", &num[i]);
        printf("Sums of %d:\n", S);
        flag=1;
        DFS(0, 0, 0);
        if(flag)
            printf("NONE\n");
    }
    return 0;
}

void DFS(int sum, int len, int x){
    int i, temp=0;
    if(len>N)
        return;
    if(sum==S){
        flag=0;
        printf("%d", ans[0]);
        for(i=1;i<len;i++)
            printf("+%d", ans[i]);
        printf("\n");
        return;
    }
    else if(sum>S)
        return;
    for(i=x;i<N;i++){
        if(temp!=num[i]){
            temp=num[i];
            ans[len]=num[i];
            DFS(sum+num[i], len+1, i+1);
        }
    }
}
