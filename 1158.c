#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _node {
	int data;
	struct _node* next;
} Node;

typedef struct _List {
	Node* head;
	Node* tail;
	Node* cur;
	Node* before;
} CList;

typedef CList List;

void Init(List* plist);
void Insert(List* plist, int data);
void Cur_Init(List* plist);		// Shift�� �ϱ� �� cur�� before�� tail�� ����Ű���� �ʱ�ȭ
int Shift(List* plist, int K);	// cur�� before�� �̵���Ű�� �Լ�
void Remove(List* plist);	// Shift �Լ��� ȣ��� �� cur�� ����Ű�� node�� ����

int main() {
	int N, K, i;
	scanf("%d %d", &N, &K);

	List list;
	Init(&list);

	for (i = 1; i <= N; i++) {
		Insert(&list, i);
	}

	Cur_Init(&list);

	printf("<%d", Shift(&list, K));
	Remove(&list);

	for (i = 0; i < N - 1; i++) {
		printf(", %d", Shift(&list, K));
		Remove(&list);
	}
	printf(">");
	return 0;
}

void Init(List* plist) {
	plist->head = NULL;
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
}

void Insert(List* plist, int data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (plist->head == NULL) {	// ť�� ����ִ� ��Ȳ
		plist->head = newNode;
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else {
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode;
	}
}

void Cur_Init(List* plist) {
	plist->cur = plist->tail;
	plist->before = plist->tail;
}

int Shift(List* plist, int K) {
	plist->cur = plist->cur->next;	// before�� �� ĭ ���̸� ����� ���� cur�� ���� �� �� �̵���Ŵ
	for (int i = 0; i < K - 1; i++) {	// K > 1�� ��� cur�� before �̵�
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
	}
	return plist->cur->data;
}

void Remove(List* plist) {
	Node* rpos = plist->cur;
	if (rpos == plist->tail) {	// tail�� �����ϴ� ���
		if (plist->tail == plist->tail->next)	// ť�� ���Ұ� �� �ϳ��� ������ ��
			plist->tail = NULL;
		else
			plist->tail = plist->before;	// tail�� �����ϹǷ� tail�� ��ġ�� �Ű���
	}
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	free(rpos);
}