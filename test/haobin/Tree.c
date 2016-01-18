//
//  Tree.c
//  
//
//  Created by 郑影 on 15/10/21.
//
//
// 二叉树构造与遍历
#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
    int data;
    struct BTNode *pLchild;//p是指针 L是左 child是孩子
    struct BTNode *pRchild;
};

void PreTraverseBTree( struct BTNode * pT );
void InTraverseBTree( struct BTNode * pT );
void PostTraverseBTree( struct BTNode * pT );
struct BTNode *CreateBTree( void );

int main( void )
{
    struct BTNode *pT = CreateBTree();
    
    printf( "先序\n" );
    PreTraverseBTree( pT );//先序
    
    printf( "中序\n" );
    InTraverseBTree( pT );//中序
    
    printf( "后序\n" );
    PostTraverseBTree( pT );//后序
    
    
    return 0;
}

void PreTraverseBTree( struct BTNode * pT )
{
    /*
     伪算法
     先访问根节点
     再先序访问左子树
     再先序访问右子树
     */
    if( pT != NULL )
    {
        printf( "%c\n", pT->data );
        
        if( NULL != pT->pLchild )
        {
            PreTraverseBTree( pT->pLchild );
        }
        
        if( NULL != pT->pRchild )
        {
            PreTraverseBTree( pT->pRchild );
            //pT->pLchild可以代表整个左子树
        }
        
    }
    
    
}



void InTraverseBTree( struct BTNode * pT )
{
    
    if( pT != NULL )
    {
        
        
        if( NULL != pT->pLchild )
        {
            InTraverseBTree( pT->pLchild );
        }
        
        printf( "%c\n", pT->data );
        
        if( NULL != pT->pRchild )
        {
            InTraverseBTree( pT->pRchild );
            //pT->pLchild可以代表整个左子树
        }
        
    }
    
}


void PostTraverseBTree( struct BTNode * pT )
{
    
    if( pT != NULL )
    {
        
        
        if( NULL != pT->pLchild )
        {
            InTraverseBTree( pT->pLchild );
        }
        
        
        if( NULL != pT->pRchild )
        {
            InTraverseBTree( pT->pRchild );
            //pT->pLchild可以代表整个左子树
        }
        
        printf( "%c\n", pT->data );
        
    }
    
    
}

struct BTNode *CreateBTree( void )
{
    struct BTNode *pA = ( struct BTNode * )malloc( sizeof( struct BTNode ) );
    struct BTNode *pB = ( struct BTNode * )malloc( sizeof( struct BTNode ) );
    struct BTNode *pC = ( struct BTNode * )malloc( sizeof( struct BTNode ) );
    struct BTNode *pD = ( struct BTNode * )malloc( sizeof( struct BTNode ) );
    struct BTNode *pE = ( struct BTNode * )malloc( sizeof( struct BTNode ) );
    
    pA->data = 'A';
    pB->data = 'B';
    pC->data = 'C';
    pD->data = 'D';
    pE->data = 'E';
    
    pA->pLchild = pB;
    pA->pRchild = pC;
    
    pB->pLchild = pB->pRchild = NULL;
    
    pC->pLchild = pD;
    pC->pRchild = NULL;
    
    pD->pLchild = NULL;
    pD->pRchild = pE;
    
    pE->pLchild = pE->pRchild = NULL;
    
    return pA;
    
}




