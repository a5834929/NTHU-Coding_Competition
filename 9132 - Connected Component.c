#include<stdio.h>
int find(int x);
void Union(int a, int b);
int set[100001], group[100001];

typedef struct _p{
    int a, b;
}POINT;
POINT edge[1000001];

int main(){
    int p, e, i, max;

    while(scanf("%d", &p)!=EOF && p){
        for(i=0;i<p;i++){
            set[i]=i;
            group[i]=1;
        }
        scanf("%d", &e);
        for(i=0;i<e;i++){
            scanf("%d%d", &edge[i].a, &edge[i].b);
            if(find(edge[i].a)!=find(edge[i].b))
                Union(edge[i].a, edge[i].b);
        }
        max=0;
        for(i=0;i<p;i++)
            if(max<=group[i])
                max=group[i];
        printf("%d\n", max);
    }
    return 0;
}

int find(int x){
    if(set[x]==x)
        return x;
    else
        return set[x]=find(set[x]);
}

void Union(int a, int b){
    int x, y;
    x=find(set[a]);
    y=find(set[b]);
    if(x!=y){
        set[y]=x;
        if(group[y]){
            group[x]+=group[y];
            group[y]=0;
        }
    }
}
