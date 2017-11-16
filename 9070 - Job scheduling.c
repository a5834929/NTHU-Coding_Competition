#include<stdio.h>
#include<string.h>
int map[11][11], in[11], vis[11], ans;
void dfs(int x, int P);
int main(){
    int i, N, P, E, a, b;

    scanf("%d", &N);
    while(N--){
        ans=0;
        memset(in, 0, sizeof(in));
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &P, &E);
        for(i=0;i<E;i++){
            scanf("%d%d", &a, &b);
            map[a][b]=1;
            in[b]++;
        }
        dfs(0, P);
        printf("%d\n", ans);
    }
    return 0;
}

void dfs(int x, int P){
    int i, j;

    if(x==P){
        ans++;
        return;
    }
    for(i=1;i<=P;i++){
        if(in[i]==0 && vis[i]==0){
            for(j=1;j<=P;j++){
                if(map[i][j])
                    in[j]--;
            }
            vis[i]=1;
            dfs(x+1, P);
            for(j=1;j<=P;j++){
                if(map[i][j])
                    in[j]++;
            }
            vis[i]=0;
        }
    }
}

/********************************************************************************

Problem Description
There are N jobs (labeled from 1 to N) that you have to schedule,
and some jobs are related to other jobs.
For example, if job No.3 is related to job No.2,
then job No.3 can only be done after job No.2 is done.
Output the number of all possible scheduling.

Input
The first line contains a positive integer T (T <= 20),
which indicates how many cases in the input.
Each case starts with two positive integers N and M (1 <= N <= 10),
and N denotes the amount of the job.
The next M lines contain the relationship among jobs.
Each line contains two positive integers A and B,
separated by a single space, denoting A is related to B.
Each case is separated by a blank line.

Output
The output contains one line for each test case. Each line contains an integer,
which is the number of all possible ways.

Sample Input
3
3 2
2 3
3 1

3 2
1 3
1 2

3 3
1 2
2 3
3 1

Sample Output
1
2
0

********************************************************************************/
