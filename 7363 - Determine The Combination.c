#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void DFS(int num, int x);
int cmp(const void*p, const void*q);
char ans[50], str[50];
int vis[2000][50];
int len, N;
int main(){
    int i;
    while(scanf("%s", str)!=EOF){
        scanf("%d", &N);
        len=strlen(str);
        qsort(str, len, sizeof(char), cmp);
        DFS(0, 0);
    }
    return 0;
}

int cmp(const void*p, const void*q){
    char a=*(char*)p, b=*(char*)q;
    if(a!=b)return (a<b)?-1:1;
    return 0;
}

void DFS(int num, int x){
    int i;
    char temp='A';
    if(num>N)
        return;
    if(num==N){
        printf("%c", ans[0]);
        for(i=1;i<N;i++)
            printf("%c", ans[i]);
        printf("\n");
        return;
    }
    for(i=x;i<len;i++){
        if(temp!=str[i]){
            temp=str[i];
            ans[num]=str[i];
            DFS(num+1, i+1);
        }
    }
}
