#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void SPFA(void);
void BACK(void);
int cmp(const void*p, const void*q);
typedef struct _E{
    int from, to, wei;
}EDGE;
EDGE edge[600010];
int s_e[100010][2], dis[100001];
int q[100010], inq[100001], back[100001];
int T, C, R, S, E;
int main(){
    int i;

    scanf("%d", &T);
    while(T--){
        memset(back, -1, sizeof(back));
        memset(dis, -1, sizeof(dis));
        scanf("%d%d%d%d", &C, &R, &S, &E);
        for(i=0;i<2*R;i+=2){
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].wei);
            edge[i+1].from=edge[i].to;
            edge[i+1].to=edge[i].from;
            edge[i+1].wei=edge[i].wei;
        }
        qsort(edge, 2*R, sizeof(EDGE), cmp);
        memset(s_e, -1, sizeof(s_e));
        for(i=0;i<2*R;i++){
            if(s_e[edge[i].from][0]==-1)
                s_e[edge[i].from][0]=i;
            s_e[edge[i].from][1]=i;
        }
        SPFA();
        BACK();
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
    q[tail]=E;
    inq[E]=1;
    dis[E]=0;
    tail++;
    while(head<tail){
        now=q[head%C];
        head++;
        inq[now]=0;
        for(i=s_e[now][0];i<=s_e[now][1] && s_e[now][0]!=-1;i++){
            next=edge[i].to;
            if(dis[now]+edge[i].wei<dis[next] || dis[next]==-1){
                dis[next]=dis[now]+edge[i].wei;
                back[next]=now;
                if(inq[next]==0){
                    q[tail%C]=next;
                    inq[next]=1;
                    tail++;
                }
            }
            else if(dis[now]+edge[i].wei==dis[next] && (now<back[next] || back[next]==-1))
                back[next]=now;
        }
    }
}

void BACK(void){
    int x;
    printf("%d", S);
    x=S;
    while(back[x]!=-1){
        printf("->%d", back[x]);
        x=back[x];
    }
    printf("\n");
}
