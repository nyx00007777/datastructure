#include<stdio.h>
int main(){
    do{
        int n;
        scanf("%d",&n);
        if(n!=0){
            printf("%d\n",8*n-4);
        }
        else{
            break;
        }
    }while(1);
return 0;
}