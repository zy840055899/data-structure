//
//  recurison.c
//  Test
//
//  Created by 郑影 on 15/9/9.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>

int f(int n){
    if (n == 1) {
        return 1;
    }
    return n * f(n - 1);
}

int k(int n){
    if (n==1) {
        return 1;
    }
    return n + k(n -1);
}


int main(void){
    printf("%d\n", f(100));
    printf("%d\n", k(100));
    return 0;
}





