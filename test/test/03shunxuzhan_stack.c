//
//  03shunxuzhan_stack.c
//  
//
//  Created by 郑影 on 16/1/6.
//
//  这种顺序链表，顺序栈有点扯

#include <stdio.h>
#include "stdlib.h"
#define MAXSIZE 20

typedef struct{
    int data[MAXSIZE];   // 分配20个空间
    int top;        // 顶指针
}SqStack;

void initStack(SqStack *stack){
    // 空栈：顶指针没有下标，为-1
    stack->top = -1;
}

// 入栈：错误返回0，正确返回1
int push(SqStack *stack, int val){
    // 如果满了返回错误
    if(stack->top == MAXSIZE-1){
        return 0;
    }
    stack->top++;
    stack->data[stack->top] = val;
    return 1;
}

void stackTraverse(SqStack stack){
    int i = 0;
    while(i <= stack.top){
        printf("%d ", stack.data[i++]);
    }
    printf("\n");
}

int pop(SqStack *stack, int *val){
    if(stack->top == -1){
        return 0;
    }
    *val = stack->data[stack->top];
    stack->top--;
    return 1;
}

int isEmptyStack(SqStack stack){
    if(stack.top == -1){
        return 1;
    }
    return 0;
}

void clearStack(SqStack *stack){
    stack->top = -1;
}

int main(){
    SqStack s;
    // 初始化栈
    initStack(&s);
    // 入栈
    for (int i=0; i<10; i++) {
        push(&s, i);
    }
    // 遍历栈
    stackTraverse(s);
    // 弹出栈
    int ele;
    pop(&s, &ele);
    printf("弹出的是%d\n", ele);
    printf("现在的栈：");
    stackTraverse(s);
    
    clearStack(&s);
}

