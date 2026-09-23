#include<stdio.h>
#include<stdlib.h>
typedef int E;
#define E_FORMAT "%d"
typedef struct {
    E* elem;
    int capacity;//array的总容量   即array最多能存多少个元素
    int length;//array中实际元素个数  即array已经存入了多少个元素
}SeqList;

_Bool initList(SeqList*L,int capacity){
    L->elem=malloc(sizeof(E)*capacity);
    if(L->elem==NULL){
        printf("创建失败");
        return 0;
        L->capacity=capacity;
        L->length=0;
    }
}


_Bool insList(SeqList*L,int index,E element){
    if(index<=0||index>L->length+1){
        printf("index不合法");
        return 0;
    }


    if(L->length==L->capacity){
        int Newcapacity=L->capacity*2;
        E* Newelem=realloc(L->elem,sizeof(E)*Newcapacity);
        L->elem=Newelem;
        L->capacity=Newcapacity;
    }

    for(int i=L->length;i>=index;i--){
        L->elem[i]=L->elem[i-1];
    }
    L->elem[index-1]=element;
    L->length++;
    return 1;
}


_Bool delList(SeqList*L,int index){
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


void printList(SeqList* L){
    for(int i=0;i<L->length;i++){
        printf(E_FORMAT,L->elem[i]);
        printf("\n");
    }
}

E* GetList(SeqList*L,int index){
    if(index<=0||index>L->length){
        return NULL;
    }
    return &L->elem[index-1];
}


int main(){
    SeqList L;
    if(initList(&L,10)){
        for(int i=0;i<=30;i++){
            insList(&L,i+1,i*10);
        }
        printList(&L);

    }
    return 0;
}