#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(void){
    int i, len1, len2;
    char str1[10001], str2[10001], s1[10001], s2[10001];
    while(scanf("%s %s", str1, str2)!=EOF){
        len1=strlen(str1);
        len2=strlen(str2);
        for(i=0;i<len1;i++){
            if(isupper(str1[i]))
                s1[i]=(str1[i]-'A')*2+1;
            else
                s1[i]=(str1[i]-'a')*2+2;
        }
        for(i=0;i<len2;i++){
            if(isupper(str2[i]))
                s2[i]=(str2[i]-'A')*2+1;
            else
                s2[i]=(str2[i]-'a')*2+2;
        }
        s1[len1]=s2[len2]=0;
        if(strcmp(s1, s2)>0)
            printf("%s %s\n", str2, str1);
        else
            printf("%s %s\n", str1, str2);
    }
    return 0;
}

/*****************************************************************

Problem Description
Given two strings, output them in alphabetical order.
Note: the order is AaBbCcDd ... YyZz.

Input
For each case a line, there are two strings separated by a single space.
The lengths of the strings are no more than 30.

Output
For each case a line, output the two strings in alphabetical order,
separated by a single space.

Sample Input
Apple apple
Banana grape
pencil pen
picture picnic

Sample Output
Apple apple
Banana grape
pen pencil
picnic picture

******************************************************************/
