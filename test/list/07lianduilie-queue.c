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

//书上写的遍历
void queueTraverse(LinkQueue queue){
    PNode tmp = queue.front->pNext;
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        tmp = tmp->pNext;
    }
    printf("\n");
}

//我写的遍历方法（错误:链表的头结点数据域是空，只能显示0，少遍历一次）
void queueTraverse2(LinkQueue queue){
    PNode tmp = queue.front;
    while (tmp != queue.rear) {
        printf("%d ", tmp->data);
        tmp = tmp->pNext;
    }
    printf("\n");
}

void clearQueue(LinkQueue *queue){
    PNode tmp = queue->front->pNext;
    PNode toClear;      //待释放空间
    while (tmp != NULL) {
        toClear = tmp;
        tmp = tmp->pNext;
        free(toClear);
    }
    //这一步不可少，空队列的必备条件
    queue->rear = queue->front;
    printf("\n");
}

void destroyQueue(LinkQueue *queue){
    while (queue->front != NULL) {
        queue->rear = queue->front->pNext;
        free(queue->front);
        queue->front = queue->rear;
    }
}

int main(){
    LinkQueue queue;
    initQueue(&queue);
    
    if(isEmpty(queue)){
        printf("是空链队列\n");
    }
    printf("队列的长度为:%d\n", getQueueLength(queue));

    //进链队列
    enQueue(&queue, 99);
    enQueue(&queue, -1);
    enQueue(&queue, 3);
    printf("入队三个元素，队列的长度为:%d\n", getQueueLength(queue));

    //遍历队列
    printf("正确的遍历：");
    queueTraverse(queue);
    printf("错误的遍历：");
    queueTraverse2(queue);          //error
    
    //清空队列
    clearQueue(&queue);
    printf("队列的长度为:%d\n", getQueueLength(queue));

    enQueue(&queue, 999);           //本行不报错，队列存在长度为空
    printf("队列的长度为:%d\n", getQueueLength(queue));
    //输出123123 12312312（地址）
    printf("front:%u rear:%u front->pNext:%u \n", queue.front, queue.rear, queue.front->pNext);

    destroyQueue(&queue);
    printf("front:%u rear:%u \n", queue.front, queue.rear);     // 0 0
//    enQueue(&queue, 990);           //本行报错，队列已不存在，入队失败
}

