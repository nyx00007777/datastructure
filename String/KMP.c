#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 堆串
typedef struct {
    char *ch;
    int length;
} HString;


void Getnext(HString T,int next[]){
    int j=0;
    int k=-1;
    next[0]=-1;
    while(j<T.length-1){
        if(k==-1||T.ch[j]==T.ch[k]){
            j++;k++;
            if(T.ch[j]!=T.ch[k]){
                next[j]=k;
            }else{
                next[j]=next[k];
            }
        }else{
            k=next[k];
        }
    }
}

// KMP：在 串S 中找模式串 T，返回第一次出现位置（1开始），没找到返回 0
int KMP(HString S,HString T,int next[]){
int i=0,j=0;
int n=S.length,m=T.length;
while(i<n&&j<m){
    if(j==-1||S.ch[i]==T.ch[j]){
        i++;j++;
    }else{
        j=next[j];
    }
}
if(j==m){
    return i-j+1; 
}else{
    return -1;
}
}



int main() {
    HString S, T;

    // 主串
    S.ch = "ababcabcacbab";
    S.length = strlen(S.ch);

    // 模式串
    T.ch = "abcac";
    T.length = strlen(T.ch);

    // next 数组
    int next[100];
    Getnext(T, next);

    // KMP 匹配
    int pos = KMP(S, T, next);
    printf("第一次出现位置：%d\n", pos); // 输出 6

    return 0;
}