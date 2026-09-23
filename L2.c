#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(n==1){
            printf("0\n");
            continue;

        }

        if(n==2){
            if(k>=1){
                printf("1\n");
            }
            else{
                printf("0\n");
            }
            continue;
        }
        if(k<2){
            printf("0\n");
            continue;
        }
        else{
            int max1=n*k/2;
            int max2=n*(n-1)/2;
            if(max1<=max2){
                printf("%d\n",max1);
            }
            else{
                printf("%d\n",max2);
            }
        }
    }

    return 0;
}