#ifdef _SEACHTREE_H
struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int Element;
typedef int ElementType;

 SearchTree MakeEmpty( SearchTree T);
 Position Find( Element X, SearchTree T);
 SearchTree Insert( Element X, SearchTree T);

#endif

 struct TreeNode
{
    ElementType Element;
    Position Left;
    Position Right;
}
