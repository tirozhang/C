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

int getTheWay( SearchTree T ,int sum ){
    if( T->m_pLeft == NULL && T->m_pRight == NULL){
        if( T->m_nValue == sum ){
            printf("%d\t",T->m_nValue);
            return 0;
        }
    }else if( T->m_nValue <= sum ){
        int findNum = sum -T->m_nValue ;
        int flag = 0;
        //printf("%d\t",findNum);
        if( T->m_pLeft != NULL && getTheWay( T->m_pLeft , findNum ) == 0 ){
            flag = 1;
        }
        if( T->m_pRight != NULL &&getTheWay( T->m_pRight, findNum ) == 0  ){
            flag = 1;
        }
        if( flag == 1){
            printf("%d\t",T->m_nValue);
            return 0;
        }
    }
}

void PrintTree( SearchTree T ){
    if( T != NULL ){
        PrintTree( T->m_pLeft );
        printf("%d\n",T->m_nValue );
        PrintTree( T->m_pRight );
    }
}


int main(){
    SearchTree theTree = NULL;
    int sum = 22;
    theTree = Insert( 10 , theTree );
    theTree = Insert( 5 , theTree );
    theTree = Insert( 4 , theTree );
    theTree = Insert( 7 , theTree );
    theTree = Insert( 12 , theTree );

    getTheWay( theTree , sum );
    //PrintTree( theTree);

    return 0;
}
