#include<stdio.h>
#include<string.h>
char str[10000001];

int main(){
    int i, len;
    long long int ans, A, C, G, T;

    while(gets(str)!=NULL){
        len=strlen(str);
        A=C=G=T=ans=0;
        for(i=len-1;i>=0;i--){
            if(str[i]=='A') A++;
            else if(str[i]=='C'){
                C++;
                ans+=A;
            }
            else if(str[i]=='G'){
                G++;
                ans+=A+C;
            }
            else if(str[i]=='T'){
                T++;
                ans+=A+C+G;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
