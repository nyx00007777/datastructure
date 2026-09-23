#include<stdio.h>
#define MAXSIZE 100
typedef int E;
#define E_FORMAT "%d"
typedef struct{
    E elem[MAXSIZE];
    int length;
}SeqList;


void initList(SeqList*L){
    L->length=0;
}

int ListLength(SeqList*L){          //也可以直接传SeList L，再用L.length
    return L->length;
}                                   


_Bool InsList(SeqList*L,int index,E element){
    if(index<=0||index>L->length+1){
        printf("index不合法");
        return 0;
    }
    for(int i=L->length;i>=index;i--){
        L->elem[i]=L->elem[i-1];
    }
    L->elem[index-1]=element;
    L->length++;
    return 1;
}


_Bool DelList(SeqList*L,int index){
    if(index<=0||index>L->length){
        printf("index不合法");
        return 0;
    }

    for(int i=index-1;i<L->length-1;i++){
        L->elem[i]=L->elem[i+1];
    }
    L->length--;
    return 1;
}

E GetList(SeqList*L,int index){
    if(index<=0||index>L->length){
        printf("index不合法");
        return 0;
    }
    return L->elem[index-1];
}

int Locate(SeqList*L,E element){
    for(int i=0;i<=L->length-1;i++){
        if(L->elem[i]==element){
            return i+1;
        }
    }
    return -1;
}

void DestroyList(SeqList*L){
    L->length=0;
}


void PrintList(SeqList*L){
    for(int i=0;i<L->length;i++){
        printf(E_FORMAT,L->elem[i]);
        printf("\n");
    }
}




_Bool CreatList(SeqList*L,E arr[],int n){       //n不能去掉，然后直接通过sizeof来代替
                                                //因为arr【】传入函数时会被当成指针处理，sizeof（arr）不合法

if(n<0||n>MAXSIZE){
    printf("n不合法");
    return 0;
}                                        for(int i=0;i<n;i++){
    L->elem[i]=arr[i];
}
L->length=n;
printf("创建成功");
return 1;
}



_Bool InsListPlus(SeqList*L,int index,E element){
    if(index<=0){
        printf("index不合法");
        return 0;
    }
    else if(index>L->length+1){
        printf("index过大,自动加在末尾");
        index=L->length+1;                  //可直接修改index
    }
    for(int i=L->length;i>=index;i--){
        L->elem[i]=L->elem[i-1];
    }
    L->elem[index-1]=element;
    L->length++;
    return 1;
}






int main(){
    SeqList L;
    initList(&L);
    for(int i=0;i<=9;i++){
        InsList(&L,1,i*10);
    }
    DelList(&L,5);
    PrintList(&L);
    return 0;
}