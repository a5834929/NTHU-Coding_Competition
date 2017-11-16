#include<stdio.h>
typedef struct T{
    int lb, rb, it;
}TREE;
TREE node[400002];
void seg(int left, int right, int ind);
void insert(int bound, int ind, int item);
int find(int left, int right, int ind);

int main(){
    int N, Q, x, y;
    char com;

    while(scanf("%d%d", &N, &Q)!=EOF){
        scanf("%*c");
        seg(1, N, 1);
        while(Q--){
            scanf("%c%d%d", &com, &x, &y);
            if(com=='c')
                printf("%d\n", find(x, y, 1));
            else if(com=='p')
                insert(y, 1, x);
            scanf("%*c");
        }
    }
    return 0;
}

void seg(int left, int right, int ind){
    int mid=(left+right)/2;
    node[ind].lb=left;
    node[ind].rb=right;
    node[ind].it=0;
    if(left!=right){
        seg(left, mid, ind*2);
        seg(mid+1, right, ind*2+1);
    }
    return;
}

void insert(int bound, int ind, int item){
    int mid=(node[ind].lb+node[ind].rb)/2;
    if(node[ind].lb==bound && node[ind].rb==bound){
        node[ind].it+=item;
        return;
    }
    else if(bound<=mid)
        insert(bound, ind*2, item);
    else if(bound>mid)
        insert(bound, ind*2+1, item);
    node[ind].it=node[ind*2].it+node[ind*2+1].it;
    return;
}
int find(int left, int right, int ind){
    int mid=(node[ind].lb+node[ind].rb)/2;
    if(node[ind].lb==left && node[ind].rb==right)
        return node[ind].it;
    else if(right<=mid)
        return find(left, right, ind*2);
    else if(left>mid)
        return find(left, right, ind*2+1);
    else
        return find(left, mid, ind*2)+find(mid+1, right, ind*2+1);
}
