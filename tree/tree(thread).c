#include<stdio.h>

typedef char E;
typedef struct ThreadNode{
    E data;
    ThreadNode* lchild;
    ThreadNode* rchild;

    int ltag,rtag;          
}ThreadNode;              
/*ltag=0	lchild指向左孩子
ltag=1	lchild指向前驱节点（线索）
rtag=0	rchild指向右孩子
rtag=1	rchild指向后继节点（线索）*/

