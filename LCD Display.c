#include<stdio.h>
#include<string.h>
void Print1(int s, int x, int y);
void Print2(int s, int x, int y);
void Print3(int s, int x, int y);
void Print4(int s, int x, int y);
void Print5(int s, int x, int y);
void Print6(int s, int x, int y);
void Print7(int s, int x, int y);
void Print8(int s, int x, int y);
void Print9(int s, int x, int y);
void Print0(int s, int x, int y);

char map[30][200];

int main(){
	int s, len, i, j, count, spac;
	char str[10];

	while(scanf("%d %s", &s, str)!=EOF && !(s==0 && str[0]=='0')){
		len=strlen(str);
		count=0;
		for(i=0;i<2*s+3;i++)
			for(j=0;j<(s+2+1)*(len-1)+s+2;j++)
				map[i][j]=' ';

		for(i=0;i<len;i++){
			if(i==0)
				spac=0;
			else
				spac=1;
			if(str[i]=='1')
				Print1(s, (s+2+spac)*count, 0);
			else if(str[i]=='2')
				Print2(s, (s+2+spac)*count, 0);
			else if(str[i]=='3')
				Print3(s, (s+2+spac)*count, 0);
			else if(str[i]=='4')
				Print4(s, (s+2+spac)*count, 0);
			else if(str[i]=='5')
				Print5(s, (s+2+spac)*count, 0);
			else if(str[i]=='6')
				Print6(s, (s+2+spac)*count, 0);
			else if(str[i]=='7')
				Print7(s, (s+2+spac)*count, 0);
			else if(str[i]=='8')
				Print8(s, (s+2+spac)*count, 0);
			else if(str[i]=='9')
				Print9(s, (s+2+spac)*count, 0);
			else if(str[i]=='0')
				Print0(s, (s+2+spac)*count, 0);
			count++;
		}
		for(i=0;i<2*s+3;i++){
			for(j=0;j<(s+2+1)*(len-1)+s+2;j++)
				printf("%c", map[i][j]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}


void Print1(int s, int x, int y){
	int j;
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
}

void Print2(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';
}

void Print3(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';
}

void Print4(int s, int x, int y){
	int i, j;
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
		for(j=y+1;j<=y+s;j++)
		map[j][x]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
}

void Print5(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';
}

void Print6(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x]='|';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';
}

void Print7(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
}

void Print8(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
		for(j=y+1;j<=y+s;j++)
		map[j][x]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x]='|';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';
}

void Print9(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
		for(j=y+1;j<=y+s;j++)
		map[j][x]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+s+1][i]='-';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';

}

void Print0(int s, int x, int y){
	int i, j;
	for(i=x+1;i<=x+s;i++)
		map[y][i]='-';
	for(j=y+1;j<=y+s;j++)
		map[j][x+s+1]='|';
		for(j=y+1;j<=y+s;j++)
		map[j][x]='|';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x]='|';
	for(j=y+s+2;j<=y+2*s+1;j++)
		map[j][x+s+1]='|';
	for(i=x+1;i<=x+s;i++)
		map[y+2*s+2][i]='-';
}
