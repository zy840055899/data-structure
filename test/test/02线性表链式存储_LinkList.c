//
//  02线性表链式存储_LinkList.c
//  
//
//  Created by 郑影 on 15/12/6.
//
//

// 线性表：链式存储。

#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"

typedef struct Node{
    int data;               // 表示的是每个节点的数据域
    struct Node *next;      // 每个节点的指针域
}Node, *PNode;           // Node表示链表的每个节点，*LinkList表示指针节点

//初始化链表(这里面为什么要传指针★：只有传指针才能真正有效的处理入参，否则压根没处理★)
void initList(PNode *pHead){
    // 产生头结点，使*pNode指向头结点
    *pHead = (PNode)malloc(sizeof(Node));
    if(*pHead == NULL){
        exit(-1);
    }
    (*pHead)->next = NULL;
}

// 获取链表的长度
int listLength(PNode pHead){
    int i = 0;
    PNode p = pHead->next;
    while (p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

// 定位插入元素，关键就是如何定位到那个位置，代码很精妙
int listInsert(PNode pHead, int index, int value){
    PNode pIndex, new;  // 要插入的那个位置的结点和新生成的节点
    pIndex = pHead;
    int j = 0;
    while (pIndex != NULL && j < index) {
        pIndex = pIndex->next;
        j++;
    }
    if (pIndex == NULL || j > index) {
        return 0;
    }
    new = (PNode)malloc(sizeof(PNode));
    new->data = value;
    new->next = pIndex->next;
    pIndex->next = new;
    return 1;
}

// 遍历链表(直接输出，不返回值)
void traverseList(PNode pHead){
    PNode pNode = pHead->next;
    while (pNode != NULL) {
        printf("%d ", pNode->data);
        pNode = pNode->next;
    }
}

//清空链表
void emptyList(PNode *pHead){
    PNode pIndex = (*pHead)->next;
    PNode temp;
    while (pIndex != NULL) {
        temp = pIndex->next;
        free(pIndex);
        pIndex = temp;
    }
    (*pHead)->next = NULL;
}

// 获取下标为index的元素的值(关键依然是定位到该下标的那个元素)
int getElement(PNode pHead, int index, int *e){
    PNode pIndex = pHead->next;
    int j = 0;
    while (pIndex != NULL && j < index) {
        pIndex = pIndex->next;
        j++;
    }
    if (pIndex == NULL || j > index) {
        return 0;
    }
    *e = pIndex->data;
    return 1;
}

int getLocate(PNode pHead, int ele){
    PNode pNow = pHead->next;
    int index = 0;
    while (pNow != NULL) {
        if (pNow->data == ele) {
            return index;
        }
        index++;
        pNow = pNow->next;
    }
    return -1;
}

// 根据下标删除元素，删除失败返回0
int eleDelByIndex(PNode pHead, int index, int *ele){
    PNode pIndex = pHead->next;
    PNode temp;
    int j = 1;
    while (pIndex != NULL && j < index) {
        pIndex = pIndex->next;
        j++;
    }
    if (pIndex == NULL || j > index) {
        return 0;
    }
    temp = pIndex->next;
    pIndex->next = temp->next;
    *ele = temp->data;
    free(temp);
    return 1;
}

// 头插法创建链表
void createListHead(PNode *pHead, int n){
    PNode temp;
    *pHead = (PNode)malloc(sizeof(Node));
    (*pHead)->next = NULL;
    for (int i=0; i<n; i++) {
        temp = (PNode)malloc(sizeof(Node));
        temp->data = rand()%100 + 1;
        temp->next = (*pHead)->next;
        (*pHead)->next = temp;
    }
}

// 尾插法创建链表
void createListTail(PNode *pHead, int n){
    PNode tail, temp;
    *pHead = (PNode)malloc(sizeof(Node));
    tail = *pHead;
    for (int i=0; i<n; i++) {
        temp = (PNode)malloc(sizeof(Node));
        temp->data = rand()%100 + 1;
        tail->next = temp;
        tail = temp;
    }
    tail->next = NULL;
}


int main(){
    printf("hello\n");
    PNode pHead;
    // 初始化链表
    initList(&pHead);
    printf("初始化后链表的长度：%d\n", listLength(pHead));
    // 链表指定位置插入数据
    for (int i = 0; i < 5; i++) {
        //一直在表头插入数据
        printf("%d ", listInsert(pHead, 0, i));
    }
    printf("\n插入数据后链表的长度：%d\n", listLength(pHead));
    // 遍历链表
    traverseList(pHead);
    // 清空链表
    emptyList(&pHead);
    printf("\n清空后list的长度%d:\n", listLength(pHead));
    //在表尾连续插入数据
    for (int i=0; i<10; i++) {
        listInsert(pHead, i, i);
    }
    traverseList(pHead);
    
    //获取指定位置的元素
    int ele;
    int index = 90;
    int result = getElement(pHead, index, &ele);
    printf("\n结果:%d,index=%d的值为%d\n", result, index, ele);
    
    // 查找某元素在链表中的下标返回，找不到返回-1
    int ele2 = 10;
    int index2 = getLocate(pHead, ele2);
    printf("元素%d的下标为%d\n", ele2, index2);
    
    // 按照下标删除元素，删除错误返回0
    int ele3;
    int index3 = 1;
    eleDelByIndex(pHead, index3, &ele3);
    printf("删除下标为%d的元素，为:%d\n", index3, ele3);
    traverseList(pHead);
    
    emptyList(&pHead);
    
    // 头插法创建链表
    createListHead(&pHead, 8);
    printf("\n头插法链表遍历：");
    traverseList(pHead);
    
    emptyList(&pHead);
    // 尾插法创建链表
    createListTail(&pHead, 9);
    printf("\n尾插法链表遍历：");
    traverseList(pHead);
}
