#include<stdio.h>
#include<string.h>

typedef struct T{
    int fac, num;
}FAC;
FAC factor[10000];

int main(){
    int N, b, e, i, j;

    while(1){
        N=1;
        memset(factor, 0, sizeof(factor));
        scanf("%d", &b);
        if(!b) break;
        while(b){
            scanf("%d", &e);
            while(e--)
                N*=b;
            scanf("%d", &b);
        }
        N--;
        i=2;
        j=0;
        while(N>=i*i){
            if(N%i==0){
                if(factor[j-1].fac!=i){
                    factor[j].fac=i;
                    factor[j].num++;
                    j++;
                }
                else factor[j-1].num++;
                N/=i;
            }
            else i++;
        }

        if(factor[j-1].fac==N) factor[j-1].num++;
        else{
            factor[j].fac=N;
            factor[j].num=1;
        }
        for(i=j;i>=0;i--)
            if(factor[i].fac)
                printf("%d %d%c", factor[i].fac, factor[i].num, (i)?' ':'\n');
    }
    return 0;
}
