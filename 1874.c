#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int n, i;
	scanf("%d", &n);
	int* stack = (int*)calloc(n + 2, sizeof(int));
	int num, top = 0, x = 1;
	int* visited = (int*)calloc(n + 2, sizeof(int));

	char* op = (char*)calloc((n + 1) * 2, sizeof(char));	// ��¹��� ������ �迭
	int op_idx = 0;

	int err = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &num);
		if (num >= x && !err) {
			while (num >= x) {
				if (!visited[x]) {
					stack[++top] = x;
					op[op_idx++] = '+';
				}
				x++;
			}
			visited[--x] = 1;
			op[op_idx++] = '-';
			stack[top--] = 0;	// �ʱ�ȭ (top--�� ���൵ ��� ����)
		}
		else if (!err) {
			if (stack[top] != num)	// ������ top�� ���ڿ� �ٸ� ��
				err = 1;
			else {
				while (num < x)	x--;
				visited[x] = 1;
				op[op_idx++] = '-';
				stack[top--] = 0;	// �ʱ�ȭ (top--�� ���൵ ��� ����)
			}
		}
	}
	if (err)
		printf("NO");
	else {
		for (i = 0; i < op_idx; i++)
			printf("%c\n", op[i]);
	}
	return 0;
}