#include<stdio.h>
void PrimeTable(void);
int CheckPrime(int x);
int tPrime[100005], n_prime=0;
int main(){
    int T, i, m, M;

    PrimeTable();
    scanf("%d", &T);

    while(T--){
        scanf("%d%d", &m, &M);
        if(m==1)
            m=2;
        for(i=m;i<=M;i++){
            if(CheckPrime(i)){
                printf("%d\n", i);
            }
        }
        if(T!=0)
            printf("\n");
    }
    return 0;
}

void PrimeTable(void){
     int MAX=100000;
     int i, j, isPrime;
     tPrime[0]=2;
     tPrime[1]=3;
     n_prime=2;

     for(i=5;i<=MAX;i+=2){
        isPrime=1;
        for(j=0;j<n_prime;j++){
            if(i%tPrime[j]==0){
                isPrime=0;
                break;
            }
            if(tPrime[j]*tPrime[j]>=i)
                break;
        }
        if(isPrime){
            tPrime[n_prime]=i;
            n_prime++;
        }
     }
}

int CheckPrime(int x){
    int i, isPrime;
    for(i=0;i<n_prime;i++){
        isPrime=1;
        if(tPrime[i]*tPrime[i]>x)
            break;
        if(x%tPrime[i]==0){
            isPrime=0;
            break;
        }
    }
    return isPrime;
}
