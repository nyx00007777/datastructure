#include <stdio.h>
#include <stdlib.h>  // 链式必须用 malloc
typedef int E;

// 1. 链式队列节点
typedef struct QNode {
    E data;
    struct QNode* next;         //定义两个结构体：1.一个是节点Node  2.一个是管理Node的便捷工具
} QNode;                            

// 2. 链式队列（队头 + 队尾指针）
typedef struct {
    QNode* front;  // 队头指针
    QNode* rear;   // 队尾指针
} Queue;

// ------------------- 链式队列常用函数 -------------------

// 1. 初始化队列
Queue* initQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    QNode* head = (QNode*)malloc(sizeof(QNode));  // 头结点
    head->next = NULL;
    q->front = q->rear = head;  // 头尾都指向头结点
    return q;
}

// 2. 判断队列是否为空
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// 3. 入队（尾部插入）
void enQueue(Queue* q, E e) {
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    newNode->data = e;
    newNode->next = NULL;

    q->rear->next = newNode;
    q->rear = newNode;  // 队尾后移
}

// 4. 出队（头部删除）
int deQueue(Queue* q, E* e) {
    if (isEmpty(q)) {
        printf("队空\n");
        return 0;
    }

    QNode* temp = q->front->next;  // 要删除的节点
    *e = temp->data;

    q->front->next = temp->next;

    // 如果是最后一个节点，rear 要回退
    if (q->rear == temp) {
        q->rear = q->front;
    }

    free(temp);
    return 1;
}

// 5. 获取队列长度
int getLength(Queue* q) {
    int len = 0;
    QNode* p = q->front->next;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

// 6. 获取第 i 个元素（以队头为第 1 个）
int getElement(Queue* q, int i, E* e) {
    if (i < 1) return 0;

    QNode* p = q->front->next;
    int pos = 1;

    while (p && pos < i) {
        p = p->next;
        pos++;
    }

    if (!p) {
        printf("越界\n");
        return 0;
    }

    *e = p->data;
    return 1;
}

// 7. 打印队列
void printQueue(Queue* q) {
    QNode* p = q->front->next;
    printf("队列：");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// ------------------- 测试 -------------------
int main() {
    Queue* q = initQueue();

    enQueue(q, 10);
    enQueue(q, 20);
    enQueue(q, 30);

    printQueue(q);
    printf("长度：%d\n", getLength(q));

    E e;
    deQueue(q, &e);
    printf("出队：%d\n", e);
    printQueue(q);

    getElement(q, 2, &e);
    printf("第2个:%d\n", e);
}