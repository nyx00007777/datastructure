#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int number;
    struct Node *next;
}Node;

Node* creatNode(int number){
    Node* new=malloc(sizeof(Node));
    new->number=number;
    new->next=NULL;
    return new;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d",&n,&m);
        int total=n+2;
        Node* head=creatNode(1);
        Node* find=head;
       
       
        for(int i=2;i<=total;i++){
            find->next=creatNode(i);
            find=find->next;
        }
        find->next=head;

        Node* prev=find;
        find=head;
        int remian=total;
        while(remian>2){
            for(int count=1;count<m;count++){
                prev=find;
                find=find->next;
            }

            prev->next=find->next;
            find=prev->next;
            remian--;
        }

        int a=find->number;
        int b=find->next->number;
        if(a>b){
            printf("%d %d\n",b,a);
        }
        else{
            printf("%d %d\n",a,b);
        }


    }
    return 0;
}