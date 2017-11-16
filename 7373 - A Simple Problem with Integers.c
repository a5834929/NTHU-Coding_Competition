#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    int lb, rb;
    long long int add, sum;
}NODE;
NODE node[500000];
void seg(int left, int right, int index);
void insert(int x, int index, int bound);
void mod(int left, int right, int index, int add);
void down(int index, int add);
long long int find(int left, int right, int index);
int main(){
    int N, Q, i, x, a, b, c;
    char com;

    while(scanf("%d%d", &N, &Q)!=EOF){
        seg(1, N, 1);
        for(i=1;i<=N;i++){
            scanf("%d", &x);
            insert(x, 1, i);
        }
        scanf("%*c");
        while(Q--){
            scanf("%c ", &com);
            if(com=='Q'){
                scanf("%d%d", &a, &b);
                printf("%lld\n", find(a, b, 1));
            }
            else if(com=='C'){
                scanf("%d%d%d", &a, &b, &c);
                mod(a, b, 1, c);
            }
            scanf("%*c");
        }
    }
    return 0;
}

void seg(int left, int right, int index){
    int mid=(left+right)/2;
    node[index].lb=left;
    node[index].rb=right;
    node[index].add=0;
    node[index].sum=0;
    if(left!=right){
        seg(left, mid, index*2);
        seg(mid+1, right, index*2+1);
    }
}

long long int find(int left, int right, int index){
    int mid=(node[index].lb+node[index].rb)/2;
    down(index, node[index].add);
    if(node[index].lb==left && node[index].rb==right)
        return node[index].sum;
    else if(right<=mid)
        return find(left, right, index*2);
    else if(left>mid)
        return find(left, right, index*2+1);
    else
        return find(left, mid, index*2)+find(mid+1, right, index*2+1);
}

void insert(int x, int index, int bound){
    int mid=(node[index].lb+node[index].rb)/2;
    if(node[index].lb==bound && node[index].rb==bound){
        node[index].sum=x;
        return;
    }
    else if(bound<=mid)
        insert(x, index*2, bound);
    else if(bound>mid)
        insert(x, index*2+1, bound);
    node[index].sum=node[index*2].sum+node[index*2+1].sum;
    return;
}

void mod(int left, int right, int index, int add){
    int mid=(node[index].lb+node[index].rb)/2;
    if(node[index].lb==left && node[index].rb==right){
        node[index].add+=add;
        node[index].sum+=((right-left+1)*add);
        return;
    }
    else if(right<=mid)
        mod(left, right, index*2, add);
    else if(left>mid)
        mod(left, right, index*2+1, add);
    else{
        mod(left, mid, index*2, add);
        mod(mid+1, right, index*2+1, add);
    }
    node[index].sum+=((right-left+1)*add);
    return;
}

void down(int index, int add){
    if(add!=0 && node[index].rb!=node[index].lb){
        node[index*2].add+=add;
        node[index*2+1].add+=add;
        node[index].add=0;
        node[index*2].sum+=(node[index*2].rb-node[index*2].lb+1)*add;
        node[index*2+1].sum+=(node[index*2+1].rb-node[index*2+1].lb+1)*add;
        return;
    }
    else return;
}


