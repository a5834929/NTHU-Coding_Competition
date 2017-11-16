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

小鳥彼爾德是可愛的圖案，Alan喜歡用彼爾德的圖案來回應別人。
彼爾德的圖案有多種，以下列出其中幾種圖的代碼以及他的網址


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

請對於Alan輸入的網址輸出彼爾德圖的代碼

Input
多組測資，每組測資ㄧ行，每行有一個網址(只會出現上面列出的網址)

Output
對於每組測資，輸出對應圖案的代碼。

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
