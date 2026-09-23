#include<stdio.h>
#define MAXSIZE 100
typedef int E;
typedef struct Queue{
    E data[MAXSIZE];
    int front;
    int rear;
}Queue;

void initQueue(Queue *Q){
    Q->front=0;                   //front指向队头元素的当前位置      
    Q->rear=0;                    //rear指向队尾元素的下一个位置
}

int isEmpty(Queue* Q){
    if(Q->front==Q->rear){
        printf("空的\n");
        return 1;
    }
    else return 0;
}

int isFull(Queue* Q){
    return (Q->rear+1)%MAXSIZE==Q->front;       //1.牺牲一个空间来区分队满和队空
                                                //否则两个的条件都是rear==front
}
                                                //2.也可以设置一个tag标准，当入队的时候if（front==rear）tag赋值为1，代表队满，出队时候if（front==rear）赋值时tag赋值为0；
                                                //然后就可以通过tag的取值来判断full or empty

//入队
int enQueue(Queue* Q,E e){
    if(isFull(Q)){
        printf("队满\n");
        return 0;
    }
    Q->data[Q->rear]=e;
    Q->rear=(Q->rear+1)%MAXSIZE;
    return 1;

}



//出队
int deQueue(Queue *Q,E *e){
    if(isEmpty(Q)){
        printf("队空\n");
        return 0;
    }

    *e=Q->data[Q->front];
    Q->front=(Q->front+1) % MAXSIZE;
    return 1;
}


//打印队列
void printQueue(Queue* Q){
    if(isEmpty(Q)){
        printf("队空\n");
        return;
    }
    int i=Q->front;
    while(i!=Q->rear){
        printf("%d ",Q->data[i]);
        i=(i+1)%MAXSIZE;
    }
    printf("\n");
}


// 求队列长度
int getLength(Queue *q) {
    // 把环状数组拉直，长度 = 尾位置 - 头位置
    return (q->rear - q->front + MAXSIZE) % MAXSIZE;
}

// 获取第 i 个元素
int getElement(Queue *q, int i, E *e) {
    int len = getLength(q); // 先拿长度

    // 判断 i 是否合法
    if (i < 1 || i > len) {
        printf("下标越界\n");
        return 0;
    }

    // 你的核心思路：
    // 第 i 个元素 = 队头往后数 i-1 位
    int pos = (q->front + i - 1) % MAXSIZE;

    *e = q->data[pos];
    return 1;
}