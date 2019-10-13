#include <stdio.h>  // 표준 입출력 헤더파일
#include <stdlib.h> // 난수, 메모리할당 등을 사용할 수 있는 헤더파일
#include <string.h> // 문자열 비교 함수 사용하기 위한 헤더파일

#define MAX_WORD_SIZE 100    // 기호 상수 사이즈
#define MAX_MEANLNG_SIZE 200 // 기호 상수 사이즈

// 데이터형식
typedef struct
{
    char word[MAX_WORD_SIZE];       // 단어를 넣기 위한 공간(char은 2바이트)
    char meaning[MAX_MEANLNG_SIZE]; // 단어의 의미를 넣기 위한 공간
} element;

// 노드의 구조
typedef struct treeNode
{ // 영어 사전 이진 트리의 노드 구조를 정의
    element key;
    struct treeNode *left;  // 왼쪽 트리에 대한 링크
    struct treeNode *right; // 오른쪽 트리에 대한 링크
} treeNode;

int main()
{
    element e;
    treeNode *root = NULL;        // 최초 root 노드 NULL 값으로 초기화
    treeNode *foundedNode = NULL; // 탐색에 필요한 Node NULL 값으로 초기화
    char choice;

    while (1)
    {
        menu();
        choice = getchar();
        fflush(stdin); // 입력받은 버퍼를 비워준다. (메뉴선택 값 비워줌)
        switch (choice)
        {
        case '1':
            printf("\t 단어 : "); // 삽입함수 호출
            gets(e.word);
            printf("\t 의미 : ");
            gets(e.meaning);
            insertNode(&root, e);
            break;
        case '2':
            printf("삭제할 단어 : "); // 삭제함수 호출
            gets(e.word);
            deleteNode(&root, e);
            break;
        case '3':
            printf("사전을 탐색합니다."); // 삽입된 노드를 순회하여 각 내용을 출력
            printf("단어 : ");
            gets(e.word);
            foundedNode = searchBST(root, e); // 검색한 결과를 foundedNode로 넣어줌
            if (foundedNode != NULL)
            {
                printf("\n\t [%s 검색완료]\n", foundedNode->key.word);
                printf("\t 단어 : %s\n", foundedNode->key.word);
                printf("\t 의미 : %s\n", foundedNode->key.meaning);
            }
            else
                printf("\n\t 문자를 찾지 못했습니다. \n");
            break;
        case '4':
            printf("사전을 출력합니다.\n");
            display(root);
            printf("\n\n");
            break;
        case '5':
            return 0;
        default:
            printf("없는 메뉴입니다. 메뉴를 다시 선택하세요! \n");
            break;
        }
    }
}
void menu()
{
    printf("\n*-- 이진 탐색 트리 영어 사전 --*");
    printf("\n\t1 : 입력");
    printf("\n\t2 : 삭제");
    printf("\n\t3 : 탐색");
    printf("\n\t4 : 출력");
    printf("\n\t5 : 종료");
    printf("\n*-----------------------------*");
    printf("\n메뉴입력>>");
}
void insertNode(treeNode **root, element x)
{
    treeNode *nNode;         // 새 노드
    treeNode *qNode = NULL;  // 삽입할 자리를 찾기 위한 포인터변수
    treeNode *pNode = *root; // 삽입할 노드의 부모노드를 저장하기 위한 포인터변수

    // 탐색을 먼저 수행하여 삽입할 자리를 찾는다.
    while (pNode != NULL)
    {
        if (strcmp(x.word, pNode->key.word) == 0)
        { // s1 = s2( strcmp 0 반환 )
            printf("\n\t 이미 같은 키가 있습니다! \n");
            return;
        }
        // 같은 키가 아닌 것을 확인한 상태
        qNode = pNode; // 삽입할 자리를 찾기 위해 pNode를 qNode로 넣는다.
        if (strcmp(x.word, pNode->key.word) < 0)
        { // s1 < s2( strcmp -1 반환)
            printf("\t 왼쪽 이동\n");
            pNode = pNode->left;
        }
        else if (strcmp(x.word, pNode->key.word) > 0)
        { // s1 > s2( strcmp 1 반환)
            printf("\t 오른쪽 이동\n");
            pNode = pNode->right;
        }
    }
    // 삽입할 자리를 찾았으니 삽입할 노드를 생성한다.
    nNode = (treeNode *)malloc(sizeof(treeNode)); // 새 노드의 공간을 할당한다.
    nNode->key = x;                               // 새 노드 key를 x의 값으로 할당한다.(word와 meaning)
    nNode->left = NULL;                           // 최초노드이기 때문에 왼쪽 링크 NULL
    nNode->right = NULL;                          // 최초노드이기 때문에 오른쪽 링크 NULL

    // 삽입할 자리의 부모노드와 비교 노드를 연결한다.
    if (qNode != NULL)
    {
        if (strcmp(x.word, qNode->key.word) < 0)
        {
            printf("\t 왼쪽에 저장\n");
            qNode->left = nNode;
        }
        else if (strcmp(x.word, qNode->key.word) > 0)
        {
            printf("\t 오른쪽에 저장\n");
            qNode->right = nNode;
        }
    }
    else
    {
        *root = nNode; // 비어 있다면 새로 만든 노드를 root로 넣는다.
    }
}
void deleteNode(treeNode **root, element x)
{
    // root 노드부터 탐색하여 key 값과 같은 노드를 찾아 삭제하는 연산
    treeNode *parent = NULL;      // 부모노드
    treeNode *pNode = *root;      // 현재노드
    treeNode *child;              // 자식노드
    treeNode *succ, *succ_parent; // 후계자 노드를 구할 포인터

    // 삭제할 노드의 위치 탐색(삽입 때와 같음)
    while ((pNode != NULL) && (strcmp(x.word, pNode->key.word) != 0))
    {
        parent = pNode;
        if (strcmp(x.word, pNode->key.word) < 0)
        {
            pNode = pNode->left;
        }
        else
        {
            pNode = pNode->right;
        }
    }
    // 탐색 결과 pNode가 NULL 이다. 키가 없다는 뜻
    if (pNode == NULL)
    {
        printf("\n\t찾는 키가 이진 트리에 없습니다!\n");
        return; //종료
    }

    // 삭제후 처리 종류 3가지- 단말 노드인 경우
    if ((pNode->left == NULL) && (pNode->right == NULL))
    {
        if (parent != NULL)
        { // 부모노드가 존재하는지 다시한번 확인
            if (parent->left == pNode)
                parent->left = NULL; // 부모노드의 왼쪽이 삭제할 노드인 경우
            else
                parent->right = NULL; // 부모노드의 오른쪽 삭제할 노드인 경우
        }
        else
            root = NULL; // 그렇지 않는 경우(전체가 하나) 부모노드가 없다면 root=NULL
    }

    // 삭제할 노드가 한 개의 자식 노드를 가진 경우
    else if ((pNode->left == NULL) || (pNode->right == NULL))
    { // left or right
        if (pNode->left != NULL)
            child = pNode->left; // 삭제할 노드의 왼쪽을 자식노드로 연결
        else
            child = pNode->right; // 삭제할 노드의 오른쪽 자식노드로 연결

        if (parent != NULL)
        { // 부모노드 값이 NULL이 아닐 경우
            if (parent->left == pNode)
                parent->left = child; // 부모노드의 왼쪽이 삭제할 노드라면 자식노드를 부모노드의 왼쪽과 연결
            else
                parent->right = child; // 부모노드의 오른쪽 삭제할 노드라면 자식노드를 부모노드의 오른쪽 연결
        }
        else
            *root = child; // 삭제 후 값이 남은 값이 자식노드 밖에 없다면 root로 지정
    }

    // 삭제할 노드가 두 개의 자식 노드를 가진 경우
    else
    {
        succ_parent = pNode; // 삭제할 노드를 succ_parent로 지정
        succ = pNode->left;  // 왼쪽 서브트리에서 후계자를 찾는다.
        while (succ->right != NULL)
        {                       // 후계자를 찾아서 계속 오른쪽으로 이동(오른쪽 값이 NULL일 때까지 반복)
            succ_parent = succ; // 값의 비교를 위해 탐색 중인 노드의 부모값도 같이 이동
            succ = succ->right; // 왼쪽 서브트리(가장 오른쪽 노드) 오른쪽 서브트리(가장 왼쪽 노드)
        }
        // 왼쪽 서브트리에서 오른쪽 값이 없을 경우 삭제할 노드의 왼쪽 노드가 후계자가 됨
        if (succ_parent->left == succ)
            succ_parent->left;
        // 선택된 후계자의 오른쪽은 NULL 값이므로 후계자의 왼쪽 값을 후계자의 부모노드 오른쪽에 연결
        else
            succ_parent->right = succ->left;
        pNode->key = succ->key; // 후계자의 key값을 삭제할 노드의 key으로 넣어줌
        pNode = succ;           // 찾은 값을 삭제할 노드의 위치로 변경
    }
    free(pNode); // 삭제노드의 메모리할당 해제
}
// 트리를 탐색(검색)하는 함수
treeNode *searchBST(treeNode *root, element x)
{ // 이진 탐색트리에서 키값이 x인 노드의 위치를 탐색하는 연산
    // p가 NULL 이면 반복중지 계속해서 순회하여 찾는다.
    while (root != NULL)
    {
        if (strcmp(x.word, root->key.word) == 0)
            return root;
        else if (strcmp(x.word, root->key.word) < 0)
            root = root->left;
        else if (strcmp(x.word, root->key.word) > 0)
            root = root->right;
    }
    printf("\n\t찾는 키가 없습니다!");
    return root;
}
void display(treeNode *root)
{ // 이진 탐색 트리를 중위 순회하면서 출력하는 연산
    int i;
    if (root != NULL)
    {
        display(root->left);
        printf("\t %s : %s",
               root->key.word, root->key.meaning);
        printf("\t\t\t [");
        for (i = 0; i <= MAX_WORD_SIZE; i++)
        {
            if (root->key.word[i] == NULL)
                break;
            else
                printf("%d ", root->key.word[i]);
        }
        printf("]\n");
        display(root->right);
    }
}
