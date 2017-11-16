#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int pri(char ch);

int main(void)
{
    char str[1010], stack[1010];
    int i, top, n;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%s", str);
        top=0;

        for(i=0;i<strlen(str);i++)
        {
            if(isdigit(str[i])) printf("%c", str[i]);

            else if(str[i]=='(')
            {
                stack[top]=str[i];
                top++;
            }

            else if(str[i]==')')
            {
                while(stack[top-1]!='(')
                {
                    printf("%c", stack[top-1]);
                    top--;
                }
                top--;
            }

            else if(str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/')
            {
                if(top==0 || stack[top-1]=='(')
                {
                    stack[top]=str[i];
                    top++;
                }

                else
                {
                    if(pri(str[i])>pri(stack[top-1]))
                    {
                        stack[top]=str[i];
                        top++;
                    }

                    else
                    {
                        while(pri(str[i])<=pri(stack[top-1]) && top>0)
                        {
                            if(stack[top-1]!='(')
                            {
                                printf("%c", stack[top-1]);
                                top--;
                            }
                            else break;
                        }
                        stack[top]=str[i];
                        top++;
                    }
                }
            }
        }
        if(i==strlen(str))
        {
            while(top>0)
            {
                printf("%c", stack[top-1]);
                top--;
            }
        }
        printf("\n");
    }

    return 0;
}

int pri(char ch)
{
    if(ch=='*' || ch=='/') return 1;
    else if(ch=='+' || ch=='-') return 0;
    return 0;
}

/********************************************************

Problem Description
術語介紹：若有一算式a+b，則a跟b是運算元，+是運算子。
數學上，最常見的算式就是四則運算式，如：(1+5)*8/2、3*7/9*4等。
此次我們要學習如何處理四則運算式。四則運算表示式是中序(infix)表示式，
要先經過神祕的轉換，轉成後序(postfix)表示式，才好處理。
上述範例的後序表示式為 15+8*2/、37*9/4*
當有後序表示式後，我們可以快速算出答案。
方法是：使用一個Stack，遇到運算元就Push進去，
遇到運算子就Pop最上面的兩個元素，然後作運算子動作，再將結果Push進去。
但由於後序表示式算結果太簡單，故此題我們要考的是如何達成神祕的轉換。
其實，神祕的轉換也是用一個Stack來達成的。
規則是：
1.	左括號(：要直接進Stack
2.	右括號)：要將Stack連續Pop並輸出，直到Pop一個左括號停止(此右括號不用Push)
3.	運算元：直接輸出
4.	運算子：Stack開始Pop，直到(1)最上方元素的優先權小於目前運算子的優先權，
    或是(2)Stack為空才停止。然後，將目前的運算子Push進去
    優先權：”(“ < “+” = “-“ < “*” = “/”

Input
第一個數字N，表示N組測資。接下來N行，每行表示一組測資。
每行最多1000個字元，其中會出現0-9, (, ), +, -, *, /
運算元為一位數字。

Output
對於每組測資，輸出一行該算式的後序表示式。

Sample Input
1
(3+4)/(5-6)*(7+8)

Sample Output
34+56-/78+*

******************************************************/
