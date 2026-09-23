#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int num=0;
        int N;
        scanf("%d",&N);
        getchar();
        char goal[20];
        gets(goal);
        int len=strlen(goal);
        if(goal[len-1]=='\n') goal[len-1]='\0';
        while(N--){
            int flag=0;
            char word[100];
            gets(word);
            char* p=strtok(word," ");
            if(word[len-1]=='\n') word[len-1]='\0';
            while(p!=NULL&&flag==0){
                if(strcmp(p,goal)==0){
                    flag=1;
                    num++;
                    break;
                }
                p=strtok(NULL," ");
            }
        }
        if(num==0){
            printf("Do not find\n");
        }
        else{
            printf("%d\n",num);
        }
        printf("\n");
    }
    return 0;
}
