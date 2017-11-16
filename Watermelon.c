#include <stdio.h>
int main(void)
{
	long long int a;
	while(scanf("%lld", &a)!=EOF){
		if(a%2 || a==2)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}
