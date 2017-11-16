#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char str1[100000], str2[100000], temp[100000];
int num1[100000]={0}, num2[100000]={0}, num3[100000]={0};

int main(void){
    int i, j, carry, lenmax, flag, point, len1, len2, nonz;

    while(scanf("%s %s", str1, str2)!=EOF){
        memset(num1, 0, sizeof(num1));
        memset(num2, 0, sizeof(num2));
        memset(num3, 0, sizeof(num3));
        point=0;

        if(str1[0]!='-' && str2[0]!='-'){
            for(i=0;i<strlen(str1);i++) num1[i]=str1[strlen(str1)-i-1]-'0';
            for(i=0;i<strlen(str2);i++) num2[i]=str2[strlen(str2)-i-1]-'0';

            lenmax=(strlen(str1)>strlen(str2))?strlen(str1):strlen(str2);
            carry=0;

            for(i=0;i<=lenmax;i++) num3[i]=num1[i]+num2[i];

            for(i=0;i<=lenmax;i++){
                num3[i]+=carry;
                carry=num3[i]/10;
                num3[i]%=10;
            }

            for(i=lenmax;i>=0;i--)
                if(num3[i]!=0){
                    point=i;
                    break;
                }

            for(i=point;i>=0;i--)
                printf("%d", num3[i]);
        }

        else if(str1[0]=='-' && str2[0]=='-'){
            for(i=0;i<strlen(str1)-1;i++) num1[i]=str1[strlen(str1)-i-1]-'0';
            for(i=0;i<strlen(str2)-1;i++) num2[i]=str2[strlen(str2)-i-1]-'0';

            lenmax=(strlen(str1)>strlen(str2))?strlen(str1)-1:strlen(str2)-1;
            carry=0;

            for(i=0;i<=lenmax;i++) num3[i]=num1[i]+num2[i];

            for(i=0;i<=lenmax;i++){
                num3[i]+=carry;
                carry=num3[i]/10;
                num3[i]%=10;
            }

            for(i=lenmax;i>=0;i--)
                if(num3[i]!=0){
                    point=i;
                    break;
                }
            if(point) printf("-");
            for(i=point;i>=0;i--)
                printf("%d", num3[i]);
        }

        else{
            if(str1[0]=='-' && str2[0]!='-'){
                strcpy(temp, str1);
                strcpy(str1, str2);
                strcpy(str2, temp);
            }

            for(i=0;i<strlen(str2);i++)
                temp[i-1]=str2[i];
            temp[i-1]='\0';
            strcpy(str2, temp);

            if(str2[0]=='0'){
                nonz=0;
                for(i=1;i<strlen(str2);i++){
                    if(str2[i]!='0'){
                        nonz=i;
                        break;
                    }
                }
                if(!nonz){
                    temp[0]='0';
                    temp[1]='\0';
                }
                else{
                    for(j=nonz;j<strlen(str2);j++)
                            temp[j-nonz]=str2[j];
                    temp[strlen(str2)-nonz]='\0';
                }
                strcpy(str2, temp);
            }
            if(str1[0]=='0'){
                nonz=0;
                for(i=0;i<strlen(str1);i++){
                    if(str1[i]!='0'){
                        nonz=i;
                        break;
                    }
                }
                if(!nonz){
                    temp[0]='0';
                    temp[1]='\0';
                }
                else{
                    for(j=nonz;j<strlen(str1);j++)
                        temp[j-nonz]=str1[j];
                    temp[strlen(str1)-nonz]='\0';
                }
                strcpy(str1, temp);
            }

            for(i=0;i<strlen(str1);i++) num1[i]=str1[strlen(str1)-i-1]-'0';
            for(i=0;i<strlen(str2);i++) num2[i]=str2[strlen(str2)-i-1]-'0';

            lenmax=(strlen(str1)>strlen(str2))?strlen(str1):strlen(str2);

            len1=strlen(str1);
            len2=strlen(str2);
            flag=0;

            if(len1>len2){
                for(i=0;i<lenmax;i++){
                    if(num1[i]<num2[i]){
                        num3[i]=num1[i]+10-num2[i];
                        num1[i+1]-=1;
                    }
                    else num3[i]=num1[i]-num2[i];
                }
                for(i=lenmax-1;i>=0;i--){
                    if(num3[i]!=0){
                        point=i;
                        break;
                    }
                }
                for(i=point;i>=0;i--) printf("%d", num3[i]);
            }

            else if(len1<len2){
                for(i=0;i<lenmax;i++){
                    if(num1[i]>num2[i]){
                        num3[i]=num2[i]+10-num1[i];
                        num2[i+1]-=1;
                    }
                    else num3[i]=num2[i]-num1[i];
                }
                printf("-");
                for(i=lenmax-1;i>=0;i--){
                    if(num3[i]!=0){
                        point=i;
                        break;
                    }
                }
                for(i=point;i>=0;i--) printf("%d", num3[i]);
            }

            else{
                for(i=lenmax-1;i>=0;i--){
                    if(num1[i]<num2[i]) break;

                    else if(num1[i]>num2[i]){
                        flag=1;
                        break;
                    }

                    else if(i==0){
                        flag=-1;
                        printf("0");
                        break;
                    }
                }

                if(flag==0){
                    for(i=0;i<lenmax;i++){
                        if(num2[i]<num1[i]){
                            num3[i]=num2[i]+10-num1[i];
                            num2[i+1]-=1;
                        }
                        else num3[i]=num2[i]-num1[i];
                    }
                    printf("-");

                    for(i=lenmax-1;i>=0;i--)
                        if(num3[i]!=0){
                            point=i;
                            break;
                        }

                    for(i=point;i>=0;i--) printf("%d", num3[i]);
                }

                else if(flag==1){
                    for(i=0;i<lenmax;i++){
                        if(num1[i]<num2[i]){
                            num3[i]=num1[i]+10-num2[i];
                            num1[i+1]-=1;
                        }
                        else num3[i]=num1[i]-num2[i];
                    }

                    for(i=lenmax-1;i>=0;i--)
                        if(num3[i]!=0){
                            point=i;
                            break;
                        }

                    for(i=point;i>=0;i--) printf("%d", num3[i]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}


/******************************************************

Problem Description
給你兩個數字，請輸出他們的和

Input
輸入有多組問題，每組有兩個數字a ,b (−6 * 10^100 ≤ a, b ≤ 6 * 10^100)

Output
對於每組問題請輸出他的總和

Sample Input
100 100
-10 20
111 -222
010 010
0 -0

Sample Output
200
10
-111
20
0

******************************************************/
