#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cow[100100], pre[100100];
int ex[100100], s, e, ans;
typedef struct t{
    int val;
    struct t* next[2];
}node;
node* root;

node* CreateNode(void){
    int i;
    node* now=(node*)malloc(sizeof(node));
    for(i=0;i<2;i++)
        now->next[i]=NULL;
    now->val=0;
    return now;
}

void Insert(int x){
    int i, bit;
    node* now=root;
    for(i=20;i>=0;i--){
        bit=(((1<<i)&pre[x])==(1<<i));
        if(now->next[bit]==NULL)
            now->next[bit]=CreateNode();
        now=now->next[bit];
    }
    now->val=x;
}

void Find(int x){
    int i, bit;
    node* now=root;
    for(i=20;i>=0;i--){
        bit=(((1<<i)&ex[x])==(1<<i));
        if(now->next[bit]==NULL)
            now=now->next[1-bit];
        else
            now=now->next[bit];
    }
    if((pre[x]^pre[now->val])>ans){
        ans=pre[x]^pre[now->val];
        s=now->val+1;
        e=x;
    }
    Insert(x);
}

void Free(node* now){
    int i;
    for(i=0;i<2;i++)
        if(now->next[i]!=NULL)
            Free(now->next[i]);
    free(now);
}

int main(){
    int C, i;

    while(scanf("%d", &C)!=EOF){
        root=CreateNode();
        for(i=1;i<=C;i++)
            scanf("%d", &cow[i]);
        pre[0]=0;
        for(i=1;i<=C;i++){
            pre[i]=pre[i-1]^cow[i];
            ex[i]=~pre[i];
        }
        pre[0]=0;
        s=e=1;
        ans=0;
        Insert(0);
        for(i=1;i<=C;i++)
            Find(i);
        Free(root);
        printf("%d %d %d\n", ans, s, e);
    }
    return 0;
}
