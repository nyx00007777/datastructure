#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    getchar();
    int count1=0;
    int count2=0;
    for(int i=0;i<n;i++){
        char num;
        scanf("%c",&num);
        if((num-'0')==(i%2)){
            count1++;
        }
        else{
            count2++;
        }

    }
    int m=(count2/2)+(count2%2);
    int k=(count1/2)+((count1)%2);
    if(m>=k){
        printf("%d",k);
    }
    else{
        printf("%d",m);
    }
    return 0;
}