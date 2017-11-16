#include<stdio.h>
#include<stdlib.h>
#define LEN 1000000
int cmp1(const void*p, const void*q);
int cmp2(const void*p, const void*q);
typedef struct T{
    int p, m, i, ans;
}PEOPLE;
PEOPLE ppl[100020];

void seg(int left, int right, int index);
typedef struct _tree{
    int lb, rb;
    int num;
}NODE;
NODE node[8000000];
void insert(int x, int index);
int find(int left, int right, int index);

int main(){
    int N, I, n, i;

    scanf("%d", &N);
    for(I=1;I<=N;I++){
        scanf("%d", &n);
        for(i=0;i<n;i++){
            scanf("%d%d", &ppl[i].p, &ppl[i].m);
            ppl[i].i=i;
            ppl[i].ans=0;
        }
        qsort(ppl, n, sizeof(PEOPLE), cmp1);
        seg(0, 2000000, 1);

        for(i=0;i<n;i++){
            insert(ppl[i].m+LEN, 1);
            if(ppl[i].m+LEN!=0)
                ppl[i].ans=find(0, ppl[i].m+LEN-1, 1);
        }
        qsort(ppl, n, sizeof(PEOPLE), cmp2);
        printf("Case #%d:\n", I);
        for(i=0;i<n;i++)
            printf("%d\n", ppl[i].ans);
        if(I!=N)
            printf("\n");
    }
    return 0;
}

int cmp1(const void*p, const void*q){
    PEOPLE a=*(PEOPLE*)p, b=*(PEOPLE*)q;
    if(a.p!=b.p) return (a.p<b.p)?-1:1;
    else if(a.m!=b.m) return (a.m>b.m)?-1:1;
    return 0;
}

int cmp2(const void*p, const void*q){
    PEOPLE a=*(PEOPLE*)p, b=*(PEOPLE*)q;
    if(a.i!=b.i) return (a.i<b.i)?-1:1;
    return 0;
}

void seg(int left, int right, int index){
    int mid;
    mid=(left+right)/2;
    node[index].lb=left;
    node[index].rb=right;
    node[index].num=0;
    if(left!=right){
        seg(left, mid, index*2);
        seg(mid+1, right, index*2+1);
    }
}

void insert(int x, int index){
    int mid;
    mid=(node[index].lb+node[index].rb)/2;
    if(node[index].lb==x && node[index].rb==x){
        node[index].num++;
        return;
    }
    else if(x<=mid)
        insert(x, index*2);
    else if(mid<x)
        insert(x, index*2+1);

    node[index].num=node[index*2].num+node[index*2+1].num;
    return;
}

int find(int left, int right, int index){
    int mid;
    mid=(node[index].lb+node[index].rb)/2;
    if(node[index].lb==left && node[index].rb==right)
        return node[index].num;
    else if(right<=mid)
        return find(left, right, index*2);
    else if(left>mid)
        return find(left, right, index*2+1);
    else
        return find(left, mid, index*2)+find(mid+1, right, index*2+1);
}


