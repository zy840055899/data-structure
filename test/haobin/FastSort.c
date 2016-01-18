//
//  FastSort.c
//  
//
//  Created by 郑影 on 15/10/21.
//
//
// 快速排序
#include <stdio.h>
void QuickSort( int *a, int low, int high );
int FindPos( int *a, int low, int high );

int main( void )
{
    int a[6] = { 2, 1, 0, 5, 4, 3 };
    int i;
    
    QuickSort( a, 0, 5 );	//第二个参数表示第一个元素的下标,第三个参数表示最后一个元素的下标
    
    for( i = 0; i < 6; ++ i )
        printf( "%d ", a[i] );
    printf( "\n" );
    
    return 0;
}

void QuickSort( int *a, int low, int high )
{
    int pos;
    
    if( low < high )
    {
        pos = FindPos( a, low, high );
        QuickSort( a, low, pos - 1 );
        QuickSort( a, pos + 1, high );
    }
}

int FindPos( int *a, int low, int high )
{
    int val = a[low];
    
    while( low < high )
    {
        while( low < high && a[high] > val )
            -- high;
        a[low] = a[high];
        
        while( low < high && a[low] <= val )
            ++ low;
        a[high] = a[low];
    }//终止while循环之后low和high一定相等的
    
    a[low] = val;
    
    return low;//或者return high;
}




