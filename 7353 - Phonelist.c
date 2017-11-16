#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T, N, flag;
typedef struct s{
    char phone[20];
}LIST;
LIST list[10010];

typedef struct t{
    int count;
    struct t* next[15];
}node;
node* root;

node* CreateNode(){
    int i;
    node* now=(node*)malloc(sizeof(node));
    now->count=0;
    for(i=0;i<15;i++)
        now->next[i]=NULL;
    now->count=0;
    return now;
}

void Insert(char* str){
    int i, len;
    len=strlen(str);
    node* ptr=root;
    for(i=0;i<len;i++){
        if(ptr->next[str[i]-'0']==NULL)
            ptr->next[str[i]-'0']=CreateNode();
        ptr=ptr->next[str[i]-'0'];
        ptr->count++;
    }
}

int Find(char* str){
    int i, len;
    len=strlen(str);
    node* ptr=root;
    for(i=0;i<len;i++){
        if(ptr->next[str[i]-'0']==NULL)
            return 0;
        ptr=ptr->next[str[i]-'0'];
    }
    return (ptr->count)==1;
}

int main(){
    int i, len;

    scanf("%d", &T);
    while(T--){
        scanf("%d%*c", &N);
        root=CreateNode();
        for(i=0;i<N;i++)
            scanf("%s", list[i].phone);
        for(i=0;i<N;i++)
            Insert(list[i].phone);
        flag=1;
        for(i=0;i<N && flag!=0;i++)
            flag=Find(list[i].phone);
        if(flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
