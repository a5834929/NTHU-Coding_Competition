#include<stdio.h>
long long int sum[10010]={0};

int main(void)
{
    int k, n, q, i, x, a, b;

    scanf("%d", &k);

    while(k--)
    {
        scanf("%d %d", &n, &q);
        sum[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d", &x);
            sum[i]=sum[i-1]+x;
        }
        for(i=0;i<q;i++)
        {
            scanf("%d %d", &a, &b);
            printf("%lld\n", sum[b]-sum[a-1]);
        }
    }

    return 0;
}

/*****************************************************

Problem Description
給你一連串的數字，請你找到第a 個數字連續加到第b 個數字的總和

Input
輸入第一行是k(k<100)，代表有k 組測資
每組測資第一行是n(n<10000) 與q(q<10000)，代表有n 個數字與q 個問題
接下來n 行每行有一個Ni(Ni < 1000)，表示第i 個數字
接下來q 行有兩個數字a ,b(1 ≤ a ≤ b ≤ n)，代表他的問題

Output
對於每個問題請輸出他的總和

Sample Input
2
3 2
1
2
3
1 3
2 3
2 1
7
6
1 1

Sample Output
6
5
7

*****************************************************/
