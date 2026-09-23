#include<stdio.h>
#include<stdlib.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int h,m;
        scanf("%d:%d",&h,&m);
        h=h%12;
        int goal1=12*m;
        int goal2=60*h+m;
        int goal=abs(goal1-goal2);
        if(goal>360){
            goal=720-goal;
        }
        if(goal%2==0){
            printf("%d\n",goal/2);
        }
        else{
            printf("%d/2\n",goal);
        }
        
    }
    return 0;
}