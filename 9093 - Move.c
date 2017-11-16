#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _num
{
    int value;
    struct _num *ptr_pre, *ptr_next;
}num;
num *ptr[1000010];

int main()
{
    int N, i, from, to;
    char str[10];
    num *ptr_first, *ptr_new, *ptr_temp;

    scanf("%d", &N);
    ptr_first=ptr[1]=(num*)malloc(sizeof(num));

    for(i=1;i<=N;i++){
        ptr[i]->value=i;
        ptr[i+1]=(num*)malloc(sizeof(num));
        ptr[i+1]->ptr_pre=ptr[i];
        ptr[i]->ptr_next=ptr[i+1];
    }

    scanf("%s", str);
    while(strcmp(str,"Move")==0){
        scanf("%d %d", &from, &to);
        ptr_first->ptr_pre=ptr[to]->ptr_pre;
        ptr[to]->ptr_pre->ptr_next=ptr_first;
        ptr_first=ptr[from]->ptr_next;
        ptr[to]->ptr_pre=ptr[from];
        ptr[from]->ptr_next=ptr[to];
        scanf("%s", str);
    }

    for(i=1;i<N;i++){
        printf("%d ", ptr_first->value);
        ptr_first=ptr_first->ptr_next;
    }
    printf("%d\n", ptr_first->value);

    return 0;
}

/************************************************

Problem Description
There are N numbers in a queue.  The origin sequence is
from 1 to N. (1 is the head). The operation ¡§Move a b¡¨
means to move all the numbers in front of a (including a)
and then insert them in front of b without changing order.
Given several such operations and output the final status of the sequence.

Input
There will be only one test case. The test case begins with an integer N
(1 <= N <= 106) indicating the number of people.  There are several operations followed.
The format is ¡§Move a b¡¨ (without quote) you can assume that the position of a is in front
of the position of b.  The test case is terminated by ¡§Exit¡¨ (without quote).

Output
Output the numbers from the first one to the last one, and separate two consecutive numbers by a space.

Sample Input
5
Move 2 4
Move 2 5
Move 3 2
Exit

Sample Output
1 4 3 2 5

************************************************/
