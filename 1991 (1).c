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
int connect(Node* node, Node* new);
void preorder(Node* node);
void inorder(Node* node);
void postorder(Node* node);

int main() {
	int N, i;
	scanf("%d", &N);
	getchar();
	char parent, l_child, r_child;
	scanf("%c %c %c", &parent, &l_child, &r_child);
	getchar();

	/* Ã¹ root ³ëµå »ðÀÔ */
	Node* root = MakeNode(parent);
	if (l_child != '.') {
		Node* left = MakeNode(l_child);
		root->left = left;
	}
	if (r_child != '.') {
		Node* right = MakeNode(r_child);
		root->right = right;
	}

	for (i = 1; i < N; i++) {
		scanf("%c %c %c", &parent, &l_child, &r_child);
		getchar();
		Node* new = MakeNode(parent);
		if (l_child != '.') {
			Node* left = MakeNode(l_child);
			new->left = left;
		}
		if (r_child != '.') {
			Node* right = MakeNode(r_child);
			new->right = right;
		}
		connect(root, new);
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

int connect(Node* node, Node* new) {
	if (node->left != NULL) {
		if (node->left->alph == new->alph) {
			free(node->left);
			node->left = new;
		}
		else
			connect(node->left, new);
	}
	if (node->right != NULL) {
		if (node->right->alph == new->alph) {
			free(node->right);
			node->right = new;
		}
		else
			connect(node->right, new);
	}
}

void preorder(Node* node) {
	printf("%c", node->alph);
	if (node->left != NULL)
		preorder(node->left);
	if (node->right != NULL)
		preorder(node->right);
}

void inorder(Node* node) {
	if (node->left != NULL)
		inorder(node->left);
	printf("%c", node->alph);
	if (node->right != NULL)
		inorder(node->right);
}

void postorder(Node* node) {
	if (node->left != NULL)
		postorder(node->left);
	if (node->right != NULL)
		postorder(node->right);
	printf("%c", node->alph);
}
