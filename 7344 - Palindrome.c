#include<stdio.h>
#include<string.h>
int max(int a, int b);
int dp[5004][5004];
int main(){
	char s1[5004], s2[5004];
	int len, i, j;

	while(scanf("%d", &len)!=EOF){
		scanf("%s", &s1[1]);
		memset(dp, 0, sizeof(dp));
		for(i=len;i>0;i--)
			s2[len-i+1]=s1[i];
		for(i=1;i<=len;i++){
			for(j=1;j<=len;j++){
				if(s1[i]==s2[j])
					dp[i][j]=max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]+1));
				else
					dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
		printf("%d\n", len-dp[len][len]);
	}
	return 0;
}

int max(int a, int b){
	return (a<b)?b:a;
}

