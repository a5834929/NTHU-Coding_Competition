#include<stdio.h>
#include<stdlib.h>
int cmp1(const void*p, const void*q);
int cmp2(const void*p, const void*q);

int main(){
    int N[20], n[20];
    int i, len, num, tmp;
    long long int big, small, count;

    while(scanf("%d", &num)!=EOF){
        len=0;
        big=small=0;
        count=1;
        while(num){
            N[len]=num%10;
            n[len++]=num%10;
            num/=10;
        }
        qsort(N, len, sizeof(int), cmp1);
        qsort(n, len, sizeof(int), cmp2);

        for(i=0;i<len;i++)
            if(n[i]){
                tmp=n[i];
                n[i]=n[0];
                n[0]=tmp;
                break;
            }
        for(i=0;i<len;i++){
            big+=N[len-i-1]*count;
            small+=n[len-i-1]*count;
            count*=10;
        }
        printf("%lld - %lld = %lld = 9 * %lld\n", big, small, big-small, (big-small)/9);
    }
    return 0;
}

int cmp1(const void*p, const void*q){
    int a=*(int*)p, b=*(int*)q;
    if(a!=b)return(a>b)?-1:1;
    return 0;
}

int cmp2(const void*p, const void*q){
    int a=*(int*)p, b=*(int*)q;
    if(a!=b)return(a<b)?-1:1;
    return 0;
}
