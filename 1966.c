#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int prior[10];	// �켱 ����

int main() {
	int T;
	scanf("%d", &T);
	while(T) {
		int N, find, max = 0;
		scanf("%d %d", &N, &find);
		int* queue = (int*)calloc(N, sizeof(int));

		int cur = -1, cnt = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", &queue[i]);
			prior[queue[i]]++;
			if (queue[i] > max)
				max = queue[i];
		}

		while (queue[find] != -1) {
			cur++;	// Ŀ�� �� ĭ �̵�

			// cur�� �迭�� ������ �ʰ��ϸ� �� ������ ������
			cur %= N;
			// cur�� ����Ű�� ������ ���� �߿䵵 ���� ������ �����ؾ� �� ��
			if (queue[cur] == max) {
				cnt++;
				queue[cur] = -1;
				prior[max]--;
				
				// ������ ������ �߿䵵�� ���� ������ ���̻� ���� ��
				if (prior[max] == 0) {
					max--;
					while (!prior[max]) max--;
				}
			}
		}
		printf("%d\n", cnt);
		free(queue);
		memset(prior, 0, sizeof(int) * 10);
		T--;
	}
	return 0;
}