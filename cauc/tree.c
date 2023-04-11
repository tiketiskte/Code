#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight( BinTree BT );

int main()
{
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}
/* 你的代码将被嵌在这里 */
int h1 = 0, h2 = 0;
int GetHeight( BinTree BT ) {
    while(BT != NULL) {
        if(BT -> Left != NULL) {
            h1 = GetHeight(BT->Left) + 1;
        } else if(BT -> Right != NULL) {
            h2 = GetHeight(BT->Right) + 1;
        }
    }
    if(h1 > h2) {
        return h1;
    } else {
        return h2;
    }
}