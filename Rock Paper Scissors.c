#include<stdio.h>
int main(void){
	char str1[10], str2[10];

	while(scanf("%s %s", str1, str2) != EOF){
		if(str1[0]==str2[0]) printf("tie\n");
		else if(str1[0]=='p'){
			if(str2[0]=='s') printf("lose\n");
			else printf("win\n");
		}
		else if(str1[0]=='s'){
			if(str2[0]=='p') printf("win\n");
			else printf("lose\n");
		}
		else{
			if(str2[0]=='s') printf("win\n");
			else printf("lose\n");
		}
	}
	return 0;
}
