

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

#define MAX_NAME_LENGTH 20

typedef struct
{
    char name[MAX_NAME_LENGTH];
    int midScore;
    int fiScore;

} element;

typedef struct treeNode
{
    element key;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

treeNode *searchBST(treeNode *root, element key)
{
    treeNode *p;
    int compare;
    p = root;
    while (p != NULL)
    {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
        {
            p = p->left;
            // printf("\n검색 중 왼쪽학생 : %s", p->key.name);
        }
        else if (compare > 0)
        {
            p = p->right;
            // printf("\n검색 중 오른쪽 학생 : %s", p->key.name);
        }
        else
        {
            printf("\n찾은 학생 : %s", p->key.name);
            printf("\n 중간 점수 : %d\n",p->key.midScore);
            printf("\n 기말점수 : %d\n",p->key.fiScore);
            return p;
        }
    }
    return p;
}

treeNode *insertKey(treeNode *p, element key)
{
    treeNode *newNode;
    int compare;
    if (p == NULL)
    {
        newNode = (treeNode *)malloc(sizeof(treeNode));
        newNode->key = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    else
    {
        compare = strcmp(key.name, p->key.name);
        if (compare < 0)
        {
            p->left = insertKey(p->left, key);
            return p;
        }
        else if (compare > 0)
        {
            p->right = insertKey(p->right, key);
            return p;
        }
        else
        {
            printf("\n 이미 같은 학생이 있습니다. \n");
            return p;
        }
    }
}

void insert(treeNode **root, element key)
{
    *root = insertKey(*root, key);
}

void deleteNode(treeNode *root, element key)
{
    treeNode *parent, *p, *succ, *succ_parent;
    treeNode *child;

    parent = NULL;
    p = root;
    while ((p != NULL) && (strcmp(p->key.name, key.name) != 0))
    {
        parent = p;
        if (strcmp(key.name, p->key.name) < 0)
            p = p->left;
        else
            p = p->right;
    }
    succ_parent = p;
    if (p == NULL)
    {
        printf("\n 찾는 학생이 트리에 없습니다!!");
        return;
    }

    // 단말노드의 삭제
    if ((p->left == NULL) && (p->right == NULL))
    {
        if (parent != NULL)
        {
            if (parent->left == p)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
        else
            root = NULL;
    }

    // 자식노드가 한 개인 노드의 삭제
    else if ((p->left == NULL) || (p->right == NULL))
    {
        if (p->left != NULL)
            child = p->left;
        else
            child = p->right;
        if (parent != NULL)
        {
            if (parent->left == p)
                parent->left = child;
            else
                parent->right = child;
        }
        else
            root = child;
    }

    // 자식노드가 두 개인 노드의 삭제
    else
    {
        //succ_parent=p;
        succ = p->right;
        while (succ->left != NULL)
        {
            succ_parent = succ;
            succ = succ->left;
        }
        if (succ_parent->left == succ)
            succ_parent->left = succ->right;
        else
            succ_parent->right = succ->right;
        p->key = succ->key;
        p = succ;
    }
    free(p);
}

void menu()
{
    printf("\n*---------------------------*");
    printf("\n\t1 : 입력");
    printf("\n\t2 : 삭제");
    printf("\n\t3 : 검색");
    printf("\n\t4 : 출력");
    printf("\n\t5 : 종료");
    printf("\n*---------------------------*\n");
}

inorderDisplay(treeNode *root)
{
    if (root)
    {
        inorderDisplay(root->left);
        printf("\n%s : mid : %d , final : %d", root->key.name, root->key.midScore, root->key.fiScore);
        inorderDisplay(root->right);
    }
}

void main()
{
    char choice;
    element e;
    treeNode *root = NULL, *temp;

    do
    {
        fflush(stdin);
        menu();
        choice = getchar();
        getchar();



        switch (choice - '0')
        {
        case 1:
            printf("\n[학생 입력] 학생를 입력하세요 : ");
            gets(e.name);
            printf("\n[점수입력] 중간고사 점수를 입력하세요 : ");
            scanf("%d",&e.midScore);
            printf("\n[점수입력] 기말고사 점수를 입력하세요 : ");
            scanf("%d",&e.fiScore);
            insert(&root, e);
            break;
        case 2:
            printf("\n[학생 삭제] 삭제할 학생 : ");
            gets(e.name);
            deleteNode(root, e);
            break;
        case 3:
            printf("\n[학생 검색] 검색할 학생 : ");
            gets(e.name);

            temp = searchBST(root, e);
            if (temp != NULL){
                printf("\n중간고사 점수 : %d", temp->key.midScore);
                printf("\n기말고사 점수 : %d", temp->key.fiScore);
            }else
                printf("\n없는 학생입니다.");
            break;
        case 4:
            printf("\t[학생 출력]");
            inorderDisplay(root);
            printf("\n\t[---------]\n");
            break;
        }
    } while ((choice - '0') != 5);
}