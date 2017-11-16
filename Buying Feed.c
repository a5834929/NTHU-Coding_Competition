#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void*p, const void*q);
int main(void)
{
	int k, e, n, f[105][3], i, ans, buy;
	while(scanf("%d%d%d", &k, &e, &n) != EOF){
		for(i=0; i<n; i++){
			scanf("%d%d%d", &f[i][0], &f[i][1], &f[i][2]);
			f[i][2] += e - f[i][0];
		}
		qsort(f, n, sizeof(f[0]), cmp);
		buy = ans = 0;
		for(i=0; buy+f[i][1] <= k; i++){
			buy += f[i][1];
			ans += f[i][1] * f[i][2];
		}
		if(buy < k) ans += (k-buy) * f[i][2];
		printf("%d\n", ans);
	}
    return 0;
}
int cmp(const void*p, const void*q){
	int *a = (int*)p, *b = (int*)q;
	if(a[2] != b[2]) return a[2] - b[2];
	else return a[0] - b[0];
}
