#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define MAX 100001

typedef struct _Heap {
	int numOfData;
	int arr[MAX];
} Heap;

void initHeap(Heap* heap);
void Insert(Heap* heap, int data);
int Delete(Heap* heap);

int main() {
	int n, x, i;
	Heap heap;
	initHeap(&heap);
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x);
		if (x == 0) {
			if (!heap.numOfData)
				printf("0\n");
			else
				printf("%d\n", Delete(&heap));
		}
		else {
			Insert(&heap, x);
		}
	}

	return 0;
}

void initHeap(Heap* heap) {
	heap->numOfData = 0;
}

void Insert(Heap* heap, int data) {
	int idx = heap->numOfData + 1;
	while (idx != 1) {
		if (data > heap->arr[idx / 2]) {
			heap->arr[idx] = heap->arr[idx / 2];
			idx /= 2;
		}
		else
			break;
	}
	heap->arr[idx] = data;
	heap->numOfData++;
}

int Delete(Heap* heap) {
	int root = heap->arr[1];
	int last = heap->arr[heap->numOfData];
	heap->numOfData--;

	int pIdx = 1, Lchild = pIdx * 2, Rchild = pIdx * 2 + 1;
	int cIdx;
	while (Lchild <= heap->numOfData) {
		if (Lchild == heap->numOfData) {	// 자식이 한 쪽만 있을 때
			if (last < heap->arr[Lchild]) {
				cIdx = Lchild;
				heap->arr[pIdx] = heap->arr[cIdx];
				pIdx = cIdx;
			}
			break;
		}
		else {
			cIdx = heap->arr[Lchild] > heap->arr[Rchild] ? Lchild : Rchild;
			if (last > heap->arr[cIdx])
				break;
			else
				heap->arr[pIdx] = heap->arr[cIdx];
		}
		pIdx = cIdx;
		Lchild = pIdx * 2;
		Rchild = pIdx * 2 + 1;
	}
	heap->arr[pIdx] = last;
	return root;
}