
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int len;
    int arr[155];
}Cycle;

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        int b[155];
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }


        int visited[155]={0};
        Cycle cycles[155];
        int cycle_cnt=0;


        for(int i=1;i<=n;i++){
            if(!visited[i]){
                int cur=i;
                int idx=0;
                int temp[155];


                while(!visited[cur]){
                    visited[cur]=1;
                    temp[idx++]=cur;
                    cur=b[cur];
                }


                int min_pos=0;
                for(int j=1;j<idx;j++){
                    if(temp[j]<temp[min_pos]) min_pos=j;
                }


                Cycle cyc;
                cyc.len=idx;
                for(int j=0;j<idx;j++){
                    cyc.arr[j]=temp[(min_pos+j)%idx];
                }


                cycles[cycle_cnt++]=cyc;
            }
        }



        for(int i=0;i<cycle_cnt-1;i++){
            for(int j=i+1;j<cycle_cnt;j++){
                if(cycles[j].arr[0]<cycles[i].arr[0]){
                    Cycle tmp=cycles[i];
                    cycles[i]=cycles[j];
                    cycles[j]=tmp;
                }
            }
        }



        for(int i=0;i<cycle_cnt;i++){
            printf("(");
            for(int j=0;j<cycles[i].len;j++){
                printf("%d",cycles[i].arr[j]);
                if(j<cycles[i].len-1) printf(",");
            }
            printf(")");
        }
        
        printf("\n");
    }
    return 0;
}
