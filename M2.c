#include<stdio.h>
int main(){
    int N,M;
    sacnf("%d,%d",&N,&M);
    int s[2001];
    for(int i=0;i<N;i++){
        scanf("%d",&s[i]);
    }


    int Q;
    scanf("%d",&Q);
    while(Q--){
        int l,r;
        scanf("%d,%d",&l,&r);
        int count1[2001]={0};
        int count2;
        for(int i=l-1;i<r;i++){
            count1[i]=1;
        }
        for(int i=0;i<2001;i++){
            if(count1[i]==1){
                count2++;
            }
        }

        printf("%d\n",count2);
    }

    return 0;
}