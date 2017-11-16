#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n_seg, s_e[100002][2], cow[100010], ans[100010], vis[100010];
int cmp(const void*p, const void*q);
int seg(int left, int right, int par);
typedef struct _tree{
    int lb, rb;
    int lc, rc, par;
    int num;
}NODE;

NODE node[300000];

typedef struct _s{
    int start, end;
}STAR;

STAR star[200002];

int search(int a, int index);
void find(int a, int index);
void Find(int a, int index);
void DFS(int p);

int main(void){
    int n, i, x;

    while(scanf("%d", &n)!=EOF){
        memset(s_e, -1, sizeof(s_e));
        memset(vis, 0, sizeof(vis));
        n_seg=-1;
        seg(1, n, -1);

        for(i=0;i<2*n-2;i+=2){
            scanf("%d %d", &star[i].start, &star[i].end);
            star[i+1].start=star[i].end;
            star[i+1].end=star[i].start;
        }
        for(i=1;i<=n;i++){
            scanf("%d", &x);
            cow[x]=i;
        }

        qsort(star, 2*n-2, sizeof(STAR), cmp);

        for(i=0;i<2*n-2;i++){
            if(s_e[star[i].start][0]==-1)
                s_e[star[i].start][0]=i;
            s_e[star[i].start][1]=i;
        }

        DFS(1);

        for(i=1;i<=n;i++)
            printf("%d\n", ans[i]);
    }
    return 0;
}

int seg(int left, int right, int par){

    int index;
    n_seg++;
    index=n_seg;
    node[index].lb=left;
    node[index].rb=right;
    node[index].par=par;
    node[index].lc=node[index].rc=-1;
    node[index].num=0;

    if(left!=right){
        node[index].lc=seg(left, (left+right)/2, index);
        node[index].rc=seg((left+right)/2+1, right, index);
    }
    return index;
}

void DFS(int p){
    int i;
    vis[p]=1;
    ans[cow[p]]=search(cow[p]-1, 0);

    find(cow[p], 0);

    for(i=s_e[p][0];i<=s_e[p][1];i++)
        if(!vis[star[i].end])
            DFS(star[i].end);

    Find(cow[p], 0);

    return;
}

int search(int a, int index){
    if(node[index].rb<=a)
        return node[index].num;
    else if(node[index].lb>a)
        return 0;
    else
        return search(a, node[index].lc)+search(a, node[index].rc);
}

void find(int a, int index){
    if(node[index].rb==a && node[index].lb==a){
        node[index].num++;
    }
    else if(node[node[index].lc].rb<a){
        find(a, node[index].rc);
        node[index].num=node[node[index].lc].num+node[node[index].rc].num;
    }
    else if(node[node[index].lc].rb>=a){
        find(a, node[index].lc);
        node[index].num=node[node[index].lc].num+node[node[index].rc].num;
    }
}

void Find(int a, int index){
    if(node[index].rb==a && node[index].lb==a)
        node[index].num--;
    else if(node[node[index].lc].rb<a){
        Find(a, node[index].rc);
        node[index].num=node[node[index].lc].num+node[node[index].rc].num;
    }
    else if(node[node[index].lc].rb>=a){
        Find(a, node[index].lc);
        node[index].num=node[node[index].lc].num+node[node[index].rc].num;
    }
}

int cmp(const void*p, const void*q){
    STAR a=*(STAR*)p, b=*(STAR*)q;
    if(a.start!=b.start) return(a.start<b.start)?-1:1;
    else if(a.end!=b.end) return (a.end<b.end)?-1:1;
    return 0;
}
