#include<stdio.h>
typedef struct factor{
    int fac;
    int num;
}FAC;

FAC factor[10000];

int main(void){
    int n, i, j, k;

    while(scanf("%d", &n)!=EOF){
        i=2;
        j=0;
        while(n>=i*i){
            if(n%i==0){
                if(factor[j-1].fac==i) factor[j-1].num++;
                else{
                    factor[j].fac=i;
                    factor[j].num++;
                    j++;
                }
                n/=i;
            }

            else i++;
        }

        if(factor[j-1].fac==n) factor[j-1].num++;
        else{
            factor[j].fac=n;
            factor[j].num=1;
        }

        for(i=0;i<=j;i++){
            if(factor[i].fac!=0){
                printf("%d^", factor[i].fac);
                printf("%d", factor[i].num);
                if(factor[i+1].fac!=0) printf("*");
            }
            factor[i].fac=0;
            factor[i].num=0;
        }
        printf("\n");
    }
    return 0;
}

/****************************************************

Problem Description
��]�Ƥ��Ѧb�ƽפW���S�O���N�q�A�ҥH�ڭ̥������m���
�@�ӼƦr�@��]�Ƥ��ѡC�{�b�A�����@�Ӿ�ơA�й復�@��]�Ƥ��ѡC

Input
���h�մ���C
�C�մ��꦳�@�ӥ����N�A2<=N<=100000000

Output
��X��]�Ƥ��Ѫ����G�C

Sample Input
24
56

Sample Output
2^3*3^1
2^3*7^1

*****************************************************/
