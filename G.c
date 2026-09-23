#include<stdio.h>
#include<string.h>
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        char s[1001];
        int length=0;
        int start=0;
        scanf("%s",s);
        int max=strlen(s);
        for(int i=0;i<max;i++){
            int r=i;
            int l=i;
            while(l>=0&&r<max&&s[l]==s[r]){
                int len=r-l+1;
                 if(len>length){
                    length=len;
                    start=i;
                }
                l--;
                r++;
              
            
            }



             r=i;
             l=i+1;
            while(l>=0&&r<max&&s[r]==s[l]){
            int len=r-l+1;
                 if(len>length){
                length=len;
                start=i;
            }
            l--;
            r++;
        
            }
        }

        int left=start-length/2;
        if(length%2==0) left++;

        for(int m=left;m<=start+length/2;m++){
            printf("%c",s[m]);
        }
        printf("\n");
    }
    return 0;
}