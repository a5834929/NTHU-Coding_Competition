#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct T{
	long long int x, y;
}SHAPE;
SHAPE p[100001];
int main(void)
{
	int N, i;
	long long int ans;
	while(scanf("%d", &N)!=EOF){
		ans=0;
		for(i=0;i<N;i++)
			scanf("%lld%lld", &p[i].x, &p[i].y);
		for(i=0;i<N;i++)
			ans+=(p[i%N].x*p[(i+1)%N].y-p[i%N].y*p[(i+1)%N].x);
		if(ans<0) ans = -ans;

		if(ans%2) printf("%lld.5\n", ans/2);
		else printf("%lld.0\n", ans/2);
	}
	return 0;
}
