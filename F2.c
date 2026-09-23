#include<stdio.h>
#include<stdlib.h>

int cmp(const void* a,const void *b){
    return *(int*)a-*(int*)b;
}




int erfen(int rock[],int a,int length){
    int left=0;
    int right=length;

    while(left<right){
        int mid=(left+right)/2;
        if(rock[mid]>=a){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return left;
}

int main(){
    int N,M;
    scanf("%d %d",&N,&M);
    int rock[100000];
    for(int i=0;i<N;i++){
        scanf("%d",&rock[i]);
    }
    qsort(rock,N,sizeof(int),cmp);





    for(int i=0;i<M;i++){
        int h;
        scanf("%d",&h);
        int goal=erfen(rock,h,N);
        printf("%d\n",N-goal);
        
    }




return 0;



}