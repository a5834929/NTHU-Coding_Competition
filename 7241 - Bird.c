#include<stdio.h>
#include<string.h>

int main(void)
{
    char url[100];

    while(scanf("%s", url)!=EOF)
    {
        if(strcmp(url, "http://img.com/Bird/001.gif")==0) printf("A\n");
        else if(strcmp(url, "http://img.com/Bird/002.gif")==0) printf("B\n");
        else if(strcmp(url, "http://img.com/Bird/012.gif")==0) printf("C\n");
        else if(strcmp(url, "http://img.com/Bird/042.gif")==0) printf("D\n");
        else if(strcmp(url, "http://img.com/Bird/016.gif")==0) printf("E\n");
        else if(strcmp(url, "http://img.com/Bird/105.gif")==0) printf("F\n");
        else if(strcmp(url, "http://img.com/Bird/036.gif")==0) printf("G\n");
        else if(strcmp(url, "http://img.com/Bird/032.gif")==0) printf("H\n");
    }

    return 0;
}


/*********************************************

�p�������w�O�i�R���ϮסAAlan���w�Ω����w���ϮרӦ^���O�H�C
�����w���Ϯצ��h�ءA�H�U�C�X�䤤�X�عϪ��N�X�H�ΥL�����}


A
http://img.com/Bird/001.gif
B
http://img.com/Bird/002.gif
C
http://img.com/Bird/012.gif
D
http://img.com/Bird/042.gif
E
http://img.com/Bird/016.gif
F
http://img.com/Bird/105.gif
G
http://img.com/Bird/036.gif
H
http://img.com/Bird/032.gif

�й��Alan��J�����}��X�����w�Ϫ��N�X

Input
�h�մ���A�C�մ��꣸��A�C�榳�@�Ӻ��}(�u�|�X�{�W���C�X�����})

Output
���C�մ���A��X�����Ϯת��N�X�C

Sample Input
http://img.com/Bird/001.gif
http://img.com/Bird/036.gif
http://img.com/Bird/042.gif
http://img.com/Bird/016.gif

Sample Output
http://img.com/Bird/001.gif
http://img.com/Bird/036.gif
http://img.com/Bird/042.gif
http://img.com/Bird/016.gif

**********************************************/
