#include<stdio.h>
int main(){
    while(1){
        int N,L,V;
        scanf("%d %d %d",&N,&L,&V);
        if(N==0&&L==0&&V==0){
            return 0;
        }

            double t=0;
            double sum=0;
            int Lmax=0;
        while(N--){
            int length;
            int pos;
            char sex;
            char direction;
            scanf("%d %c %c",&pos,&sex,&direction);
            if(direction=='W'){
                length=pos;
            }
            else{
                length=L-pos;
            }

            if(length>Lmax){
                Lmax=length;
            }

            sum+=length;

        }
        t=(double)Lmax/V;
        printf("%.2f %.2f\n",t,sum);

        

    }
}