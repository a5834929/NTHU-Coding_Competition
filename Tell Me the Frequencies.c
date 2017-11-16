#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void*p, const void*q);

typedef struct T{
    int ascii, freq;
}INFO;
INFO info[130];

int main(){
    int i, len;
    char str[1010];
    gets(str);
    while(1){
        memset(info, 0, sizeof(info));
        len=strlen(str);
        for(i=0;i<len;i++){
            info[str[i]].ascii=str[i];
            info[str[i]].freq++;
        }
        qsort(info, 130, sizeof(INFO), cmp);
        for(i=0;i<130;i++)
            if(info[i].freq!=0)
                printf("%d %d\n", info[i].ascii, info[i].freq);
        if(gets(str)!=NULL) printf("\n");
        else break;
    }
    return 0;
}
int cmp(const void*p, const void*q){
    INFO a=*(INFO*)p, b=*(INFO*)q;
    if(a.freq!=b.freq) return (a.freq<b.freq)?-1:1;
    else if(a.ascii!=b.ascii) return (a.ascii>b.ascii)?-1:1;
    return 0;
}
