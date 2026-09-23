#include<stdio.h>

typedef char E;
typedef struct TreeNode{
    E data;
    TreeNode* lchild;
    TreeNode* rchild;
}TreeNode;

char str[]="ABDH#K###E##CRI###G#J##";
int index=0;

//造树（前序），参考图片
void creatTree(TreeNode** T){
    E ch;                        //int ch;
    ch=str[index++];            //scanf("%d",&ch);


    if(ch='#'){
        *T=NULL;
    }
    else{
        *T=(TreeNode*)malloc(sizeof(TreeNode));
        (*T)->data=ch;
        creatTree(&(*T)->lchild);
        creatTree(&(*T)->rchild);
    }


}


//前序遍历(根-》左-》右)                                               
void preorder(TreeNode* T){                                    
    if(T==NULL){                                              
        return;                                                     
    }                                                           
    printf("%d",T->data);
    preorder(T->lchild);
    preorder(T->rchild);
}

//非递归前序遍历

/*void preOrderNonRec(TreeNode* T) {
    if (T == NULL) return;

    TreeNode* stack[100];
    int top = -1;
    TreeNode* p = T;

    while (top != -1 || p != NULL) {
        // 一路向左：访问 + 入栈
        while (p != NULL) {
            printf("%c ", p->data);
            stack[++top] = p;
            p = p->lchild;
        }
        // 左边空了，出栈，去右边
        p = stack[top--];
        p = p->rchild;
    }
}*/


//中序遍历（左->根->右）(H K D B E A I F C G J)
void inorder(TreeNode* T){
    if(T==NULL){
        return;
    }
    inorder(T->lchild);
    printf("%c",T->data);
    inorder(T->rchild);
}

//后序遍历（左->右->根)(K H D E B I F J G C A)