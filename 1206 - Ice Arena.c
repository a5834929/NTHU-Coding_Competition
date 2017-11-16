#include<stdio.h>
#include<string.h>
void BFS(int K, int I, int J);
int Legal(int a, int b);
typedef struct Q{
    int K, I, J;
}QUEUE;
QUEUE q[30030];
int vis[3][101][101], N, M;
int map[3][101][101], ans;
int move[4][2]={{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int main(){
    int T, i, j, k;

    scanf("%d", &T);
    while(T--){
        ans=0;
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &N, &M);
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                scanf("%d", &map[1][i][j]);
                map[0][i][j]=map[1][i][j]-1;
                map[2][i][j]=map[1][i][j]+1;
            }
        }
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                for(k=0;k<=2;k++){
                    if(vis[k][i][j]==0){
                        BFS(k, i, j);
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

void BFS(int K, int I, int J){
    QUEUE now, next;
    int i, k;
    int head, tail;
    head=tail=0;
    q[0].K=K;
    q[0].I=I;
    q[0].J=J;
    vis[K][I][J]=1;
    tail++;
    while(head<tail){
        now=q[head];
        head++;
        for(k=0;k<3;k++){
            next.K=k;
            for(i=0;i<4;i++){
                next.I=now.I+move[i][0];
                next.J=now.J+move[i][1];
                if(Legal(next.I, next.J) && vis[next.K][next.I][next.J]==0
                    && map[now.K][now.I][now.J]==map[next.K][next.I][next.J]){
                    q[tail]=next;
                    vis[next.K][next.I][next.J]=1;
                    tail++;
                }
            }
        }
    }
    if(tail>ans)
        ans=tail;
}

int Legal(int a, int b){
    if(a>=0 && a<N && b>=0 && b<M)
        return 1;
    return 0;
}
