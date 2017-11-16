#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sum, n_list, c_list;
int cmp(const void*p, const void*q);
typedef struct p{
    char tree[50];
}TREE;
TREE list[10001];
typedef struct t{
    int saved;
    double count;
    struct t* next[130];
}node;
node* root;

node* CreateNode(void){
    int i;
    node* now=(node*)malloc(sizeof(node));
    for(i=0;i<130;i++)
        now->next[i]=NULL;
    now->saved=0;
    now->count=0;
    return now;
}

void Insert(char* str, int len){
    int i;
    node* now=root;
    for(i=0;i<len;i++){
		if(now->next[str[i]-0]==NULL)
			now->next[str[i]-0]=CreateNode();
		now=now->next[str[i]-0];
	}
	if(now->saved==0){
        now->saved=1;
        strcpy(list[n_list].tree, str);
        n_list++;
	}
	now->count++;
}

void Free(node* now){
    int i;
    for(i=0;i<128;i++)
        if(now->next[i]!=NULL)
            Free(now->next[i]);
    free(now);
}

void Find(node* now){
    int i;
    for(i=0;i<128;i++)
        if(now->next[i]!=NULL)
            Find(now->next[i]);
    if(now->count){
        printf("%s", list[c_list].tree);
        printf(" %.4lf\n", (now->count/sum)*100);
        c_list++;
    }
    return;
}

int main(){
    int T, len;
    char str[50];

    freopen("in.txt", "r", stdin);
	freopen("out.txt", "w+", stdout);

    scanf("%d", &T);
    getchar();
    getchar();
    while(T--){
        sum=0;
        n_list=0;
        c_list=0;
        root=CreateNode();
        while(gets(str)){
            len=strlen(str);
            if(len){
                Insert(str, len);
                sum++;
            }
            else break;
        }
        qsort(list, n_list, sizeof(TREE), cmp);
        Find(root);
        Free(root);
        if(T)
            printf("\n");
    }
    return 0;
}

int cmp(const void*p, const void*q){
    TREE a=*(TREE*)p, b=*(TREE*)q;
    if(strcmp(a.tree, b.tree)!=0) return(strcmp(a.tree, b.tree)<0)?-1:1;
    return 0;
}
