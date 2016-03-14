//
//  09erchashu_lian.c
//  test
//
//  Created by 郑影 on 16/3/2.
//  Copyright © 2016年 zhengying. All rights reserved.
//

//二叉树的链实现，顺序实现：利用数组，无结点该节点对应的数组元素为空。
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXSIZE 100

typedef char String[24];                    //0号单元存放串的长度

typedef struct BiTNode{
    char data;                              //数据域
    struct BiTNode *lchild, *rchild;        //左右子树
}BiTNode, *BiTree;

int local = 1;
String str;

void initBiTree(BiTree *T){
    *T = NULL;
}

void strAssgin(String str, char *chars){
    if(strlen(chars) > MAXSIZE){
        exit(-1);
    }
    str[0] = strlen(chars);
    for (int i=1; i<=str[0]; i++) {
        str[i] = *(chars+i-1);              //数组指针指向数组的第一个元素★
    }
}

void createTree(BiTree *T){
    char ch = str[local++];
    if ('#' == ch) {
        *T = NULL;
    }else{
        *T = (BiTree) malloc(sizeof(BiTNode));
        if(*T == NULL)
            exit(-1);
        (*T)->data = ch;                    //生成跟结点
        createTree(&(*T)->lchild);          //构造左子树
        createTree(&(*T)->rchild);          //构造右子树
    }
}

bool isBiTreeEmpty(BiTree T){
    if (T) {
        return false;
    }
    return true;
}

/*求解二叉树的深度，代码。。牛叉*/
int getBiTreeDepth(BiTree T){
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i=getBiTreeDepth(T->lchild);
    else
        i=0;
    if(T->rchild)
        j=getBiTreeDepth(T->rchild);
    else
        j=0;
    return i>j?i+1:j+1;
}

/*获取树的根元素*/
char getRoot(BiTree T){
    if(isBiTreeEmpty(T)){
        return ' ';
    }
    return T->data;
}

/*先序遍历二叉树*/
void preOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    printf("%c ", T->data);         //遍历中间结点
    preOrderTraverse(T->lchild);    //遍历左结点
    preOrderTraverse(T->rchild);    //遍历右结点
}

/*中序遍历二叉树*/
void inOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    inOrderTraverse(T->lchild);    //遍历左结点
    printf("%c ", T->data);        //遍历中间结点
    inOrderTraverse(T->rchild);    //遍历右结点
}

/*后续遍历二叉树*/
void postOrderTraverse(BiTree T){
    if(T == NULL){
        return;
    }
    postOrderTraverse(T->lchild);    //遍历左结点
    postOrderTraverse(T->rchild);    //遍历右结点
    printf("%c ", T->data);          //遍历中间结点
}

int main(){
    BiTree T;
    initBiTree(&T);
    printf("是否为空：%d\n", isBiTreeEmpty(T));
    //构造要生成树的字符（char）数组(先序遍历)
    strAssgin(str, "ABDH#K###E##CFI###G#J##");
    //构造
    createTree(&T);
    printf("是否为空：%d,深度为:%d\n", isBiTreeEmpty(T), getBiTreeDepth(T));
    
    char c = getRoot(T);
    printf("根元素是：%c\n", c);
    
    printf("先序遍历二叉树：");
    preOrderTraverse(T);
    printf("\n中序遍历二叉树：");
    inOrderTraverse(T);
    printf("\n后序遍历二叉树：");
    postOrderTraverse(T);
    printf("\n");
}
