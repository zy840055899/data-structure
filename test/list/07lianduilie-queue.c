//
//  07lianduilie-queue.c
//  
//
//  Created by 郑影 on 16/1/18.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//结点结构
typedef struct Node{
    int data;
    struct Node *pNext;
}Node, *PNode;

typedef struct{
    PNode front;
    PNode rear;
}LinkQueue;

//初始化链队列
void initQueue(LinkQueue *queue){
    PNode new = (PNode)malloc(sizeof(Node));
    if (new == NULL) {
        exit(-1);
    }
    queue->front = queue->rear = new;
    queue->front->pNext = NULL;
}

//获取链队列的长度
int getQueueLength(LinkQueue queue){
    PNode tmp = queue.front;
    int length = 0;
    while (queue.rear != tmp) {
        tmp = tmp->pNext;
        length++;
    }
    return length;
}

bool isEmpty(LinkQueue queue){
    if(queue.front == queue.rear){
        return true;
    }
    return false;
}

void enQueue(LinkQueue *queue, int val){
    PNode new = (PNode)malloc(sizeof(Node));
    if (new == NULL) {
        exit(-1);
    }
    new->data = val;
    new->pNext = NULL;
    queue->rear->pNext = new;
    queue->rear = new;
}

int main(){
    
    printf("asdas\n");
    
    LinkQueue queue;
    initQueue(&queue);
    
    if(isEmpty(queue)){
        printf("是空链队列\n");
    }
    printf("队列的长度为:%d\n", getQueueLength(queue));

    //进链队列
    enQueue(&queue, 99);
    printf("队列的长度为:%d\n", getQueueLength(queue));

}


