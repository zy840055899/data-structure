//
//  Stack.c
//  Test
//
//  Created by 郑影 on 15/8/30.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int data;
    struct Node* pNext;
}NODE, * PNODE;

typedef struct Stack{
    PNODE pTop;
    PNODE pBottom;
}STACK, *PSTACK;


void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool isEmpty(PSTACK);
bool pop(PSTACK, int*);
void empty(PSTACK);

int main(){
    int val;
    STACK S;
    init(&S);
    push(&S, 999);
    push(&S, 2);
    push(&S, 5);
    push(&S, 1);
    traverse(&S);
    // 出栈
    while (!isEmpty(&S)) {
        if (pop(&S, &val)) {
            printf("%d出栈成功\n", val);
        }else{
            printf("出栈失败");
        }
    }
    empty(&S);
    return 0;
}

void init(PSTACK pS){
    pS->pTop = (PNODE)malloc(sizeof(NODE));
    if (NULL == pS->pTop) {
        printf("动态内存分配失败");
        exit(-1);
    }
    pS->pBottom = pS->pTop;
    
    // 清空指向的新栈的指针域
    pS->pTop->pNext = NULL;
}

void push(PSTACK pS, int val){
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    pNew->data = val;
    pNew->pNext = pS->pTop;
    pS->pTop = pNew;
}

void traverse(PSTACK pS){
    PNODE p = pS->pTop;
    
    while (p != pS->pBottom) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool isEmpty(PSTACK pS){
    if (pS->pTop == pS->pBottom) {
        return true;
    }
    return false;
}

bool pop(PSTACK pS, int* val){
    if (isEmpty(pS)) {
        return false;
    }
    PNODE r = pS->pTop;
    *val = r->data;
    pS->pTop = r->pNext;
    free(r);
    r = NULL;
    return true;
}

void empty(PSTACK pS){
    if (isEmpty(pS)) {
        return;
    }
    PNODE p = pS->pTop;
    PNODE q = NULL;
    while (p != pS->pBottom) {
        q = p->pNext;
        free(p);
        p = q;
    }
    pS->pTop = pS->pBottom;
}






