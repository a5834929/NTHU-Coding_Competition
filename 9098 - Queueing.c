#include<stdio.h>
#include<string.h>
char que[1000010][11];

int main(){
    char com[10];
    int i, front=0, rear=0;

    while(scanf("%s", com)!=EOF){
        if(strcmp(com, "Front")==0){
            if(front==rear)
                printf("empty\n");
            else
                printf("%s\n", que[front]);
        }
        else if(strcmp(com, "Push")==0){
            scanf("%s", que[rear]);
            rear++;
        }
        else if(strcmp(com, "Pop")==0)
            if(front<rear)
                front++;
    }
    return 0;
}

/*******************************************************************************

Problem Description
You need to write a program to simulate a queue of names.
Each name is a string consisting of English letters only.
There are three operations:

1.¡§Push [name]¡¨, which means to enque name in the queue.

2.¡§Pop¡¨, which means to deque. If the queue is empty, this operation takes no effect.

3.¡§Front¡¨, which means to print out the name in the front of queue.
If the queue is empty, print "empty" (without quotes).

Input
There will be at most 106 operations.
Each line contains one of the following operations.
¡§Push [name]¡¨ (without quotes), ¡§Pop¡¨ (without quotes), ¡§Front¡¨(without quotes).
The length of each name is at most 10.

Output
For each ¡§Front¡¨ operation, print out the name in the front of the queue.

Sample Input
Push Bruce
Push Alan
Front
Pop
Push Tom
Pop
Front
Pop
Pop
Pop
Front

Sample Output
Bruce
Tom
empty

**********************************************************************************/
