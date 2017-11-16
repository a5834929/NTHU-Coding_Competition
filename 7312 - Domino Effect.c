#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void SPFA(void);
void TIME(void);
int cmp(const void*p, const void*q);
typedef struct _P{
    int from, to;
    int time;
}EDGE;
EDGE edge[500010];
int se[600][2], dis[600], q[600], inq[600];
int N, M, p1, p2, flag, sys=0;
double max;
int main(){
    int i;

    while(scanf("%d%d", &N, &M)!=EOF && !(M==0 && N==0)){
        sys++;
        for(i=0;i<2*M;i+=2){
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].time);
            edge[i+1].from=edge[i].to;
            edge[i+1].to=edge[i].from;
            edge[i+1].time=edge[i].time;
        }
        qsort(edge, 2*M, sizeof(EDGE), cmp);
        memset(se, -1, sizeof(se));
        memset(dis, -1, sizeof(dis));
        for(i=0;i<2*M;i++){
            if(se[edge[i].from][0]==-1)
                se[edge[i].from][0]=i;
            se[edge[i].from][1]=i;
        }
        SPFA();
        TIME();
        if(flag==0){
            printf("System #%d\n", sys);
            printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", max, p1);
        }

        else{
            printf("System #%d\n", sys);
            printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n", max, p1, p2);
        }
    }
    return 0;
}

int cmp(const void*p, const void*q){
    EDGE a=*(EDGE*)p, b=*(EDGE*)q;
    if(a.from!=b.from) return (a.from<b.from)?-1:1;
    else if(a.to!=b.to) return (a.to<b.to)?-1:1;
    return 0;
}

void SPFA(void){
    int i, head, tail, now, next;
    head=tail=0;
    q[tail]=1;
    inq[1]=1;
    dis[1]=0;
    tail++;
    while(head<tail){
        now=q[head%N];
        inq[now]=0;
        head++;
        for(i=se[now][0];i<=se[now][1] && se[now][0]!=-1;i++){
            next=edge[i].to;
            if(dis[now]+edge[i].time<dis[next] || dis[next]==-1){
                dis[next]=dis[now]+edge[i].time;
                if(inq[next]==0){
                    q[tail%N]=next;
                    inq[next]=1;
                    tail++;
                }
            }
        }
    }
}

void TIME(void){
    int i, j, next;
    double t;
    max=0;
    p1=1;
    flag=0;
    for(i=1;i<=N;i++){
        for(j=se[i][0];j<=se[i][1] && se[i][0]!=-1;j++){
            next=edge[j].to;
            if(dis[i]+edge[j].time==dis[next] && dis[next]>max){
                flag=0;
                max=(double)dis[next];
                p1=next;
            }
            else if(dis[i]+edge[j].time!=dis[next] && dis[next]+edge[j].time!=dis[i]){
                t=(double)(dis[i]+edge[j].time-dis[next])/2+dis[next];
                if(t>max){
                    flag=1;
                    max=t;
                    p1=(i<next)?i:next;
                    p2=(i<next)?next:i;
                }
            }
        }
    }
}
