#include "List.h"
#include <stdlib.h>
#include "fatal.h"

struct Node
{
    ElementType Element;
    Position    Next;
};

List InitList()
{
    List TmpCell;
    TmpCell =  (List)malloc( sizeof(struct Node));
    TmpCell->Next = NULL;
    return TmpCell;
}

List MakeEmpty(List L)
{
   return L; 
}

int IsEmpty(List L)
{
    return L->Next == NULL;
}

void Insert( ElementType X , List L ,Position P)
{
    Position TmpCell;
    TmpCell = malloc( sizeof(struct Node));
    if( NULL == TmpCell ){
        FatalError("Out of space !!!");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}

void PrintList(List L)
{
    while( NULL != L )
    {
        printf("%d\n",L->Element);
        L = L->Next;
    }
}

int main(){
    PtrToNode List = InitList();
    Insert( 1 , List ,List);
    Insert( 2 , List ,List);
    Insert( 3 , List ,List);
    Insert( 4 , List ,List);
    Insert( 5 , List ,List->Next);
    PrintList(List);

    return 1;
}
