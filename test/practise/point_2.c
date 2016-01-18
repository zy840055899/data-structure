//
//  point_2.c
//  Test
//
//  Created by 郑影 on 15/7/2.
//  Copyright (c) 2015年 郑影. All rights reserved.
//


/*
     使用指针真正的改变参数
 
 */

#include <stdio.h>

void f(int *i){
    
    *i = 100;
    
}

int main(){
    
    int i = 10;
    
    f(&i);
    
    printf("i = %d\n", i);
}