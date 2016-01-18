//
//  05Fibonacci_stack.c
//  
//
//  Created by 郑影 on 16/1/11.
//
//  斐波拉契数列：1，1，2，3，5，8，13，21。。。
//  递归是一种很浪费内存的东西

#include <stdio.h>

int fibonacciGetSum(int i){
    if(i == 1 || i == 2){
        return 1;
    }
    if (i == 3) {
        return 2;
    }
    return fibonacciGetSum(i-1)+fibonacciGetSum(i-2);
}

int main(){
    printf("%d\n", fibonacciGetSum(8));
}



