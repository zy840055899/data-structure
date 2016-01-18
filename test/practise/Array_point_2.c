//
//  Array_point_2.c
//  Test
//
//  Created by 郑影 on 15/7/5.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>


void f(int * p, int len){
    int i;
    for(i = 0; i < len; i++){
        printf("%d\n", p[i]);
    }
}

int main(){
    
    int a[] = {1,2,3,4,5};
    
    f(a, 5);
    
    
    return 0;
}