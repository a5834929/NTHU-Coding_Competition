#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INF 999999
int cmp(const void*p, const void*q);
typedef struct N{
    int from, to, wei;
}EDGE;
EDGE edge[20001];
void Union(int a, int b);
int find(int x);
int set[10001];
int main(){
    int V, E, i, j, k;
    int n_E, set_f, set_t;
    int min_e, max_e, slim;

    while(scanf("%d%d", &V, &E)!=EOF && !(V==0 && E==0)){
        for(i=0;i<E;i++)
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].wei);
        qsort(edge, E, sizeof(EDGE), cmp);
        slim=INF;
        for(i=0;i<E;i++){
            n_E=1;
            for(k=1;k<=V;k++)
                set[k]=k;
            max_e=edge[i].wei;
            min_e=edge[i].wei;
            Union(edge[i].from, edge[i].to);
            for(j=i+1;j<E && n_E<V;j++){
                set_f=find(edge[j].from);
                set_t=find(edge[j].to);
                if(set_f!=set_t){
                    Union(edge[j].from, edge[j].to);
                    max_e=(max_e>edge[j].wei)?max_e:edge[j].wei;
                    min_e=(min_e<edge[j].wei)?min_e:edge[j].wei;
                    n_E++;
                }
            }
            if(n_E==V-1)
                slim=(slim<(max_e-min_e))?slim:(max_e-min_e);
        }
        if(slim==INF)
            printf("-1\n");
        else
            printf("%d\n", slim);
    }
    return 0;
}

int cmp(const void*p, const void*q){
    EDGE a=*(EDGE*)p, b=*(EDGE*)q;
    if(a.wei!=b.wei)return(a.wei<b.wei)?-1:1;
    else if(a.from!=b.from) return(a.from<b.from)?-1:1;
    else if(a.to!=b.to)return(a.to<b.to)?-1:1;
    return 0;
}

void Union(int a, int b){
    int x, y;
    x=find(set[a]);
    y=find(set[b]);
    if(x!=y)
        set[y]=x;
    return;
}
int find(int x){
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}
