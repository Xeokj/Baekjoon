#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

int arr[100001];
char p[100001];

int main() {
	int i, T, n;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", p);
		scanf("%d", &n);

		char garb;
		scanf(" %c", &garb);	// '['�� �Է� �޴� �뵵
		for (i = 0; i < n; i++)
			scanf("%d,", &arr[i]);	// ','�� ����
		scanf(" %c", &garb);	// ']'�� �Է� �޴� �뵵

		// �迭�� ����ִ� ���� front�� rear ���̿� �ִ� ����
		int front = -1, rear = n;
		int len_p = strlen(p), cur = 0;
		for (cur = 0; cur < len_p; cur++) {
			if (p[cur] == 'R') {
				// front�� rear ��ġ ���� �ٲٱ�
				int temp = front;
				front = rear;
				rear = temp;
			}
			else if(p[cur] == 'D') {
				if (front == rear - 1 || rear == front - 1) {
					// front�� rear ������ ���� ������ break
					break;
				}
				else if (front < rear)
					front++;
				else
					front--;
			}
		}
		// cur < len_p�� ���: �迭�� ����ִµ� D�� ���
		if (cur < len_p) {
			// error ����ϰ� ���� �׽�Ʈ ���̽���
			printf("error\n");
			continue;
		}

		printf("[");
		if (front < rear) {
			if (front == rear - 1) {
				// ������ ���� ���� ��
				printf("]\n");
				continue;
			}
			while (front < rear - 2) {
				// ������ ���Ҵ� �ڿ� ','�� ������ �����Ƿ� ���� ó��
				printf("%d,", arr[front + 1]);
				front++;
			}
			// ������ ����
			printf("%d]\n", arr[front + 1]);
		}
		else {
			if (rear == front - 1) {
				// ������ ���� ���� ��
				printf("]\n");
				continue;
			}
			while (rear < front - 2) {
				// ������ ���Ҵ� �ڿ� ','�� ������ �����Ƿ� ���� ó��
				printf("%d,", arr[front - 1]);
				front--;
			}
			// ������ ����
			printf("%d]\n", arr[front - 1]);
		}
	}
}