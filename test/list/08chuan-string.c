//
//  08chuan-string.c
//
//
//  Created by 郑影 on 16/1/21.
//
//

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#define MAXSIZE 40

typedef char String[MAXSIZE + 1];     //0号单元存放串的长度

//生成一个字符串(字符数组)
void strAssign(String str, char *chars) {

    if (strlen(chars) > MAXSIZE) {
        return;
    }
    str[0] = strlen(chars);
    for (int i = 0; i < str[0]; i++) {
        printf("%c ", *(chars + i));
        str[i + 1] = *(chars + i);
    }
}

int strLength(String str) {
    return str[0];
}

int main() {

    String s1;
    strAssign(s1, "abcd");


}


