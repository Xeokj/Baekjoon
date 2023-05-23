#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node {
	char alph;
	struct _Node* left;
	struct _Node* right;
} Node;

Node* MakeNode(char);
int Find(Node* node, Node* new);
void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

int main() {
	int N, i;
	scanf("%d", &N);

	char parent, l_child, r_child;
	scanf(" %c %c %c", &parent, &l_child, &r_child);
	Node* root = MakeNode(parent);
	Node* left = MakeNode(l_child);
	Node* right = MakeNode(r_child);
	root->left = left;
	root->right = right;

	for (i = 1; i < N; i++) {
		scanf(" %c %c %c", &parent, &l_child, &r_child);
		Node* new = MakeNode(parent);
		Node* left = MakeNode(l_child);
		Node* right = MakeNode(r_child);
		new->left = left;
		new->right = right;
		Find(root, new);
	}
	preorder(root);
	printf("\n");
	inorder(root);
	printf("\n");
	postorder(root);
	return 0;
}

Node* MakeNode(char parent) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->alph = parent;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

int Find(Node* node, Node* new) {
	if (node->left == NULL)
		return 0;
	if (node->right == NULL)
		return 0;
	if (node->left->alph == new->alph) {
		free(node->left);
		node->left = new;
	}
	else if (node->right->alph == new->alph) {
		free(node->right);
		node->right = new;
	}
	else {
		if (node->left->alph != '.')
			Find(node->left, new);
		if (node->right->alph != '.')
			Find(node->right, new);
	}
}

void preorder(Node* node) {
	printf("%c", node->alph);
	if (node->left->alph != '.')
		preorder(node->left);
	if (node->right->alph != '.')
		preorder(node->right);
}

void inorder(Node* node) {
	if (node->left->alph != '.')
		inorder(node->left);
	printf("%c", node->alph);
	if (node->right->alph != '.')
		inorder(node->right);
}

void postorder(Node* node) {
	if (node->left->alph != '.')
		postorder(node->left);
	if (node->right->alph != '.')
		postorder(node->right);
	printf("%c", node->alph);
}