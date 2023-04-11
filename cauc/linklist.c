#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {false, true} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List MakeEmpty(); 
Position Find( List L, ElementType X );
bool Insert( List L, ElementType X, Position P );
bool Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        if ( Insert(L, X, 0)==false )
            printf(" Insertion Error: %d is not in.\n", X);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &P);
        if ( Delete(L, P)==false )
            printf(" Deletion Error.\n");
        if ( Insert(L, 0, P)==false )
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */
List MakeEmpty() {
    List l;
//     l->Data[i] = (ElementType)malloc(MAXSIZE * sizeof(ElementType));
    for(int i = 0; i < MAXSIZE; i++) {
        l->Data[i] = 0;
    }
    l->Last = ERROR;
    return l;
}
Position Find( List L, ElementType X ) {
    for(int i = 0; i < MAXSIZE; i++) {
        if(L->Data[i] == X) {
            return i;
        }
    }
    return ERROR;
}
bool Insert( List L, ElementType X, Position P ) {
    if(L->Last == MAXSIZE - 1) {
        printf("ILLEGAL POSITION\n");
        return false;
    }
    for(int i = MAXSIZE - 2; i >= P; i--) {
        int j = i;
        L->Data[j++] = L->Data[j];
    }
    L->Data[P] = X;
    return true;
}
bool Delete( List L, Position P ) {
    if(P < 0 || P >= MAXSIZE) {
        printf("POSITION P EMPTY");
        return false;
    }
    for(int i = P; i < MAXSIZE; i++) {
        int j = i;
        L->Data[j] = L->Data[j++];
    }
    return true;
}