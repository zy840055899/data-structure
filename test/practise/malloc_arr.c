//
//  malloc_arr.c
//  Test
//
//  Created by 郑影 on 15/7/7.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>
int main(){
    
    
    int len;
    printf("请输入数组的长度len = ");
    scanf("%d", &len);
    
    printf("%d\n", len);
    
    
    int * pArr = (int *)malloc(sizeof(int) * len);
    
    for (int i = 0; i < len; i++) {
        scanf("%d", &pArr[i]);
    
    }
    
    for(int i = 0; i < len; i++){
        printf("%d\n", *(pArr+i));
    }
    
    return 0;
}