#include<stdio.h>
#define MAXSIZE 1000

typedef struct{
    int data[MAXSIZE];
    int len;
} Seqlist;

void swap(Seqlist* l,int pos){

    int temp[pos];
    for(int i=0;i<pos;i++){
        temp[i]=l->data[i];
    }
    for(int i=0;i<l->len-pos;i++){
        l->data[i]=l->data[i+pos];
    }
    for(int i=l->len-pos;i<l->len;i++){
        l->data[i]=temp[i-l->len+pos];
    }

return 

}