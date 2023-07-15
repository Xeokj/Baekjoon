#include <bits/stdc++.h>

int arr[128][128];
int white, blue;
void paper(int N, int sti, int stj);

int main() {
	int N, i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);

	paper(N, 0, 0);
	printf("%d\n%d", white, blue);
}

void paper(int N, int sti, int stj) {
	for (int i = sti; i < sti + N; i++) {
		for (int j = stj; j < stj + N; j++) {
			if (arr[i][j] != arr[sti][stj]) {
				paper(N / 2, sti, stj);
				paper(N / 2, sti + N / 2, stj);
				paper(N / 2, sti, stj + N / 2);
				paper(N / 2, sti + N / 2, stj + N / 2);
				return;
			}
		}
	}
	if (arr[sti][stj])
		blue++;
	else
		white++;
}