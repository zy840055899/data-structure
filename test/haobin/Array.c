//
//  Array.c
//  Test
//
//  Created by 郑影 on 15/8/17.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Arr{
    int *pBase;     // 存储的是数组第一个元素的地址
    int len;        // 数组所能容纳的最大元素
    int cnt;        // 当前数组有效元素的个数
    int increment;  // 自动增长因子
};

void init_arr(struct Arr*, int);
void show_arr(struct Arr*);
bool is_empty(struct Arr*);
bool is_full(struct Arr*);
bool append_arr(struct Arr*, int);
bool insert_arr(struct Arr*, int, int);             // 插入元素
bool delete_arr(struct Arr*, int, int*);
void inverse_arr(struct Arr*);
void sort_arr(struct Arr*);

int main(void){
    struct Arr arr;
    init_arr(&arr, 6);
    show_arr(&arr);
    printf("\n");
    append_arr(&arr, 1);
    append_arr(&arr, 2);
    append_arr(&arr, 3);
    append_arr(&arr, 4);
    append_arr(&arr, 5);
    insert_arr(&arr, 0, 99);
    show_arr(&arr);
    printf("\n数组的长度:%d\n", arr.len);
    show_arr(&arr);
    int i;
    delete_arr(&arr, 6, &i);
    printf("\n删除元素%d后：", i);
    show_arr(&arr);
    inverse_arr(&arr);
    printf("\n数组反转后：");
    show_arr(&arr);
    sort_arr(&arr);
    printf("\n数组排序后：");
    show_arr(&arr);
    return 0;
}

void init_arr(struct Arr *pArr, int length){
    pArr->pBase = (int*) malloc(sizeof(int) * length);
    if(NULL == pArr->pBase){
        printf("动态内存分配失败");
        exit(-1);
    }else{
        pArr->len = length;
        pArr->cnt = 0;
    }
    return;
}

bool is_empty(struct Arr *pArr){
    if(0 == pArr->cnt){
        return true;
    }else{
        return false;
    }
}

bool is_full(struct Arr* pArr){
    if(pArr->cnt == pArr->len){
        return true;
    }else{
        return false;
    }
}

void show_arr(struct Arr* pArr){
    if(is_empty(pArr)){
        printf("数组为空");
    }else{
        for (int i= 0; i < pArr->cnt; i++) {
            printf("%d ", pArr->pBase[i]);
        }
    }
}

bool append_arr(struct Arr* pArr, int val){
    if(is_full(pArr)){
        printf("追加%d失败\n", val);
        return false;
    }
    // 不满的时候追加
    pArr->pBase[pArr->cnt] = val;
    (pArr->cnt)++;
    return true;
}

bool insert_arr(struct Arr* pArr, int pos, int val){
    int i;
    if(is_full(pArr)){
        return false;
    }
    if(pos<0 || pos>pArr->cnt){
        return false;
    }
    for (i=pArr->cnt-1; i>=pos; --i) {
        pArr->pBase[i+1] = pArr->pBase[i];
    }
    pArr->pBase[pos] = val;
    pArr->cnt++;
    return true;
}

bool delete_arr(struct Arr* pArr, int pos, int* pVal){
    int i;
    if (is_empty(pArr)) {
        return false;
    }
    if (pos<0 || pos>pArr->cnt-1) {
        return false;
    }
    *pVal = pArr->pBase[pos];
    for (i=pos+1; i<pArr->cnt; i++) {
        pArr->pBase[i-1] = pArr->pBase[i];
    }
    pArr->cnt--;
    return true;
}

void inverse_arr(struct Arr* pArr){
    int i = 0;
    int j = pArr->cnt-1;
    int t;
    
    while (i < j) {
        t = pArr->pBase[i];
        pArr->pBase[i] = pArr->pBase[j];
        pArr->pBase[j] = t;
        i++;
        j--;
    }
    return;
}

void sort_arr(struct Arr* pArr){
    int i, j, t;
    for (i=0; i<pArr->cnt; i++) {
        for (j=i+1; j<pArr->cnt; j++) {
            if (pArr->pBase[i] > pArr->pBase[j]) {
                t = pArr->pBase[i];
                pArr->pBase[i] = pArr->pBase[j];
                pArr->pBase[j] = t;
            }
        }
    }
}

