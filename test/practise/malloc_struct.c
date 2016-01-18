//
//  malloc_struct.c
//  Test
//
//  Created by 郑影 on 15/7/26.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>

struct Student{
    int sid;
    int age;
};

struct Student * createStudent(void);
void show(struct Student * ps);

int main(void){
    struct Student * ps;
    ps = createStudent();
    
    return 0;
}

struct Student * createStudent(void){
    struct Student * p = (struct Student *)malloc(sizeof(struct Student));
    p->sid = 99;
    p->age = 20;
    return p;
}

void show(struct Student * ps){
    printf("%d %d", ps->age, ps->sid);
}






