#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int E;
typedef struct Stack{
    E data;
    struct Stack* next;
}Stack;

Stack* initStack(){
    Stack* s=malloc(sizeof(Stack));
    s->data=0;
    s->next=NULL;
    return s;
}

int isEmpty(Stack* s){
    if(s->next==NULL){
        printf("空的\n");
        return 1;
    }
    else{
        return 0;
    }
}


int push(Stack* s,E e){
    Stack *p=(Stack*)malloc(sizeof(Stack));
    p->data=e;
    p->next=s->next;
    s->next=p;
    return 1;
}


int pop(Stack* s,E* e){
    if(s->next==NULL){
        printf("空的\n");
        return 0;
    }
    *e=s->next->data;
    Stack *q=s->next;
    s->next = q->next;
    free(q);
    return 1;
}



int getTop(Stack* s,E* e){
    if (s->next==NULL){
        printf("空的\n");
        return 0;
    }
    *e = s->next->data;
    return 1;
    
}