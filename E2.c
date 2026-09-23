#include <stdio.h>
#include <math.h>
#define M_PI 3.141592653589793

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N,R;
        scanf("%d%d",&N,&R);
        int speed1[N+1];
        for(int i=0;i<N;i++){
            scanf("%d",&speed1[i]);
        }

        int sum=0;
        for(int i=0;i<N;i++){
            int speed2;
            if(i==0){
                speed2=speed1[i]-speed1[N-1];
            }
            else{
                speed2=speed1[i]-speed1[i-1];
            }
            if(speed2>0){
                sum+=speed2;
            }
    }
    if(sum==0){
        printf("Inf\n");
    }
    else{
        double t=(double)2*R*M_PI/sum;
        printf("%.3f\n",t);
    }



}

return 0;
}