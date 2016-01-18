//
//  queue.c
//  Test
//
//  Created by 郑影 on 15/9/5.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

// 队列2015-09-05 16:59:32
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Queue{
    int* pBase;
    int front;
    int rear;
}QUEUE;

void init(QUEUE*);
bool add(QUEUE*, int);
void traverse(QUEUE*);
bool isFull(QUEUE*);
bool out(QUEUE*, int*);
bool isEmpty(QUEUE*);

int main(){
    QUEUE Q;
    init(&Q);
    add(&Q, 1);
    add(&Q, 2);
    add(&Q, 3);
    add(&Q, 4);
    add(&Q, 5);
    add(&Q, 6);
    add(&Q, 7);
    traverse(&Q);
    int val;
    for (int i = 0; i < 7; i++) {
        if (out(&Q, &val)) {
            printf("%d出队成功\n", val);
        }else{
            printf("出队失败\n");
        }
    }
    return 0;
}

void init(QUEUE* pQ){
    pQ->pBase = (int*)malloc(sizeof(int) * 6);
    pQ->front = 0;
    pQ->rear = 0;
}

bool isFull(QUEUE* pQ){
    if ((pQ->rear+1) % 6 == pQ->front) {
        return true;
    }
    return false;
}

bool add(QUEUE* pQ, int val){
    if (isFull(pQ)) {
        return false;
    }
    pQ->pBase[pQ->rear] = val;
    pQ->rear = (pQ->rear + 1) % 6;
    
    return true;
}

void traverse(QUEUE* pQ){
    int i = pQ->front;
    while (i != pQ->rear) {
        printf("%d ", pQ->pBase[i]);
        i = (i+1) % 6;
    }
    printf("\n");
}

bool isEmpty(QUEUE* pQ){
    if (pQ->front == pQ->rear) {
        return true;
    }
    return false;
}

bool out(QUEUE* pQ, int* pVal){
    if (isEmpty(pQ)) {
        return false;
    }
    *pVal = pQ->pBase[pQ->front];
    pQ->front = (pQ->front + 1) % 6;
    return true;
}


