#include<stdio.h>
int main(void)
{
	int L, p, x, i;
	long long int w;
	
	while(scanf("%d", &L) && L!=0)
	{
		w = 0;
		p = 0;
		for(i=0;i<L;i++)
		{
			scanf("%d", &x);
			w += (long long int)x*i;
			p += x;
		}
		
		if((w%p)==0) printf("%d\n", w/p);
		else printf("-1\n");
	}
	
	return 0;
}
