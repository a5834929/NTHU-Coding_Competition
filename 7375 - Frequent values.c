#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct tree{
    int lb, rb, time;
}TREE;
TREE node[400010];
void seg(int left, int right, int ind);
int find(int left, int right, int ind);
int MAX(int a, int b);
int l_most[300001], r_most[300001];
int main(){
    int N, Q, V, a, b, i;
    int m_c, tmp;

    while(scanf("%d", &N)!=EOF && N!=0){
        m_c=0;
        memset(l_most, 0, sizeof(l_most));
        memset(r_most, 0, sizeof(r_most));
        scanf("%d", &Q);
        tmp=-100001;
        for(i=1;i<=N;i++){
            scanf("%d", &V);
            if(tmp!=V){
                r_most[m_c]=i-1;
                m_c++;
                l_most[m_c]=i;
                tmp=V;
            }
        }
        r_most[m_c]=N;

        seg(1, m_c, 1);
        for(i=0;i<Q;i++){
            scanf("%d%d", &a, &b);
            printf("%d\n", find(a, b, 1));
        }
    }
    return 0;
}

void seg(int left, int right, int ind){
    int mid=(left+right)/2;
    node[ind].lb=l_most[left];
    node[ind].rb=r_most[right];
    node[ind].time=0;
    if(left!=right){
        seg(left, mid, ind*2);
        seg(mid+1, right, ind*2+1);
        node[ind].time=MAX(node[ind*2].time, node[ind*2+1].time);
    }
    else
        node[ind].time=r_most[right]-l_most[left]+1;
    return;
}

int find(int left, int right, int ind){
    if(node[ind].lb==left && node[ind].rb==right)
        return node[ind].time;
    if((node[ind].rb-node[ind].lb+1)==node[ind].time)
        return right-left+1;
    if(right<=node[ind*2].rb)
        return find(left, right, ind*2);
    else if(left>=node[ind*2+1].lb)
        return find(left, right, ind*2+1);
    else
        return MAX(find(left, node[ind*2].rb, ind*2), find(node[ind*2+1].lb, right, ind*2+1));
}

int MAX(int a, int b){
    return (a>b)?a:b;
}
