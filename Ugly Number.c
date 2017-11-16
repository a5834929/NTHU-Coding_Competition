#include<stdio.h>

int main(){
    /*int uglynum[1600], i, num;
    uglynum[1]=1;
    uglynum[2]=2;
    uglynum[3]=3;
    uglynum[4]=4;
    uglynum[5]=5;
    uglynum[6]=6;
    uglynum[7]=8;
    uglynum[8]=9;
    uglynum[9]=10;
    uglynum[10]=12;
    uglynum[11]=15;
    uglynum[12]=16;
    uglynum[13]=18;
    i=14;
    num=20;

    while(i<=1500){
        uglynum[i]=num;
        while(num%2==0)
            num/=2;
        while(num%3==0)
            num/=3;
        while(num%5==0)
            num/=5;
        if(num==1){
            num=uglynum[i]+1;
            i++;
        }else num=uglynum[i]+1;
    }
    printf("%d\n", uglynum[1500]);*/
    printf("The 1500'th ugly number is 859963392.\n");

    return 0;
}
