#include<stdio.h>

int main(){
    char ch, word[10000];
    int len, i;
    while(scanf("%c", &ch)!=EOF){
        len=0;
        while(ch!='\n' && ch!=' '){
            word[len++]=ch;
            scanf("%c", &ch);
        }
        for(i=len-1;i>=0;i--)
            printf("%c", word[i]);
        if(ch==' ')
            printf(" ");
        else if(ch=='\n')
            printf("\n");
    }
    return 0;
}
