#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int A[11], op[10], isused[10];
int N, result;
int min = 1000000000, max = -1000000000;
void calculate(int cur);

int main() {
	int i, j, temp;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);
	j = 0;
	result = A[0];
	for (i = 1; i <= 4; i++) {
		scanf("%d", &temp);
		// +는 1, -는 2, *는 3, /는 4
		while (temp) {
			op[j++] = i;
			temp--;
		}
	}
	calculate(0);
	printf("%d\n%d", max, min);
	return 0;
}

void calculate(int cur) {
	if (cur == N - 1) {
		if (result > max)
			max = result;
		if (result < min)
			min = result;
	}
	for (int i = 0; i < N - 1; i++) {
		if (!isused[i]) {
			int tmp = result;
			if (op[i] == 1)
				result += A[cur + 1];
			else if (op[i] == 2)
				result -= A[cur + 1];
			else if (op[i] == 3)
				result *= A[cur + 1];
			else if (op[i] == 4)
				result /= A[cur + 1];
			isused[i] = 1;
			calculate(cur + 1);
			result = tmp;
			isused[i] = 0;
		}
	}
}