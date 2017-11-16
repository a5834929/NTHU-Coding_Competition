#include<stdio.h>
#include<string.h>
int MIN(int a, int b);
int map[20][150], dp[20][150];
int path[150], n_p;
int N, M;
int main(){
    int i, j, b_i, b_j, min;

    while(scanf("%d%d", &N, &M)!=EOF){
        memset(dp, 0, sizeof(dp));
        memset(path, -1, sizeof(path));
        for(i=0;i<N;i++){
            for(j=0;j<M;j++)
                scanf("%d", &map[i][j]);
            dp[i][M-1]=map[i][M-1];
        }

        for(j=M-1;j>0;j--)
            for(i=0;i<N;i++)
                dp[i][j-1]=map[i][j-1]+MIN(dp[(N+i-1)%N][j], MIN(dp[i][j], dp[(N+i+1)%N][j]));

        min=dp[0][0];
        b_i=N-1;
        for(i=0;i<N;i++){
            if(min>dp[i][0]){
                min=dp[i][0];
                b_i=i;
            }
            if(min==dp[i][0])
                b_i=(b_i<i)?b_i:i;
        }
        path[0]=b_i;
        n_p=1;
        for(b_j=0;b_j<M-1;b_j++){
            if(MIN(dp[(N+b_i-1)%N][b_j+1], MIN(dp[b_i][b_j+1], dp[(N+b_i+1)%N][b_j+1]))==dp[(N+b_i-1)%N][b_j+1]){
                if(path[n_p]==-1)
                    path[n_p]=(N+b_i-1)%N;
                else if(path[n_p]>((N+b_i-1)%N))
                    path[n_p]=(N+b_i-1)%N;
            }
            if(MIN(dp[(N+b_i-1)%N][b_j+1], MIN(dp[b_i][b_j+1], dp[(N+b_i+1)%N][b_j+1]))==dp[b_i][b_j+1]){
                if(path[n_p]==-1)
                    path[n_p]=b_i;
                else if(path[n_p]>b_i)
                     path[n_p]=b_i;
            }
            if(MIN(dp[(N+b_i-1)%N][b_j+1], MIN(dp[b_i][b_j+1], dp[(N+b_i+1)%N][b_j+1]))==dp[(N+b_i+1)%N][b_j+1]){
                if(path[n_p]==-1)
                    path[n_p]=(N+b_i+1)%N;
                else if(path[n_p]>((N+b_i+1)%N))
                    path[n_p]=(N+b_i+1)%N;
            }
            b_i=path[n_p];
            n_p++;
        }
        printf("%d",path[0]+1);
        for(i=1;i<n_p;i++)
            printf(" %d", path[i]+1);
        printf("\n%d\n", min);
    }
    return 0;
}

int MIN(int a, int b){
    return (a<b)?a:b;
}

