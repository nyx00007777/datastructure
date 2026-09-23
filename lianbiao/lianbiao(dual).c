#include<stdio.h>
#include<stdlib.h>
typedef int E;
#define E_FORMAT "%d"
typedef struct Node{
    E data;
    struct Node* next;
    struct Node* prev;
}Node,*LinkList;

InitList(LinkList* L){
    Node* head = (Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
    return head;
}


int insertHead(Node* L,E e){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data = e;
    p->prev = L;
    p->next = L->next;
    if(L->next!=NULL){
        L->next->prev=p;
    }
    L->next = p;
    return 1;
}
//遍历
void listNode(Node* L){
    Node* p=L->next;
    while(p!=NULL){
        printf("%d",p->data);
    }
    printf("\n");
}


//获取尾部节点
Node* get_tail(Node* L){
    Node *p=L;
    while(p->next!=NULL){
        p=p->next;
    }
    return p;
}


//尾插
Node* insertTail(Node *tail,E e){
    Node* p=(Node*)malloc(sizeof(Node));
    p->data =e;
    p->prev=tail;
    p->next=NULL;
    tail->next=p;
    return p;
}

//指定位置插入
int insertNode(Node*L,int pos,E e){
    Node *p = L;
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }
    Node* q = (Node*)malloc(sizeof(Node));
    q->data=e;
    q->prev=p;
    q->next=p->next;
    p->next->prev=q;
    p->next=q;
    return 1;
}


//删除
int delNode(Node *L,int pos){
    Node* p=L;
    int i=0;
    while(i<pos-1){
        p=p->next;
        i++;
        if(p==NULL){
            return 0;
        }
    }

    if(p->next==NULL){
        printf("删除位置错误\n");
        return 0;
    }
    Node* q=p->next;
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return 1;
}