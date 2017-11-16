#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void SPFA1(void);
void SPFA2(void);
int cmp1(const void*p, const void*q);
int cmp2(const void*p, const void*q);
typedef struct _P{
    int from, to, time;
}EDGE;
EDGE edge[100010];
int N, M, X;
int se1[1001][2], se2[1001][2], time1[1001], time2[1001], q[1001], inq[1001];
int main(){
    int i, max;

    while(scanf("%d%d%d", &N, &M, &X)!=EOF){
        max=0;
        memset(time1, -1, sizeof(time1));
        memset(time2, -1, sizeof(time2));
        memset(se1, -1, sizeof(se1));
        memset(se2, -1, sizeof(se2));
        for(i=0;i<M;i++)
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].time);
        qsort(edge, M, sizeof(EDGE), cmp1);
        for(i=0;i<M;i++){
            if(se1[edge[i].from][0]==-1)
                se1[edge[i].from][0]=i;
            se1[edge[i].from][1]=i;
        }
        SPFA1();
        qsort(edge, M, sizeof(EDGE), cmp2);
        for(i=0;i<M;i++){
            if(se2[edge[i].to][0]==-1)
                se2[edge[i].to][0]=i;
            se2[edge[i].to][1]=i;
        }
        SPFA2();
        for(i=1;i<=N;i++){
            time1[i]+=time2[i];
            if(time1[i]>max)
                max=time1[i];
        }
        printf("%d\n", max);
    }
    return 0;
}

int cmp1(const void*p, const void*q){
    EDGE a=*(EDGE*)p, b=*(EDGE*)q;
    if(a.from!=b.from) return (a.from<b.from)?-1:1;
    else if(a.to!=b.to) return (a.to<b.to)?-1:1;
    return 0;
}

int cmp2(const void*p, const void*q){
    EDGE a=*(EDGE*)p, b=*(EDGE*)q;
    if(a.to!=b.to) return (a.to<b.to)?-1:1;
    else if(a.from!=b.from) return (a.from<b.from)?-1:1;
    return 0;
}

void SPFA1(void){
    int i, head, tail, now, next;
    head=tail=0;
    q[0]=X;
    inq[X]=1;
    tail++;
    time1[X]=0;
    while(head<tail){
        now=q[head%N];
        head++;
        inq[now]=0;
        for(i=se1[now][0];i<=se1[now][1] && se1[now][0]!=-1;i++){
            next=edge[i].to;
            if(time1[now]+edge[i].time<time1[next] || time1[next]==-1){
                time1[next]=time1[now]+edge[i].time;
                if(inq[next]==0){
                    q[tail%N]=next;
                    inq[next]=1;
                    tail++;
                }
            }
        }
    }
}

void SPFA2(void){
    int i, head, tail, now, next;
    head=tail=0;
    q[0]=X;
    inq[X]=1;
    tail++;
    time2[X]=0;
    while(head<tail){
        now=q[head%N];
        head++;
        inq[now]=0;
        for(i=se2[now][0];i<=se2[now][1] && se2[now][0]!=-1;i++){
            next=edge[i].from;
            if(time2[now]+edge[i].time<time2[next] || time2[next]==-1){
                time2[next]=time2[now]+edge[i].time;
                if(inq[next]==0){
                    q[tail%N]=next;
                    inq[next]=1;
                    tail++;
                }
            }
        }
    }
}

/*****************************************************************************

Problem Description
One cow from each of N farms (1 ≤ N ≤ 1000) conveniently numbered 1..N is going to
attend the big cow party to be held at farm #X (1 ≤ X ≤ N).
A total of M (1 ≤ M ≤ 100,000) unidirectional (one-way roads connects pairs of farms;
road i requires Ti (1 ≤ Ti ≤ 100) units of time to traverse.
Each cow must walk to the party and, when the party is over, return to her farm.
Each cow is lazy and thus picks an optimal route with the shortest time.
A cow's return route might be different from her original route to the party
since roads are one-way.
Of all the cows, what is the longest amount of time a cow must spend walking
to the party and back?

Input
Line 1: Three space-separated integers, respectively: N, M, and X
Lines 2..M+1: Line i+1 describes road i with three space-separated integers:
Ai, Bi, and Ti. The described road runs from farm Ai to farm Bi,
requiring Ti time units to traverse.

Output
Line 1: One integer: the maximum of time any one cow must walk.

Sample Input
4 8 2
1 2 4
1 3 2
1 4 7
2 1 1
2 3 5
3 1 2
3 4 4
4 2 3

Sample Output
10

******************************************************************************/
