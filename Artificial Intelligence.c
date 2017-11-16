#include<stdio.h>

int main(){
    int i, n;
    double tmp, I, P, U;
    char ch;
    scanf("%d\n", &n);
    for(i=1;i<=n;i++){
        I=P=U=0;
        while(scanf("%c", &ch)!=EOF && ch!='\n'){
            if(ch=='='){
                scanf("%lf", &tmp);
                scanf("%c", &ch);
                if(ch=='m'){
                    tmp*=0.001;
                    scanf("%c", &ch);
                }
                else if(ch=='k'){
                    tmp*=1000;
                    scanf("%c", &ch);
                }
                else if(ch=='M'){
                    tmp*=1000000;
                    scanf("%c", &ch);
                }
                if(ch=='A') I=tmp;
                else if(ch=='V') U=tmp;
                else if(ch=='W') P=tmp;
            }
        }
        printf("Problem #%d\n", i);
        if(I==0)
            printf("I=%.2lfA\n", P/U);
        else if(U==0)
            printf("U=%.2lfV\n", P/I);
        else if(P==0)
            printf("P=%.2lfW\n", I*U);
        printf("\n");
    }
    return 0;
}
