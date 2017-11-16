#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char bull[20][26], cow[20][26];
int match[20][20];

int main(void)
{
	int B, C, i, j, k, n, flag, count;
	while(scanf("%d %d", &B, &C)!=EOF){
		for(i=0;i<B;i++)
			scanf("%s", bull[i]);
		for(i=0;i<C;i++)
			scanf("%s", cow[i]);

		for(i=0;i<B;i++){
			for(j=0;j<C;j++){
				count=0;
				for(k=0;k<B;k++){
					if(k!=i){
						flag=1;
						for(n=0;n<25;n++){
							if(bull[k][n]!=bull[i][n] && bull[k][n]!=cow[j][n]){
								flag=0;
								break;
							}
						}
						if(flag)
							count++;
					}
				}
				for(k=0;k<C;k++){
					if(k!=j){
						flag=1;
						for(n=0;n<25;n++){
							if(cow[k][n]!=bull[i][n] && cow[k][n]!=cow[j][n]){
								flag=0;
								break;
							}
						}
						if(flag)
							count++;
					}
				}
				match[i][j]=count;
			}
		}

		for(i=0;i<B;i++){
			for(j=0;j<C-1;j++)
				printf("%d ", match[i][j]);
			printf("%d\n", match[i][j]);
		}
	}
    return 0;
}
