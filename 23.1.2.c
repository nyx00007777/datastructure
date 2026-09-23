

#include <stdio.h>
#include <stdlib.h>


// 二叉树节点结构体
typedef struct btree_node {
    int data;
    struct btree_node* left;
    struct btree_node* right;
} btree_node, *btree;

// 栈结构体
typedef struct stack_node {
    btree* data;
    struct stack_node* next;
} stack;

// 栈操作函数声明
void push(stack** S, btree x);
btree* pop(stack** S);
bool empty(stack* S);
void print_node(btree x);



void find_leaves(btree root){
    stack* S;
    
}




