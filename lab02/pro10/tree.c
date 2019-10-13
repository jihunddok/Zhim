
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    struct Node* Left;
    struct Node* Right;
    char name[10];
    int midSc;
    int fiSc;
} Node;

Node*  CreateNode( char NewName,int NewMid,int NewFi );

void      DestroyNode( Node* Node );
void      DestroyTree( Node* Root );

void      PreorderPrintTree( Node* Node );
void      InorderPrintTree( Node* Node );
void      PostorderPrintTree( Node* Node );


Node*  CreateNode( char NewName,int NewMid,int NewFi )
{
 Node * NewNode = (Node *)malloc(sizeof(Node));
 NewNode->Left = NULL;
 NewNode->Right = NULL;
 NewNode->name = NewName;
 NewNode->midSc = NewMid;
 NewNode->fiSc = NewFi;
 return NewNode;
}                                                                

                                                                                                  
void      DestroyNode( Node* Node )
{
 free(Node);
}                                                              

void      DestroyTree( Node* Root )
{
}                                                

void      PreorderPrintTree( Node* Node )
{
 if ( Node == NULL )
  return ;
 
 printf("%c ",Node->Data);

 PreorderPrintTree(Node->Left);
 PreorderPrintTree(Node->Right);
}                                                        

void      InorderPrintTree( Node* Node )
{

 if ( Node == NULL )
  return ;

 InorderPrintTree(Node->Left);
 printf("%c ",Node->Data);
 InorderPrintTree(Node->Right);
}                                                         

void      PostorderPrintTree( Node* Node )
{
 if ( Node == NULL )
  return ;

 PostorderPrintTree(Node->Left);
 PostorderPrintTree(Node->Right);

 printf("%c ",Node->Data);
}

int main( void )
{
    /*  Create Node */
    Node* A = CreateNode('A');
    Node* B = CreateNode('B');
    Node* C = CreateNode('C');
    Node* D = CreateNode('D');
    Node* E = CreateNode('E');

    /*  Append Node */
    A->Left  = B;
    B->Left  = C;
    B->Right = D;
    A->Right = E;

    /*  Print Node */
    printf("Preorder Sequence \n");
    PreorderPrintTree( A );
    printf("\n\n");

    printf("Inorder Sequence \n");
    InorderPrintTree( A );
    printf("\n\n");

    printf("Postorder Sequence \n");
    PostorderPrintTree( A );
    printf("\n");

    /*  Destroy */
    DestroyTree( A );

    return 0;
}