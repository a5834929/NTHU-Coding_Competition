#include<stdio.h>

int main(void)
{
    int num, count=0;
    double initTemp, diff;

    scanf("%d", &num);

    while(count<num)
    {
        scanf("%lf %lf", &initTemp, &diff);
        printf("Case %d: %.2lf\n", count+1, initTemp+diff*5/9);
        count++;
    }
    return 0;
}

/******************************************

Problem Description
在科學實驗的過程中，量測溫度與溫差是很常見的工作，
不過因為有華氏(度F)與攝氏(度C)兩種常見的溫度表示法，
所以有時候會有點麻煩。兩者的轉換公式如下：

F=(5/9)*C+32

本題會給定以攝氏表示的初始溫度C，與以華氏表示的溫差F，
請你以攝氏溫度表示新的溫度為何。

Input
輸入第一列有一個整數 T (<= 100)表示測式資料的組數。
每組資料有兩個整數 C 與 d ( 0 <= C, d <= 100)，C表示初始溫度
(以攝氏溫度表示)，d表示溫差(以華氏溫度表示)。

Output
請以攝氏溫度為單位輸出新的溫度為何，請輸出到小數點後兩位。

Sample Input
2
100 0
0 100

Sample Output
Case 1: 100.00
Case 2: 55.56

******************************************/
