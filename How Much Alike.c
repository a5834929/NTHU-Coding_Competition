#include<stdio.h>
int main(void)
{
	int A[50005], B[50005], i, j, c, match, cnt, a, b;
	
	while(scanf("%d %d", &a, &b) && (a&&b))
	{
		for(i=0;i<a;i++) scanf("%d", &A[i]);
		for(i=0;i<b;i++) scanf("%d", &B[i]);
		
		cnt = 0;
		for(i=0;i<a-2;i++)
		{
			c = A[i]-B[0];
			match = 1;
			for(j=0;j<b;j++)
			{
				if(B[j]+c!=A[i+j])
				{
					match = 0;
					break;
				}
			}
			if(match) cnt++;
		}
		
		printf("%d\n", cnt);
	}
	
	return 0;
}
