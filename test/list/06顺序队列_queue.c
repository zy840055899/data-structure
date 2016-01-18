//
//  06顺序队列_queue.c
//  
//
//  Created by 郑影 on 16/1/13.
//
//  顺序队列

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 20

//定义一个队列
typedef struct{
    int data[MAXSIZE];
    int front;          //头指针
    int rear;           //尾指针
}SqQueue;

void initQueue(SqQueue *queue){
    queue->front = 0;
    queue->rear = 0;
}

bool isEmpty(SqQueue queue){
    if (queue.rear == queue.front) {
        return true;
    }
    return false;
}

//很重要（队列是否已满，队列尾部下标的移动★）
bool enQueue(SqQueue *queue, int val){
    //先判断队列是否满
    if((queue->rear+1) % MAXSIZE == queue->front){
        printf("队列已满，%d插入失败\n", val);
        return false;
    }
    queue->data[queue->rear] = val;             //新增元素补在队列尾部
    queue->rear = (queue->rear + 1) % MAXSIZE;  //尾部下标加1（考虑循环队列）
    
    return true;
}

int getQueueLength(SqQueue queue){
    return (queue.rear - queue.front + MAXSIZE) % MAXSIZE;
}

//我自己写的queue遍历(笨方法，大话数据结构上得写法不对，高级方法在下面)
void traverseQueue(SqQueue queue){
    
    printf("front:%d, rear:%d size:%d\n", queue.front, queue.rear, getQueueLength(queue));
    
    //队列已经追尾的情况
    if (queue.rear < queue.front) {
        for (int i=queue.front; i<MAXSIZE; i++) {
            printf("%d ", queue.data[i]);
        }
        
        for (int i=0; i<queue.rear; i++) {
            printf("%d ", queue.data[i]);
        }
    }
    
    //队列没有追尾的情况
    if (queue.rear > queue.front) {
        for (int i=queue.front; i<queue.rear; i++) {
            printf("%d ", queue.data[i]);
        }
    }
    printf("\n");
}

//第二种遍历（高级方法）
void traverseQueue2(SqQueue queue){
    int i = queue.front;
    while (i != queue.rear) {
        printf("%d ", queue.data[i]);
        i = (i+1) % MAXSIZE;
    }
    printf("\n");
}

//出队列
bool deQueue(SqQueue *queue, int *val){
    if (queue->front == queue->rear) {
        return false;
    }
    *val = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAXSIZE;
    return true;
}

void clearQueue(SqQueue *queue){
    queue->front = queue->rear = 0;
}

int main(){
    
    //初始化队列
    SqQueue queue;
    initQueue(&queue);
    
    //判断是否为空
    if(isEmpty(queue)){
        printf("空\n");
    }else{
        printf("不为空\n");
    }
    //入队
    for (int i=0; i<20; i++) {
        enQueue(&queue, i);
    }
    
    int length = getQueueLength(queue);
    printf("队列的长度为%d\n", length);
    
    //遍历队列
    traverseQueue(queue);
    //出队列（先进先出）
    int val;
    deQueue(&queue, &val);
    printf("%d出队\n", val);
    deQueue(&queue, &val);
    printf("%d出队\n", val);
    deQueue(&queue, &val);
    printf("%d出队\n", val);
    traverseQueue(queue);
    traverseQueue2(queue);
    
    //清空队列
    clearQueue(&queue);
    
    length = getQueueLength(queue);
    printf("length=%d\n", length);
}
