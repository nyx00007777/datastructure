#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
      int x,y,t;
      char s[100001];
      scanf("%d %d %d",&x,&y,&t);

    scanf("%s",s);

    if(x==0&&y==0){
        printf("0\n");
        continue;
    }

    int U=0;
    int D=0;
    int L=0;
    int R=0;
    int count=-1;
    for(int i=0;i<t;i++){
        switch(s[i]){
            case 'U':{
                U++;
                break;}
            case 'D':{
                D++;
                break;
            }
            case 'L':{
                L++;
                break;
            }
            case 'R':{
                R++;
                break;
            }
        }

            if(-D<=y&&y<=U&&-L<=x&&x<=R){
                count=i+1;
                break;
            }
    }
    printf("%d\n",count);
    }
    return 0;
}
