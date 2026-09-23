#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    while(getchar()!='\n');
    while(T--){
        char ch;
        int i=0;
        char digit[1000]={0};
        while((ch=getchar())!='\n'&&ch!=EOF){
            if(ch>='0'&&ch<='9'){
                digit[i]=ch;
                i++;
            }
            else{
                if(i==0||digit[i-1]=='+'){
                    continue;
                }
                else{
                    digit[i]='+';
                    i++;
                }
            }
        }


long long sum=0;
long long num=0;
for(int m=0;digit[m]!='\0';m++){
if(digit[m]!='+'){
    num=num*10+(digit[m]-'0');
}
else{
    sum+=num;
    num=0;
}

    }
    sum+=num;
    printf("%lld\n",sum);
}
return 0;
}
