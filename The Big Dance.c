#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void divide(int left, int right);
int cow[2500]={0};
int sum;

int main(void)
{
    int N, i, j;

    while(scanf("%d", &N)!=EOF)
    {
        sum=0;
        for(i=1;i<=N;i++)
            cow[i]=i;

        divide(1, N);

        printf("%d\n", sum);
    }

    return 0;
}

void divide(int left, int right)
{
    int mid;

    if(left<right)
    {
        mid=(right+left)/2;
        divide(left, mid);
        divide(mid+1, right);
        if(left==right-1)
            sum+=cow[left]*cow[right];
    }
    return;
}



