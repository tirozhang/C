#include<stdio.h>
#include <stdlib.h>
struct  TreeNode;
typedef struct TreeNode *SearchTree;
typedef struct TreeNode *DoubleList;
typedef int ElementType; 

void convertToDoubleList( SearchTree T );
struct TreeNode 
{
    int m_nValue;
    SearchTree m_pLeft;
    SearchTree m_pRight;

};

DoubleList pHead;
DoubleList pCurrent;


SearchTree Insert( int X, SearchTree T){
    
    if( T ==  NULL ){
        SearchTree newNode = malloc( sizeof( struct TreeNode ) );
        newNode->m_nValue = X;
        newNode->m_pLeft = NULL;
        newNode->m_pRight= NULL;
        return newNode;
    }else if( T->m_nValue > X ){
        T->m_pLeft  = Insert( X , T->m_pLeft);
    }else{
        T->m_pRight = Insert( X , T->m_pRight);
    }
    return T;
    
}

DoubleList convertTree( SearchTree T ){
    if( T == NULL ){
        return ;
    }
    if( T->m_pLeft != NULL ){
        convertTree( T->m_pLeft );
    }
    convertToDoubleList( T );
    if( T->m_pRight != NULL ){
        convertTree( T->m_pRight );
    }
}

void convertToDoubleList( SearchTree T ){
    if( pHead == NULL ){
        pHead = malloc( sizeof( struct TreeNode ) ); 
        pHead->m_pRight = T;
        T->m_pLeft = pHead ;
    }else{
        pCurrent->m_pRight = T;
        T->m_pLeft = pCurrent;
    }
    pCurrent = T;
    printf("%d\n",pCurrent->m_nValue);
}

void PrintTree( SearchTree T ){
    if( T != NULL ){
        PrintTree( T->m_pLeft );
        printf("%d\n",T->m_nValue );
        PrintTree( T->m_pRight );
    }
}

void PrintList( DoubleList T ){
    if( T !=NULL ){
        printf( "%d\n",T->m_nValue );
        PrintList( T->m_pRight);
    }
}

int main(){
    SearchTree theTree = NULL;
    theTree = Insert( 5 , theTree );
    theTree = Insert( 2 , theTree );
    theTree = Insert( 6 , theTree );
    theTree = Insert( 1 , theTree );
    theTree = Insert( 7 , theTree );

    convertTree( theTree );
    //PrintList( pHead );

    return 0;
}
// vim600: ts=4 st=4 foldmethod=marker foldmarker=<<<,>>> syn=c
// vim600: enc=utf-8 commentstring=//\ %s
    
