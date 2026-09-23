#include<stdio.h>
long long a[100010];  
long long b[100010];
long long pos[100010];

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        for(int i=1;i<=n-1;i++){
            scanf("%lld",&b[i]);
        }
        pos[1] = 0;
        for(int k=2;k<=n;k++){
            pos[k]=pos[k-1]+a[k-1]+b[k-1];
        }
        double min_L=0.0;
        double max_L=1e18;
        int possible=1;
        for(int k=1;k<=n-1;k++){
            long long left=pos[k+1];
            long long right=pos[k+1] + a[k+1];
            double low=(double)left/k;
            double high=(double)right/ k;
            if(low>min_L) min_L=low;
            if(high< max_L) max_L=high;
            if(min_L>max_L){
                possible=0;
                break;
            }
        }
        if(possible){
            printf("%.2f\n", min_L);
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}