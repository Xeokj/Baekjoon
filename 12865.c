#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max(a,b) ((a)>(b)?(a):(b))

int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);

	int* arr = (int*)calloc(K + 1, sizeof(int));
	int* prev = (int*)calloc(K + 1, sizeof(int));
	int* weight = (int*)calloc(N, sizeof(int));
	int* value = (int*)calloc(N, sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d %d", &weight[i], &value[i]);
	}

	int prev_weight;
	for (i = 0; i < N; i++) {
		for (j = 1; j <= K; j++) {
			prev_weight = j - weight[i];	// 물건을 담기 전의 무게
			if (prev_weight < 0)	// 물건을 담을 수 없을 때
				arr[j] = prev[j];
			else
				arr[j] = max(prev[j], prev[prev_weight] + value[i]);
		}
		/* prev에 현재 행의 값 저장 */
		for (j = 1; j <= K; j++)
			prev[j] = arr[j];
	}
	printf("%d", arr[K]);
	free(arr);
	free(prev);
	free(weight);
	free(value);
	return 0;
}