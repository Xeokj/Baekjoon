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
		scanf(" %c", &garb);	// '['를 입력 받는 용도
		for (i = 0; i < n; i++)
			scanf("%d,", &arr[i]);	// ','로 구분
		scanf(" %c", &garb);	// ']'를 입력 받는 용도

		// 배열에 들어있는 수는 front와 rear 사이에 있는 수임
		int front = -1, rear = n;
		int len_p = strlen(p), cur = 0;
		for (cur = 0; cur < len_p; cur++) {
			if (p[cur] == 'R') {
				// front와 rear 위치 서로 바꾸기
				int temp = front;
				front = rear;
				rear = temp;
			}
			else if(p[cur] == 'D') {
				if (front == rear - 1 || rear == front - 1) {
					// front와 rear 사이의 수가 없으면 break
					break;
				}
				else if (front < rear)
					front++;
				else
					front--;
			}
		}
		// cur < len_p인 경우: 배열이 비어있는데 D한 경우
		if (cur < len_p) {
			// error 출력하고 다음 테스트 케이스로
			printf("error\n");
			continue;
		}

		printf("[");
		if (front < rear) {
			if (front == rear - 1) {
				// 사이의 수가 없을 때
				printf("]\n");
				continue;
			}
			while (front < rear - 2) {
				// 마지막 원소는 뒤에 ','를 붙이지 않으므로 따로 처리
				printf("%d,", arr[front + 1]);
				front++;
			}
			// 마지막 원소
			printf("%d]\n", arr[front + 1]);
		}
		else {
			if (rear == front - 1) {
				// 사이의 수가 없을 때
				printf("]\n");
				continue;
			}
			while (rear < front - 2) {
				// 마지막 원소는 뒤에 ','를 붙이지 않으므로 따로 처리
				printf("%d,", arr[front - 1]);
				front--;
			}
			// 마지막 원소
			printf("%d]\n", arr[front - 1]);
		}
	}
}