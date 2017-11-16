#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void)
{
    int map[9][9], queue[1000][2];
    char sr, er;
    int sc, ec;
    int i, j, flag, front, rear;

    while(scanf("%c%d", &sr, &sc)!=EOF)
    {
        getchar();
        flag=0;
        scanf("%c%d", &er, &ec);
        getchar();
        memset(map, 0, sizeof(map));
        memset(queue, 0, sizeof(queue));

        front=0;
        rear=1;
        i=sr-'a'+1;
        j=sc;
        queue[0][0]=i;
        queue[0][1]=j;
        while(!flag)
        {
            if((i==er-'a'+1) && (j==ec))
            {
                printf("To get from %c%d to %c%d takes %d knight moves.\n", sr, sc, er, ec, map[i][j]);
                flag=1;
            }
            else
            {
                if(i+1<=8 && j+2<=8 && map[i+1][j+2]==0)
                {
                    map[i+1][j+2]=map[i][j]+1;
                    queue[rear][0]=i+1;
                    queue[rear][1]=j+2;
                    rear++;
                }
                if(i+1<=8 && j-2>0 && map[i+1][j-2]==0)
                {
                    map[i+1][j-2]=map[i][j]+1;
                    queue[rear][0]=i+1;
                    queue[rear][1]=j-2;
                    rear++;
                }
                if(i-1>0 && j+2<=8 && map[i-1][j+2]==0)
                {
                    map[i-1][j+2]=map[i][j]+1;
                    queue[rear][0]=i-1;
                    queue[rear][1]=j+2;
                    rear++;
                }
                if(i-1>0 && j-2>0 && map[i-1][j-2]==0)
                {
                    map[i-1][j-2]=map[i][j]+1;
                    queue[rear][0]=i-1;
                    queue[rear][1]=j-2;
                    rear++;
                }
                if(i+2<=8 && j+1<=8 && map[i+2][j+1]==0)
                {
                    map[i+2][j+1]=map[i][j]+1;
                    queue[rear][0]=i+2;
                    queue[rear][1]=j+1;
                    rear++;
                }
                if(i+2<=8 && j-1>0 && map[i+2][j-1]==0)
                {
                    map[i+2][j-1]=map[i][j]+1;
                    queue[rear][0]=i+2;
                    queue[rear][1]=j-1;
                    rear++;
                }
                if(i-2>0 && j+1<=8 && map[i-2][j+1]==0)
                {
                    map[i-2][j+1]=map[i][j]+1;
                    queue[rear][0]=i-2;
                    queue[rear][1]=j+1;
                    rear++;
                }
                if(i-2>0 && j-1>0 && map[i-2][j-1]==0)
                {
                    map[i-2][j-1]=map[i][j]+1;
                    queue[rear][0]=i-2;
                    queue[rear][1]=j-1;
                    rear++;
                }
                front++;
                i=queue[front][0];
                j=queue[front][1];
            }
        }
    }
    return 0;
}

/*************************************

Problem Description
�A���@�ӪB�ͥ��b���@�������v�Ѥ��M�h�Ȧ���D�]Traveling Knight Problem�^����s�A
�L�Ʊ�A���L�ѨM�@�Ӱ��D�G�N�O���A2�Ӯ�l����mX��Y�A�ЧA��X�M�h�qX����Y�ֻ̤ݭn���X�B�C

Input
�C�����ո�Ƥ@�C�C�C�C��2�Ӧ�v�Ѫ��y�Ц�m�C�C�Ӧ�m�y�ЬO�Ѥ@�ӭ^��r��
�]a-h�A�N��ѽL���ĴX��^�Τ@�ӼƦr�]1-8�A�N��ѽL���ĴX�C�^�զ��C

Output
��C�@�C��J�A�п�X "To get from xx to yy takes n knight moves.".

Sample Input
e2 e4
a1 b2
b2 c3
a1 h8
a1 h7
h8 a1
b1 c3
f6 f6

Sample Output
To get from e2 to e4 takes 2 knight moves.
To get from a1 to b2 takes 4 knight moves.
To get from b2 to c3 takes 2 knight moves.
To get from a1 to h8 takes 6 knight moves.
To get from a1 to h7 takes 5 knight moves.
To get from h8 to a1 takes 6 knight moves.
To get from b1 to c3 takes 1 knight moves.
To get from f6 to f6 takes 0 knight moves.

*************************************/
