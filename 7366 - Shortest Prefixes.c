#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct t{
	int done;
	struct t* next[100];
}node;
node* root;

node* ini(void){
	int i;
	node* ans=malloc(sizeof(node));
	for(i=0;i<100;i++)
		ans->next[i]=NULL;
	ans->done=0;
	return ans;
}

void Add(char* input){
	int i, len;
	len=strlen(input);
	node* now=root;
	for(i=0;i<len;i++){
		if(now->next[input[i]-'a']==NULL)
			now->next[input[i]-'a']=ini();
		now->next[input[i]-'a']->done++;
		now=now->next[input[i]-'a'];
	}
}

void Find(char* input){
	int i, len;
	len=strlen(input);
	node* now=root;
	for(i=0;i<len;i++){
		printf("%c", input[i]);
		if(now->next[input[i]-'a']==NULL)
			break;
		if(now->next[input[i]-'a']->done==1)
			break;
		now=now->next[input[i]-'a'];
	}
	return ;
}

int main(void){
	char input[1010][50];
	int i=0, j;
	root=ini();
	while(scanf("%s",input[i])!=EOF && input[i][0] != '-'){
		Add(input[i]);
		i++;
	}
	for(j=0;j<i;j++){
		printf("%s ", input[j]);
		Find(input[j]);
		printf("\n");
	}
	return 0;
}
