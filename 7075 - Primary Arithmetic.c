#include<stdio.h>
#include<string.h>

int main(void)
{
    char str1[12], str2[12];
    char num1[12]={0}, num2[12]={0}, num3[12]={0};
    int i, len1, len2, len_max;

    while(EOF!=scanf("%20s %20s", str1, str2))
    {
        int carry=0, crycnt=0;

        if(str1[0]=='0' && str2[0]=='0') break;
        else
        {
            len1=strlen(str1);
            len2=strlen(str2);
            len_max=(len1>=len2)?len1:len2;

            for(i=0;i<len1;i++) num1[len1-i-1]=str1[i]-'0';

            for(i=0;i<len2;i++) num2[len2-i-1]=str2[i]-'0';

            for(i=0;i<len_max;i++) num3[i]=num1[i]+num2[i];

            for(i=0;i<len_max;i++)
            {
                num3[i]+=carry;
                carry=num3[i]/10;
                num3[i]=num3[i]%10;
                num1[i]=0;
                num2[i]=0;

                if(carry!=0) crycnt++;
            }

            if(crycnt==0) printf("No carry operation.\n");
            else if(crycnt==1) printf("1 carry operation.\n");
            else printf("%d carry operations.\n", crycnt);
        }
    }

    return 0;
}

/*****************************************************

Problem Description
在小學時我們都做過加法的運算，就是把2個整數靠右對齊然後，
由右至左一位一位相加。如果相加的結果大於等於10就有進位
（carry）的情況出現。你的任務就是要判斷2個整數相加時產生了
幾次進位的情況。這將幫助小學老師分析加法題目的難度。

Input
每一列測試資料有2個正整數，長度均小於10位。最後一列有2個0代表輸入結束。

Output
每列測試資料輸出該2數相加時產生多少次進位，請參考Sample Output。
注意進位超過1次時operation有加s

Sample Input
123 456
555 555
123 594
0 0

Sample Output
No carry operation.
3 carry operations.
1 carry operation.

****************************************************/
