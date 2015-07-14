#include<stdio.h>
#include "SearchTree.h"
#include "../fatal.h"

SearchTree head = malloc( sizeof( struct TreeNode ) )
if( head == NULL ){
    FatalError( "Out of space !!!" );
}

SearchTree Insert( Element X, SearchTree T ){
    if( T == NULL ){
        T = malloc( sizeof( struct TreeNode ) );
        if( T == NULL ){
            FatalError( "Out of space !!!" );
        }else{
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }else if( X < T->Element ){
        Insert( X, T->Left );
    }else if( X > T->Element ){
        Insert( X, T->Right );
    }
    return T; 
}

int main(){

}
