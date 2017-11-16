#include<stdio.h>
int main(void)
{
	int A, B, x, y;
	
	while(scanf("%d %d %d %d", &A, &B, &x, &y))
	{
		if((A==0)&&(B==0)&&(x==0)&(y==0)) break;
	
		printf("%d %d\n", x+B, y-A);
	}
	
	return 0;
}
