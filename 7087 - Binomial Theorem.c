#include<stdio.h>
#include<string.h>
#include<ctype.h>
double comb(int n, int m);

int main(void)
{
    char ch, word1[100], word2[100];
    int num, i, j, k, exp;
    double coeff;

    scanf("%d", &num);

    for(i=0;i<num;i++)
    {
        scanf(" (");

        j=0;
        while((ch=getchar())!='+') word1[j++]=ch;
        word1[j]='\0';

        j=0;
        while((ch=getchar())!=')') word2[j++]=ch;
        word2[j]='\0';

        scanf(" ^%d", &exp);

        printf("Case %d: ", i+1);
        for(k=0;k<strlen(word1);k++) printf("%c", word1[k]);
        if(exp!=1) printf("^%d+", exp);
        else printf("+");

        for(j=1;j<exp;j++)
        {
            coeff=comb(exp, j);
            printf("%.0lf*", coeff);
            for(k=0;k<strlen(word1);k++) printf("%c", word1[k]);
            if((exp-j)!=1) printf("^%d", exp-j);
            printf("*");
            for(k=0;k<strlen(word2);k++) printf("%c", word2[k]);
            if(j>1) printf("^%d", j);
            printf("+");
        }
        for(k=0;k<strlen(word2);k++) printf("%c", word2[k]);
        if(exp!=1) printf("^%d", exp);
        printf("\n");
    }

    return 0;
}

double comb(int n, int m)
{
    int i, j;
    double fac;

    if(m>n/2) m=n-m;
    for(fac=1,i=n,j=1;i>=n-m+1;i--,j++)
    {
        fac*=i;
        fac/=j;
    }

    return fac;
}

/************************************************

Problem Description
本題請你將 (a+b)^k 乘開，寫出等式：
(a+b)^k = x1a^k + x2a^(k−1)b + x3a^(k−2)b^2 + … + xk+1b^k
其中 x1 … xk+1 為二項式係數，即 xi = Cki .

Input
輸入 資料的第一列為一整數T(T <= 100)表示測試資料的組數。
每組資料一列，其格式為(a+b)^k，其中 a 與 b 為變數名稱，
變數名稱以'a' ~ 'z'的小寫字母所組成，且 k (1 <= k <= 50)為其次方。
每列的長度不會超過100個字元。

Output
請每組資料輸出格式"Case N: T"，其中N表示測試資料編號(由1開始)，
T表示乘開的式子。你不應該輸出係數或指數上多餘的1。

Sample Input
3
(a+b)^1
(alpha+omega)^2
(acm+icpc)^3

Sample Output
Case 1: a+b
Case 2: alpha^2+2*alpha*omega+omega^2
Case 3: acm^3+3*acm^2*icpc+3*acm*icpc^2+icpc^3



**************************************************/

