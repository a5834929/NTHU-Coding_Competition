#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct t{
	int leave;
	struct t* next[26];
	char trans[15];
}node;
node* root;

node* CreateNode(void){
	int i;
	node* ans=malloc(sizeof(node));
	for(i=0;i<26;i++)
		ans->next[i]=NULL;
	ans->leave=0;
	return ans;
}

void Add(char* input, char* tran){
	int i, len;
	len=strlen(input);
	node* now=root;
	for(i=0;i<len;i++){
		if(now->next[input[i]-'a']==NULL)
			now->next[input[i]-'a']=CreateNode();
		now=now->next[input[i]-'a'];
	}
	now->leave++;
	strcpy(now->trans,tran);
}

node* Find(char* input){
	int i, len;
	len=strlen(input);
	node* now=root;
	for(i=0;i<len;i++){
		if(now->next[input[i]-'a']==NULL)
			return NULL;
		now=now->next[input[i]-'a'];
	}
	if(now->leave)
		return now;
	else
		return NULL;
}

int main(void){
	char english[50], foreign[50], ask[15];
	int len, i, j, n;
	node* ans;
	root=CreateNode();
	while(gets(english)){
		n=0;
		len=strlen(english);
		j=len;
		if(len!=0){
			for(i=0;i<len;i++){
				if(english[i]==' ')
					j=i;
				if(i>j){
					foreign[n]=english[i];
					n++;
				}
			}
			foreign[n]='\0';
			english[j]='\0';
			Add(foreign,english);
		}
		else
			break;
	}
	while(scanf("%s", ask)!=EOF){
		ans=Find(ask);
		if(ans==NULL)
			printf("eh\n");
		else
			printf("%s\n", ans->trans);
	}
	return 0;
}
