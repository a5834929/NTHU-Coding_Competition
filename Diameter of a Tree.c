#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int BFS(int x);
int cmp(const void*p, const void*q);
typedef struct t{
    int from, to;
}TREE;
TREE tree[400000];
int se[200001][2], dis[200001], N;
int q[200001], inq[200001];

int main(){
    int T, i, max;

    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(i=0;i<2*N-2;i+=2){ //save two-way paths
            scanf("%d%d", &tree[i].from, &tree[i].to);
            tree[i+1].from=tree[i].to;
            tree[i+1].to=tree[i].from;
        }
        memset(se, -1, sizeof(se));
        memset(dis, 0, sizeof(dis));
        memset(q, 0, sizeof(q));
        memset(inq, 0, sizeof(inq));
        qsort(tree, 2*N-2, sizeof(TREE), cmp);//sort

        for(i=0;i<2*N-2;i++){
            //se[i][0] : the first edge starts from i
            //se[i][1] : the last egde starts from i
            if(se[tree[i].from][0]==-1)
                se[tree[i].from][0]=i;
            se[tree[i].from][1]=i;
        }
        max=BFS(1);
        memset(dis, 0, sizeof(dis));
        memset(q, 0, sizeof(q));
        memset(inq, 0, sizeof(inq));
        printf("%d\n", dis[BFS(max)]);
    }
    return 0;
}

int cmp(const void*p, const void*q){
    TREE a=*(TREE*)p, b=*(TREE*)q;
    if(a.from!=b.from)return(a.from<b.from)?-1:1;
    else if(a.to!=b.to)return (a.to<b.to)?-1:1;
    return 0;
}

int BFS(int x){
    int head, tail, i, now, next, max;
    head=0;
    tail=1;
    q[0]=x;
    inq[x]=1;
    dis[x]=0;
    max=x;
    while(head<tail){
        now=q[head%N];
        head++;
        for(i=se[now][0];i<=se[now][1] && se[now][0]!=-1;i++){
            next=tree[i].to;
            if(inq[next]==0){
                dis[next]=dis[now]+1;
                q[tail%N]=next;
                inq[next]=1;
                tail++;
                if(dis[max]<dis[next])
                    max=next;
            }
        }
    }
    return max;
}
