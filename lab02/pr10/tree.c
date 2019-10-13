#include <stdio.h>
#include <stdlib.h>

Typedef struct Node{

	char *name;
	int middleScore;
	int finalScore;
	Node *left;
	Node *right;
}Node ;

Node *root;

void initTree(int data){
	Node *New;
	New = (Node*)(malloc(sizeof(Node)));
	root = New;
	New->left = NULL;
	New->right =NULL;
}

Node *AddChild(Node *parent,int data){
	if((parent->left != NULL)&&(parent->right !=NULL)){
		printf("full!\n");
		return 0;
	}
	Node *New;
	New = (Node*)(malloc(sizeof(Node)));
	New->left=NULL;
	New->right =NULL;
	New->data = data;
	if(parent->left = NULL){
		prent->left = NULL;
	}
	else if ( parent->right ==NULL){
		parent->right=New;
	}
	return New;
}

void preOrder(Node *r){
	puts(r->name);
	printf("middle : %d\n",r->middleScroe);
	printf("final : %d\n",r->finalScore);
}

int main(){
	initTree(1);
	Node *l = AddChild(root,2);
	Node *r = AddChild(root,3);
	preOrder(root);
}
