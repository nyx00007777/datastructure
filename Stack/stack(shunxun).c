#include<stdio.h>
#define MAXSIZE 100
typedef int E;                   //静态
typedef struct{
    E data[MAXSIZE];
    int top;//栈顶的位置
}Stack;


//#include<stdio.h>             //动态
//#define MAXSIZE 100
//typedef int E;
//typedef struct{
//    E* data;
//    int top;//栈顶的位置
//}Stack;

//Stack* initStack(){
//    Stack* s=malloc(sizeof(Stack));
//    s->data=(E*)malloc(sizeof(E)*MAXSIZE);
//    s->top=-1;
//    return s;
//}
//void initStack(Stack* s){
//    s->top=-1;
//    return s;}




int isEmpty(Stack* s){
    if(s->top==-1){
        printf("空的");
        return 1;
    }
    else return 0;
}


int push(Stack* s,E e){
    if((s->top>=MAXSIZE-1)){
        printf("满了\n");
        return 0;
    }
    s->top++;
    s->data[s->top]=e;
    return 1;
}

int pop(Stack* s,E* e){
    if(s->top==-1){
        printf("空的\n");
        return 0;
    }
    *e=s->data[s->top];
    s->top--;
    return 1;
}


int gettop(Stack *s,E *e){
    if(s->top==-1){
        printf("空的\n");
        return 0;

    }
    *e=s->data[s->top];
    return 1;
}