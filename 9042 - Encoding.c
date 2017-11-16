#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void encrypt(char str[1000001], int k);
void decrypt(char str[1000001], int k);

int main(void){
    int T, com, k;
    char str[1000001];

    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &com, &k);
        scanf("%s", str);

        if(com==1)
            encrypt(str, k);
        else
            decrypt(str, k);
    }
    return 0;
}

void encrypt(char str[1000001], int k){
    int i, j, len;
    char code[1000001];

    len=strlen(str);
    for(i=0, j=len-1;j>=0;i++, j--)
        code[i]=(str[j]-'A'+k)%26+65;

    code[i]='\0';
    printf("%s\n", code);
}

void decrypt(char str[1000001], int k){
    int i, j, len, c;
    char code[1000001];

    len=strlen(str);
    for(i=0, j=len-1;j>=0;i++, j--){
        c=str[j]-65-k;
        if(c>=0)
            code[i]=c%26+65;
        else
            code[i]=(c%26+26)%26+65;
    }

    code[i]='\0';
    printf("%s\n", code);
}

/***************************************************************

Problem Description
Implement a system to do the encoding and decoding for a text message.
The encoding method has two steps, described as follows:
(1) Reverse the message. For example, ABCD ＠ DCBA
(2) Shift each character by a constant k.
To do that, we first map character ．A・~・Z・ to number 0~25,
and then add a number k to each mapped number, and then map
the shifted number back to characters. If the shifted number exceeds 25,
then mod it by 26. For example, if k = 3, ．Z・+3 = ．C・.

Input
The input includes multiple test cases. The number of test cases T, T <= 1000,
is given in the first line of the input. The next T lines are for test data.
Each line contains two integers and a character string.
The first integer specifies the operation mode: 1 for encryption, and 2 for decryption.
The second integer is the shift k, k <= 100.
The character string, consists of capital English letters only,
is the message to be encoded or to be decoded.
The length of the string is less than or equal to 106.

Output
For each case, output the encoded or decoded text in a single line.

Sample Input
2
1 4 WXYZ
2 4 DCBA

Sample Output
DCBA
WXYZ

**************************************************************/
