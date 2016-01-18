//
//  struct.c
//  Test
//
//  Created by 郑影 on 15/7/5.
//  Copyright (c) 2015年 郑影. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct Student{
    int id;
    char name[200];
    int age;
};

void show(struct Student * pstu);

int main(){
    struct Student stu = {1001, "zhengying", 23};
    printf("%d %s %d\n", stu.id, stu.name, stu.age);
    stu.id = 1002;
    strcpy(stu.name, "lisi");
    stu.age = 23;
    printf("%d %s %d\n", stu.id, stu.name, stu.age);
    show(&stu);
    return 0;
}

void show(struct Student * pstu){
    printf("%d, %s, %d\n", pstu->age, pstu->name, pstu->age);
}




