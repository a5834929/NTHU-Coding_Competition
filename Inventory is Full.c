#include<stdio.h>
#include<string.h>
int main(void){
	int coin[6] = {1, 5, 10, 50, 100, 200};
	int dp[2010], i, j, a, b;

	memset(dp, 0, sizeof(dp));

	for(j=1;j<2002;j++){
		a = j;
		for(i=5;i>=0;i--){
			while(a>=coin[i]){
				a -= coin[i];
				dp[j]++;
			}
		}
	}

	while(scanf("%d.%d", &a, &b) && (100*a+b)!=0){
		printf("%d\n", dp[100*a+b]);
	}
	return 0;
}
