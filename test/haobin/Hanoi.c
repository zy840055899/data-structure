//
//  Hanoi.c
//  Test
//
//  Created by 郑影 on 15/9/13.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

// 汉诺塔、递归dd
#include <stdio.h>

int i = 0;
void hannuota( int n, char A, char B, char C )
{
    /*
     如果是1个盘子
     直接将A柱子上的盘子从A移动到C
     否则
     先将A柱子上的n-1个盘子借助于C移动到B
     直接将A柱子上的盘子从A移到C
     最后将B柱子上的n-1借助A移动到C
     */
    i++;
    
    if( 1 == n )
    {
        printf( "将编号为%d的盘子从%c柱子移动到%c柱子\n", n, A, C );
        printf("%d", i);
    }
    else
    {
        hannuota( n-1, A, C, B );
        printf( "将编号为%d的盘子从%c柱子移动到%c柱子\n", n, A, C );
        hannuota( n-1, B, A, C );
        
    }
}

int main( void )
{
    int n;
    
    printf( "请输入要移动的盘子个数:" );
    scanf( "%d", &n );
    
    hannuota( n, 'A', 'B', 'C' );
}
