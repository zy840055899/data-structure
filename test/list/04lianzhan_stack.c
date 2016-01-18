//
//  04lianzhan_stack.c
//  
//
//  Created by 郑影 on 16/1/10.
//
//  简单的一些函数没有写

#include <stdio.h>
#include <stdlib.h>

//栈中的每个节点的定义
typedef struct StackNode{
    int data;
    struct StackNode *pNext;
}StackNode, *PStackNode;

//栈的定义
typedef struct{
    StackNode *top;     //栈顶节点指针
    int count;          //存放栈的长度（元素个数）
}LinkStack;

//初始化栈
void initStack(LinkStack *stack){
    stack->top = (PStackNode)malloc(sizeof(StackNode));
    if (stack->top == NULL) {
        exit(-1);
    }
    stack->top = NULL;
    stack->count = 0;
}

//入栈
void push(LinkStack *stack, int ele){
    PStackNode new = (PStackNode)malloc(sizeof(StackNode));
    new->data = ele;
    new->pNext = stack->top;
    stack->top = new;
    stack->count++;
}

// 遍历栈
void stackTraverse(LinkStack *stack){
    PStackNode tmp = stack->top;
    while (tmp!= NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->pNext;
    }
    printf("\n");
}

//弹出栈
void pop(LinkStack *stack, int *ele){
    if (stack->count == 0) {
        exit(-1);
    }
    PStackNode tmp = stack->top;
    *ele = tmp->data;
    stack->top = tmp->pNext;
    stack->count--;
    free(tmp);
}

//清空栈
void emptyStack(LinkStack *stack){
    PStackNode index = stack->top;
    PStackNode tmp;
    while (index!= NULL) {
        tmp = index;
        index = index->pNext;
        free(tmp);
    }
    stack->count = 0;
}

int main(){
    
    LinkStack s;
    initStack(&s);
    //入栈
    for (int i=0; i<10; i++) {
        push(&s, i);
    }
    
    // 遍历栈
    printf("栈遍历：");
    stackTraverse(&s);
    
    //弹栈，并保存元素
    int a;
    pop(&s, &a);
    printf("弹出的元素是：%d\n遍历结果：", a);
    stackTraverse(&s);
    
    //清空栈
    emptyStack(&s);
    printf("清空栈之后，栈的长度：%d\n", s.count);
}

