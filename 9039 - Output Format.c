#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SPACE "                    "

typedef struct _s
{
    char str[25];
    int len;
}STRING;
STRING string[110];

int main(void)
{
    int n, m, i;

    scanf("%d", &n);

    while(n--)
    {
        scanf("%d", &m);
        for(i=1;i<=m;i++)
        {
            scanf("%s", string[i].str);
            string[i].len=strlen(string[i].str);
        }

        for(i=1;i<=m;i++)
        {
            printf("%.*s%s", 20-string[i].len, SPACE, string[i].str);
            if(!(i%4))
                printf("\n");
        }

        if(!((i-1)%4))
            printf("\n");
        else
            printf("\n\n");
    }
    return 0;
}

/***********************************************************

Problem Description
Output the given strings according to the defined format.

Input
The first line of input contains a positive integer t (t <= 20),
which indicates the number test cases.  For each case, the first
line contains one positive integer n (n <= 100) indicating the
number of strings.  In the next n lines, one string is appeared
per line.  The length of each string is between 1 and 20.

Output
The output format is as follows.  First, each line has 4 strings.
Second, each string occupies 20 spaces and right aligned.
Print a blank line after each case.

Sample Input
1
10
oDAAQLCV
KTFmaNeByBzslUNH
yQRHGGTy
mwEgTpx
hCQWGNuHGTNs
h
fhSPckcOHnQDNT
VjFJKJhdBxPPSggCq
VxBVidLf
wbeg

Sample Output
            oDAAQLCV    KTFmaNeByBzslUNH            yQRHGGTy             mwEgTpx
        hCQWGNuHGTNs                   h      fhSPckcOHnQDNT   VjFJKJhdBxPPSggCq
            VxBVidLf                wbeg

***********************************************************/
