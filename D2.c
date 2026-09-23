#include<stdio.h>
#include<math.h>
int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int a=pow(N-1,M);
    int b;
    if(M%2==0){
        b=N-1;
    }
    else{
        b=1-N;
    }


    printf("%d",(a+b)/N);
}