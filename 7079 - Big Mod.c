#include<stdio.h>

int main(void)
{
    long long int B, P, M, r;

    while(EOF!=scanf("%lld %lld %lld", &B, &P, &M))
    {
        r=1;
        B=B%M;
        while(P)
        {
            if(P%2) r=r*B%M;
            B=B*B%M;
            P/=2;
        }
        printf("%lld\n", r);
    }

    return 0;
}

/***********************************

Problem Description
�p�� R = BP mod M
��۷�j��B�BP�BM�мg�@�Ӧ��Ĳv���t��k�ӡC

Input
�C�����ո�Ʀ�3��A�U��1�Ӿ�Ƥ��O�N��B�BP�BM�C
�䤤 0 <= B <= 2147483647 0 <= P <= 2147483647 1 <= M <= 46340

Output
��X�p�⪺���G�A�C�����ո�Ƥ@��C

Sample Input
3
18132
17

17
1765
3

2374859
3029382
36123

Sample Output
13
2
13195

***********************************/
