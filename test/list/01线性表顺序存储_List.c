//
//  01线性表顺序存储_List.c
//  
//
//  Created by 郑影 on 15/11/2.
//
//

#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int data[20];       /*数组，存储数据元素*/
    int length;         /*线性表当前长度*/
}SqList;

/*初始化线性表*/
void initList(SqList *L){
    L->length = 0;
}

/*线性表插入数据  xx, 位置，元素*/
bool listInsert(SqList *L, int i, int e){
    int k;
    //线性表已满返回错误
    if (L->length == 20) {
        return false;
    }
    // 插入位置错误，返回错误
    if (i<1 || i>L->length+1) {
        return false;
    }
    if (i <= L->length) {
        for (k=L->length-1; k>=i-1; k--) {
            L->data[k+1] = L->data[k];
        }
    }
    L->data[i-1] = e;
    L->length++;
    
    return true;
}

void listTraverse(SqList *L){
    int i;
    for (i=0; i<L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

bool listIsEmpty(SqList *L){
    if (L->length == 0) {
        return true;
    }
    return false;
}

void clearList(SqList *L){
    L->length = 0;
}

bool getElem(SqList *L, int index, int *e){
    if (L->length==0 || index<1 || index>L->length) {
//        printf("不存在\n");
        return false;
    }
    *e = L->data[index-1];
    return true;
}

/*获取元素的位置*/
int locateElem(SqList *L, int ele){
    
    for (int i=0; i<L->length; i++) {
        if (ele == L->data[i]) {
            return i;
        }
    }
    return -1;
}

/*根据位置删除元素*/
int eleDelete(SqList *L, int index){
    if (index >= L->length || index < 0) {
        printf("不存在该位置\n");
        return -1;
    }
    int e = L->data[index];
    for (int i=index; i<L->length; i++) {
        L->data[i] = L->data[i+1];
    }
    L->length--;
    return e;
}

void unionL(SqList *L, SqList *Lb){
    int la_length = L->length;
    int lb_length = Lb->length;
    int e;
    
    for (int i=1; i<lb_length+1; i++) {
        getElem(Lb, i, &e);
//        printf("元素%d为%d\n",i,e);
        if(locateElem(L, e) == -1){
            listInsert(L, ++la_length, e);
        }
    }
}

int main(){
    SqList L;
    // 初始化链表
    initList(&L);
    printf("初始化L后，L.length=%d\n", L.length);        // 0
    // 循环插入元素（一直在表头插入）
    for (int j=1; j<=5; j++) {
        listInsert(&L, 1, j);
    }
    // 遍历链表
    listTraverse(&L);
    
    // 判断是否为空
    if (listIsEmpty(&L)) {
        printf("链表为空\n");
    }else{
        printf("链表不为空\n");
    }
    
    // 清空链表
    clearList(&L);
    
    // 判断是否为空
    if (listIsEmpty(&L)) {
        printf("链表为空\n");
    }else{
        printf("链表不为空\n");
    }
    // 插入元素（一直在表末插入）
    for(int j=1;j<=10;j++){
        listInsert(&L,j,j);
    }

    // 获取第n个元素的值
    int index = 11;
    int e;
    bool flag = getElem(&L, index, &e);
    if (flag) {
        printf("第%d个元素是：%d\n", index, e);
    }else{
        printf("第%d个元素不存在\n",index);
    }
    // 获取元素的位置,返回-1表示不存在
    printf("遍历链表：");
    listTraverse(&L);
    for (int j=10; j<=11; j++) {
        int index = locateElem(&L, j);
        if (index > 0) {
            printf("元素%d的位置是%d\n", j, index);
        }else{
            printf("元素%d不存在\n", j);
        }
    }
    
    // 根据位置删除元素
    e = eleDelete(&L, 9);
    printf("删除的元素是：%d\n",e);
    printf("L:");
    listTraverse(&L);
    
    SqList Lb;
    initList(&Lb);
    //构造一个顺序链表LB，用来和L合并
    for (int j=6; j<15; j++) {
        listInsert(&Lb, 1, j);
    }
    printf("LB:");
    listTraverse(&Lb);
    
    //合并L和Lb到L
    unionL(&L, &Lb);
    listTraverse(&L);

    return 0;
}

