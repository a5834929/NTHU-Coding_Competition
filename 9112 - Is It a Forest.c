#include<stdio.h>
#include<stdlib.h>
int find(int x);
void Union(int a, int b);
int set[500001];

typedef struct _p{
    int a, b;
}POINT;
POINT edge[500001];

int main(){
    int p, e, i, flag;

    while(scanf("%d%d", &p, &e)!=EOF && p){
        flag=0;
        for(i=1;i<=p;i++)
            set[i]=i;
        for(i=0;i<e;i++){
            scanf("%d%d", &edge[i].a, &edge[i].b);
            if(find(edge[i].a)!=find(edge[i].b))
                Union(edge[i].a, edge[i].b);
            else
                flag=1;
        }
        if(flag)
            printf("No\n");
        else
            printf("Yes\n");
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
    if(x!=y)
        set[y]=x;
}
