//常见题型：1.快慢指针  2.空间换时间


#include<stdio.h>
#include<stdlib.h>
typedef int E;
#define E_FORMAT "%d"
typedef struct Node{
    E data;
    struct Node* next;
}Node,*LinkList;

InitList(LinkList* L){
    *L=malloc(sizeof(Node));
    (*L)->next=NULL;
}

void CreatFromHead(Node* L){
    Node* s=NULL;
    E c;
    int flag=1;
    while(flag){
        scanf(E_FORMAT,&c);
        if(c!=999){  //这里的判断必须要符合E类型，根据E的具体类型进行变换
        s=malloc(sizeof(Node));
        if(s==NULL){
            printf("内存分配失败");
            break;
        }
        s->data=c;
        s->next=L->next;
        L->next=s;   
     }
     else {flag=0;}
    }
}

void CreatFromTail(LinkList L){
    Node* s;
    Node* r=L;
    E c;
    int flag=1;
    while(flag){
        scanf(E_FORMAT,&c);
        if(c!=999){
        s=malloc(sizeof(Node));
        if(s==NULL){
            printf("分配失败\n");
            break;
        }
        s->data=c;
        s->next=NULL;
        r->next=s;
        r=s;
    }
    else flag=0;
    }

}

Node* GetData(LinkList L,int index){//查找第i个元素
    if(index<=0){
        printf("index非法");
        return NULL;
    }
    Node* find=L->next;
    for(int i=1;i<index;i++){
        if(find==NULL){
            printf("未找到");
            return NULL;
        }
        find=find->next;
    }
    if(find==NULL){
        printf("未找到");
        return NULL;
    }
    return find;

}

Node* Locate(LinkList L,E element){//找data等于key的节点
    Node* find=L->next;
    while(find!=NULL){
        if(find->data==element){
            return find;
        }
        find=find->next;
    }
    printf("未找到");
    return NULL;
}



int ListLength(LinkList L){
    Node*find=L;
    int i=0;
   for (i = 0; find->next != NULL; i++) {
        find = find->next;
    }
    return i;
}


_Bool InsList(LinkList* L,int index,E e){
    Node* find=*L;
    if(index<=0){
        printf("index不合法");
        return 0;}



        while(--index){                              
        if(find->next==NULL) break;      
            find=find->next;
        }

        //while(--index){
        //if(find->next==NULL){
        //printf("index大了");
        //return 0;
        //}
        //find=find->next;
        //}


        Node* s=malloc(sizeof(Node));
        if(s==NULL){
            printf("分配失败");
            return 0;
        }
        s->data=e;
        s->next=find->next;
        find->next=s;
        return 1;
    }


_Bool DelList(LinkList L,int index,E* e){//e储存被删除元素的地址
    
    
    if(index<=0){
        printf("index不合法");
        return 0;
    } 


    Node* find=L;


    while(--index){
        if(find->next==NULL){
            printf("index大了");
            return 0;
        }
        find=find->next;
    }


    if(find->next==NULL){
        printf("index大了");
        return 0;
    }


    *e=find->next->data;

    Node* delList=find->next;
    find->next=find->next->next;
    delList->next=NULL;
    free(delList);

    
    return 1;

}