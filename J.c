#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        long long n;
        scanf("%lld",&n);
        printf("%lld=",n);
        int isfirst=1;
        while(n%2==0){
            if(isfirst){
                printf("2");
                isfirst=0;
            }
            else{
                printf("*2");
            }
            n=n/2;
        }




        long long i=3;

        while(i*i<=n){
            while(n%i==0){
                if(isfirst){
                    printf("%lld",i);
                    isfirst=0;
                }
                else{
                    printf("*%lld",i);
                }
                n=n/i;
            }

            i+=2;
        }




        if(n>1){
            if(isfirst){
                printf("%lld",n);
            }
            else{
                printf("*%lld",n);
            }
        }

        printf("\n");
    }
return 0;
}