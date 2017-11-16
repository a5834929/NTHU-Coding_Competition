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
計算 R = BP mod M
對相當大的B、P、M請寫一個有效率的演算法來。

Input
每筆測試資料有3行，各有1個整數分別代表B、P、M。
其中 0 <= B <= 2147483647 0 <= P <= 2147483647 1 <= M <= 46340

Output
輸出計算的結果，每筆測試資料一行。

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
