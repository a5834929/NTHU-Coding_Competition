#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

typedef struct T{
    char room[5], id[10];
    char name[22];
    int len, order;
}S;
S list[200];

int main(){
    int N, i, j, com;
    int len326, len328, lenmac;
    char ch;

    while(scanf("%d", &N)!=EOF && N){
        memset(list, 0, sizeof(list));
        len326=len328=lenmac=0;
        for(i=0;i<N;i++){
            com=2;
            scanf("%s%s%s", list[i].room, list[i].id, list[i].name);
            while(com){
                scanf("%c", &ch);
                if(ch=='"') com--;
            }
            list[i].order=i;
            list[i].len=strlen(list[i].id);
            if(strcmp(list[i].room, "326")==0 && len326<list[i].len)
                len326=list[i].len;
            if(strcmp(list[i].room, "328")==0 && len328<list[i].len)
                len328=list[i].len;
            if(strcmp(list[i].room, "mac")==0 && lenmac<list[i].len)
                lenmac=list[i].len;
        }
        qsort(list, N, sizeof(S), cmp);
        i=0;
        printf("<326>\n");
        while(strcmp(list[i].room, "326")==0){
            for(j=0;j<len326-list[i].len;j++)
                printf(" ");
            printf("%s %s\n", list[i].id, list[i].name);
            i++;
        }
        printf("<328>\n");
        while(strcmp(list[i].room, "328")==0){
            for(j=0;j<len328-list[i].len;j++)
                printf(" ");
            printf("%s %s\n", list[i].id, list[i].name);
            i++;
        }
        printf("<mac>\n");
        while(strcmp(list[i].room, "mac")==0){
            for(j=0;j<lenmac-list[i].len;j++)
                printf(" ");
            printf("%s %s\n", list[i].id, list[i].name);
            i++;
        }
        printf("\n");
    }
    return 0;
}

int cmp(const void*p, const void*q){
    S a=*(S*)p, b=*(S*)q;
    if(strcmp(a.room, b.room)!=0)
        return(strcmp(a.room, b.room)<0)?-1:1;
    else return(a.order<b.order)?-1:1;
    return 0;
}
