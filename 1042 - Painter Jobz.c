#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _D{
    int x, y, col;
}DATA;
DATA data[200000];
typedef struct _T{
    int lb, rb, c;
}TREE;
TREE node[400003];
void seg(int left, int right, int ind);
void insert(int left, int right, int ind, int color);
void find(int ind);
void PRINT(int ind);
int main(){
    int N, i, min, max;
    while(scanf("%d", &N)!=EOF){
        min=200001;
        max=-1;
        for(i=0;i<N;i++){
            scanf("%d%d%d", &data[i].col, &data[i].x, &data[i].y);
            min=(min<data[i].x)?min:data[i].x;
            max=(max>data[i].y)?max:data[i].y;
        }
        seg(min, max, 1);
        for(i=0;i<N;i++)
            insert(data[i].x, data[i].y, 1, data[i].col);
        find(1);


    }
    return 0;
}

void seg(int left, int right, int ind){
    int mid=(left+right)/2;
    node[ind].lb=left;
    node[ind].rb=right;
    node[ind].c=0;
    if(left!=right-1){
        seg(left, mid, ind*2);
        seg(mid, right, ind*2+1);
    }
    return;
}

void insert(int left, int right, int ind, int color){
    int mid=(node[ind].lb+node[ind].rb)/2;
    if(node[ind].lb==node[ind].rb-1){
        node[ind].c=color;
        return;
    }
    else if(right<=mid)
        insert(left, right, ind*2, color);
    else if(left>=mid)
        insert(left, right, ind*2+1, color);
    else{
        insert(left, mid, ind*2, color);
        insert(mid, right, ind*2+1, color);
    }
    if(node[ind*2].c==node[ind*2+1].c)
        node[ind].c=node[ind*2].c;
    return;
}

void find(int ind){
    if(node[ind].c!=0 || node[ind].lb==node[ind].rb-1){
        printf("%d %d %d\n", node[ind].lb, node[ind].rb, node[ind].c);
        return;
    }
    find(ind*2);
    find(ind*2+1);
}
