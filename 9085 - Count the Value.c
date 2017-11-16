#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int cmp(const void*p, const void*q);
typedef struct _P{
    char C;
    int val;
}CHAR;
CHAR data[30];

int main(){
    int v, max, i;
    char ch;
    max=0;
    while(scanf("%c", &ch)!=EOF){
        if(isalpha(ch) && islower(ch)){
            data[ch-'a'].C=ch;
            data[ch-'a'].val+=(ch-'a'+1);
            if((ch-'a')>max)
                max=ch-'a';
        }
    }
    qsort(data, max+1, sizeof(CHAR), cmp);
    for(i=0;i<=max;i++){
        if(data[i].val)
            printf("%c %d\n", data[i].C, data[i].val);
        else break;
    }
    return 0;
}

int cmp(const void*p, const void*q){
    CHAR a=*(CHAR*)p, b=*(CHAR*)q;
    if(a.val!=b.val) return (a.val>b.val)?-1:1;
    else return (a.C<b.C)?-1:1;
}

/************************************************************************************

Problem Description
Given an article, calculate the value of each character and output them in the descending order of their values.
The price of characters is calculated as follows:
one dollar for a letter ¡¥a¡¦, two dollars for a letter ¡¥b¡¦ ¡K and 26 dollars for a letter ¡¥z¡¦.
'A' and 'a' are not the same in this problem, just count the lowercase letters.

Input
The input contains an article, which is terminated by EOF.

Output
Output the total value of each character in the descending order.  Do not print the character not in the article.
If two characters have the same value, output the one with smaller ASCII code first.

Sample Input
aaa2bcddzz
a--a
aaa..

Sample Output
z 52
a 8
d 8
c 3
b 2

***********************************************************************************/
