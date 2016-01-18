//
//  Node.c
//  Test
//
//  Created by 郑影 on 15/8/9.
//  Copyright (c) 2015年 郑影. All rights reserved.
//  链表的创建与遍历2015-08-15 15:43:51

#include "stdio.h"
#include <stdlib.h>

typedef struct Node{
    int data;               // 数据域
    struct Node * pNext;    // 指针域
}NODE,*PNODE;               // NODE等价于struct code,*PNODE等价于struct Node *

// 函数声明
PNODE create_list(void);            // 创建链表
void traverse_list(PNODE pHead);    // 遍历链表
bool isEmpty(PNODE);                // 判断链表是否为空
int length_list(PNODE);             // 求链表的长度
void sort_list(PNODE);              // 排序
bool insert_list(PNODE, int, int);  // 插入结点int：位置 int：插入的值
bool delete_list(PNODE, int, int* pVal);    // 删除指定位置的元素
// 练习
void empty();



int main(void){
    PNODE pHead = NULL;
    pHead = create_list();
    printf("链表内容：");
    traverse_list(pHead);
    if(isEmpty(pHead)){
        printf("链表为空\n");
    }else{
        printf("链表不为空\n");
    }
    printf("链表的长度为：%d\n", length_list(pHead));
    sort_list(pHead);
    printf("排序结果：");
    traverse_list(pHead);
    if(insert_list(pHead, 3, 9999)){
        printf("插入成功：");
        traverse_list(pHead);
    }else{
        printf("插入失败");
    }
    int val;
    if(delete_list(pHead, 1, &val)){
        printf("删除的元素是：%d\n", val);
        printf("链表内容：");
        traverse_list(pHead);
    }else{
        printf("删除失败，元素不存在");
    }
    return 0;
}

PNODE create_list(void){
    int len;
    int i;
    int val;        // 用来存放用户临时输入的值
    
    // 分配了一个不存放有效数据的头结点（不能说是头指针）
    PNODE pHead = (PNODE)malloc(sizeof(NODE));
    if(NULL == pHead){
        printf("内存分配失败，程序终止。。");
        exit(-1);       // 程序终止
    }
    // ptail就相当于一个temp一样永远指向当前链表的最后一个尾结点
    PNODE pTail = pHead;
    pTail->pNext = NULL;
    
    printf("请输入生成链表的个数:len = ");
    scanf("%d", &len);
    for(i = 0; i < len; i++){
        printf("请输入第%d个值：", i+1);
        scanf("%d", &val);
        
        PNODE pNew = (PNODE)malloc(sizeof(NODE));
        if(NULL == pNew){
            printf("内存分配失败，程序终止。。");
            exit(-1);       // 程序终止
        }
        pNew->data = val;
        pTail->pNext = pNew;
        pNew->pNext = NULL;
        pTail = pNew;
    }
    return pHead;
}

// 遍历链表
void traverse_list(PNODE pHead){
    PNODE p  = pHead->pNext;
    while (NULL != p) {
        printf("%d ", p->data);
        p = p->pNext;
    }
    printf("\n");
}

bool isEmpty(PNODE pHead){
    if(NULL == pHead->pNext)
        return true;
    return false;
}

int length_list(PNODE pHead){
    int len = 0;
    PNODE p = pHead->pNext;
    while (NULL != p) {
        len++;
        p = p->pNext;
    }
    return len;
}

void sort_list(PNODE pHead){
    int i, j, t;
    PNODE p, q;
    int len = length_list(pHead);
    for (i=0, p=pHead->pNext; i<len-1; i++, p=p->pNext) {
        for (j=i+1, q=p->pNext; j<len; j++, q=q->pNext) {
            if (p->data > q->data) {
                t = p->data;
                p->data = q->data;
                q->data = t;
            }
        }
    }
}

bool insert_list(PNODE pHead, int pos, int val){
    int i = 0;
    PNODE p = pHead;
    while (NULL!=p && i<pos) {
        p = p->pNext;
        i++;
    }
    
    if(i>pos || NULL==p)
        return false;
    
    PNODE pNew = (PNODE)malloc(sizeof(NODE));
    if (NULL == pNew) {
        printf("动态内存分配失败");
        exit(-1);
    }
    
    pNew->data = val;
    PNODE q = p->pNext;
    p->pNext = pNew;
    pNew->pNext = q;
    return true;
}

bool delete_list(PNODE pHead, int pos, int* pVal){
    // -------主要就是这段代码经典----
    // 作用：直接定位到要操作结点的位置
    int i = 0;
    PNODE p = pHead;
    while (NULL!=p->pNext && i<pos) {
        p = p->pNext;
        i++;
    }
    if(i>pos || NULL==p->pNext)
        return false;
    // ----------------------------
    
    PNODE q = p->pNext;
    *pVal = q->data;
    
    // 删除p结点后面的结点
    p->pNext = q->pNext;
    free(q);
    q = NULL;
    return true;
}

