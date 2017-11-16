#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(){
    char com[20], ans[205], ch;
    int i;

    while(1){
        scanf("%s", com);
        if(strcmp(com, "ENDOFINPUT")==0)
            break;
        if(strcmp(com, "START")==0){
            i=0;
            getchar();
            scanf("%c", &ch);
            while(ch!='\n'){
                ans[i]=ch;
                if(isalpha(ch)){
                    ans[i]=ch-5;
                    if(ch-5<65)
                        ans[i]=90-(5-(ch-65)-1);
                }
                i++;
                scanf("%c", &ch);
            }
            ans[i]='\0';
        }
        if(strcmp(com, "END")==0)
            printf("%s\n", ans);
    }
    return 0;
}
