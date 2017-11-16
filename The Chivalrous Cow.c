#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int map[200][200], que[40000][2];

int main(void){

    int row, col, i, j;
    int front, rear, dx, dy;
    char c;
    freopen("pb-kcow.in", "r", stdin);
    freopen("out.txt", "w+", stdout);
    while(scanf("%d%d", &col, &row)!=EOF){
        memset(map, 0, sizeof(map));
        front=0;
        rear=0;
        getchar();
        for(i=0;i<row;i++){
            for(j=0;j<col;j++){
                scanf("%c", &c);
                if(c=='*')
                    map[i][j]=-1;
                else if(c=='.')
                    map[i][j]=0;
                else if(c=='K'){
                    map[i][j]=0;
                    que[rear][0]=i;
                    que[rear][1]=j;
                    rear++;
                }
                else if(c=='H'){
                    dx=i;
                    dy=j;
                }
            }
            getchar();
        }
        while(1){
            i=que[front][0];
            j=que[front][1];
            if(map[dx][dy]){
                printf("%d\n", map[dx][dy]);
                break;
            }
            else{
                if(i+2<row && j+1<col && map[i+2][j+1]!=-1 && !map[i+1][j+1]){
                    map[i+2][j+1]=map[i][j]+1;
                    que[rear][0]=i+2;
                    que[rear][1]=j+1;
                    rear++;
                }
                if(i+2<row && j-1>=0 && map[i+2][j-1]!=-1 && !map[i+2][j-1]){
                    map[i+2][j-1]=map[i][j]+1;
                    que[rear][0]=i+2;
                    que[rear][1]=j-1;
                    rear++;
                }
                if(i-2>=0 && j+1<col && map[i-2][j+1]!=-1 &&!map[i-2][j+1]){
                    map[i-2][j+1]=map[i][j]+1;
                    que[rear][0]=i-2;
                    que[rear][1]=j+1;
                    rear++;
                }
                if(i-2>=0 && j-1>=0 && map[i-2][j-1]!=-1 && !map[i-2][j-1]){
                    map[i-2][j-1]=map[i][j]+1;
                    que[rear][0]=i-2;
                    que[rear][1]=j-1;
                    rear++;
                }
                if(i+1<row && j+2<col && map[i+1][j+2]!=-1 && !map[i+1][j+2]){
                    map[i+1][j+2]=map[i][j]+1;
                    que[rear][0]=i+1;
                    que[rear][1]=j+2;
                    rear++;
                }
                if(i+1<row && j-2>=0 && map[i+1][j-2]!=-1 && !map[i+1][j-2]){
                    map[i+1][j-2]=map[i][j]+1;
                    que[rear][0]=i+1;
                    que[rear][1]=j-2;
                    rear++;
                }
                if(i-1>=0 && j+2<col && map[i-1][j+2]!=-1 && !map[i-1][j+2]){
                    map[i-1][j+2]=map[i][j]+1;
                    que[rear][0]=i-1;
                    que[rear][1]=j+2;
                    rear++;
                }
                if(i-1>=0 && j-2>=0 && map[i-1][j-2]!=-1 && !map[i-1][j-2]){
                    map[i-1][j-2]=map[i][j]+1;
                    que[rear][0]=i-1;
                    que[rear][1]=j-2;
                    rear++;
                }
                front++;
            }
        }
    }
    return 0;
}
