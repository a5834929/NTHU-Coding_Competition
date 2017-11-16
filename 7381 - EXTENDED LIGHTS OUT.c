#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int map[10][10], state[10][10];
int ans[10][10], flag;
void out(int i, int j);
void DFS(int i);
int main(){
    int I, T, i, j, k, bit;

    scanf("%d", &T);
    for(I=1;I<=T;I++){
        for(i=0;i<5;i++)
            for(j=0;j<6;j++){
                scanf("%d", &map[i][j]);
                state[i][j]=map[i][j];
            }
        for(k=0;k<64;k++){
            flag=1;
            memset(ans, 0, sizeof(ans));
            for(i=0;i<5;i++)
                for(j=0;j<6;j++)
                    state[i][j]=map[i][j];
            for(j=0;j<6;j++){
                bit=(((1<<j)&k)==(1<<j));
                if(bit)
                    out(0, 5-j);
            }
            DFS(1);
            if(flag)
                break;
        }
        printf("PUZZLE #%d\n", I);
        for(i=0;i<5;i++)
            for(j=0;j<6;j++)
                printf("%d%c", ans[i][j], (j<5)?' ':'\n');
    }
    return 0;
}

void out(int i, int j){
    ans[i][j]=1;
    state[i][j]=1-state[i][j];
    if(j-1>=0)
        state[i][j-1]=1-state[i][j-1];
    if(j+1<6)
        state[i][j+1]=1-state[i][j+1];
    if(i-1>=0)
        state[i-1][j]=1-state[i-1][j];
    if(i+1<6)
        state[i+1][j]=1-state[i+1][j];
}

void DFS(int i){
    int j;
    for(j=0;j<6;j++)
        if(state[i-1][j])
            out(i, j);
    if(i==4){
        for(j=0;j<6;j++)
            if(state[4][j]){
                flag=0;
                break;
            }
        return;
    }
    DFS(i+1);
}
