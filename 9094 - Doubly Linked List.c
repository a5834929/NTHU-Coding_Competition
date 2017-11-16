#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct list_node
{
    int data;
    struct list_node* next;
    struct list_node* pre;
}NODE;

NODE* head;
NODE* tail;
NODE* mid;

int main(void)
{
    NODE *node, *temp;
    int total=0, num;
    char str[10];

    while(scanf("%s", str)!=EOF)
    {
        temp=(NODE*)malloc(sizeof(NODE));
        if(strcmp(str, "IH")==0)
        {
            scanf("%d", &num);
            if(!total){
                temp->data=num;
                temp->next=NULL;
                temp->pre=NULL;
                head=tail=mid=temp;
            }
            else
            {
                temp->data=num;
                temp->next=head;
                temp->pre=NULL;
                head=temp;
            }
            total++;
        }

        else if(strcmp(str, "IT")==0)
        {
            scanf("%d", &num);
            if(!total)
            {
                temp->data=num;
                temp->next=NULL;
                temp->pre=NULL;
                head=temp;
                mid=temp;
                tail=temp;
            }
            else
            {
                temp->data=num;
                temp->next=NULL;
                temp->pre=tail;
                tail=temp;
            }
            total++;
        }

        else if(strcmp(str, "RH")==0)
        {
            printf("%d\n", head->data);
            head=head->next;
            head->pre=NULL;
            free(head->pre);
            total--;
        }

        else if(strcmp(str, "RT")==0)
        {
            printf("%d\n", tail->data);
            tail=tail->pre;
            tail->next=NULL;
            free(tail->next);
            total--;
        }

    }

    return 0;
}


/************************************

Problem Description
Maintain a doubly linked list, which supports the following operations:

(1) IH i : Insert a new integer i to the head of the list.

(2) IT i : Insert a new integer i to the tail of the list.

(3) RH : Print and remove the element in the head of the list.

(4) RT : Print and remove the element in the tail of the list.

(5) S : Swap the first floor(k/2) elements and the last k - floor(k/2) elements,
    where k is the total number of elements in the list. For example, if k = 5,
    the result of swapping a1, a2, a3, a4, a5 will be a3, a4, a5, a1, a2.

To improve the performance, it is suggested that three pointers be maintained: head,
tail and middle, where middle points to the floor(k/2) + 1-th element. With the help
of these pointers, all of the operations can be done in constant time.

Input
There is only a single set of input and each operation will occupy a line.
There will be a space between "IH" and "IT", and "RH" and "RT". The input contains
no more than 500000 operations, and it is terminated by end-of-file (EOF).
You may assume that i will fit in a 32-bit signed integer. The list is initially empty.

Output
For each "RH" or "RT" operation, print a line containing the removed integer as
commanded by the operation.

Sample Input
IT 10
IH 27
IT 2011
IT 114
IH 207
S
RT
RH

Sample Output
27
10

**************************************/


