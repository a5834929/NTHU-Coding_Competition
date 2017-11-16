#include<stdio.h>
#include<string.h>
char str[100001][25];

int main(){
    int i, j, len, palin;
    char ch;

    while(scanf("%s", str[0])!=EOF){
        len=1;
        palin=1;
        while(scanf("%s%c", str[len++], &ch)!=EOF && ch!='\n');
        for(i=0, j=len-1;i<=j/2;i++, j--)
            if(strcmp(str[i], str[j]))
                palin=0;
        if(palin) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
