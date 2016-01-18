//
//  Array_point_1.c
//  Test
//
//  Created by 郑影 on 15/7/5.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>

int main(){
    
    
    int a[5] = {1,2,3,4,5};
    
    
    
    
    printf("a[0]=%d, %d\n", a[0], *(a+1));
    
    printf("%p\n", (a+1));
    printf("%p\n", (a+2));
    printf("%p\n", (a+3));
    printf("%p\n", *a + 3);
    
    /*
     a[0]=1, 2
     0x7fff5fbff7f4
     0x7fff5fbff7f8
     0x7fff5fbff7fc
     0x4
     */
    
    
    
    return 0;
}
