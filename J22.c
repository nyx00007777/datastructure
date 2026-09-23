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

    int cost1;
    if(count2 % 2 == 0){
        cost1 = count2 / 2;
    }else{
        cost1 = count2;
    }

    int cost2;
    if(count1 % 2 == 0){
        cost2 = count1 / 2;
    }else{
        cost2 = count1;
    }
    if(cost1 < cost2){
        printf("%d",cost1);
    }else{
        printf("%d",cost2);
    }
    return 0;
}