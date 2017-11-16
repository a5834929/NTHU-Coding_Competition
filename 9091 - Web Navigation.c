#include<stdio.h>
#include<string.h>

int main(void)
{
    char web[10000][101];
    char str[50];
    int i, j;
    i=0;
    j=0;
    strcpy(web[0], "http://www.acm.org/");
    while(scanf("%s", str)!=EOF)
    {
        if(strcmp(str, "QUIT")==0) break;

        if(strcmp(str, "VISIT")==0)
        {
            scanf("%s", &web[++i]);
            printf("%s\n", web[i]);
            j=i;
        }

        else if(strcmp(str, "BACK")==0)
        {
            if(i>0)
            {
                --i;
                printf("%s\n", web[i]);
            }
            else printf("Ignored\n");
        }

        else if(strcmp(str, "FORWARD")==0)
        {
            if(j>i)
            {
                ++i;
                printf("%s\n", web[i]);
            }
            else printf("Ignored\n");
        }
    }
    return 0;
}


/************************************************

Problem Description
It is a common feature that the web browsers support moving
backward and forward among the pages recently visited.
Please simulate this function, which uses two stacks, backward stack
and forward stack, and is commanded by following keywords.

(1) VISIT <url> - Push the current page on the top of the backward stack,
    and make the page specified by URL become the new current page.
    The entries in forward stack are then discarded.

(2) BACK - Push the current page on the top of the forward stack and pop
    the page from the top of the backward stack, which becomes the new current page.
    If the backward stack is empty, this command should be ignored.

(3) FORWARD - Push the current page on the top of the backward stack and pop
    the page from the top of the forward stack, which becomes the new current page.
    If the forward stack is empty, this command should be ignored.

Assume that the browser initially loads the web page at the URL ¡§http://www.acm.org/¡¨.

Input
There is only one set of commands in the input. Each command occupies a line,
and the length of URLs will be no more than 100 and they contain no space character.
The number of commands will be no more than 100000, and the input is terminated by
end-of-file (EOF). You may assume that the entries in the stack will be no more than 10000 at any time.

Output
For each command, output the URL of the current page after the command is executed,
in a line. In case that the command is ignored, print ¡§Ignored¡¨ instead.

Sample Input
VISIT http://acm.ashland.edu/
VISIT http://acm.baylor.edu/acmicpc/
BACK
BACK
BACK
FORWARD
VISIT http://www.ibm.com/
BACK
BACK
FORWARD
FORWARD
FORWARD

Sample Output
http://acm.ashland.edu/
http://acm.baylor.edu/acmicpc/
http://acm.ashland.edu/
http://www.acm.org/
Ignored
http://acm.ashland.edu/
http://www.ibm.com/
http://acm.ashland.edu/
http://www.acm.org/
http://acm.ashland.edu/
http://www.ibm.com/
Ignored

*************************************************/
