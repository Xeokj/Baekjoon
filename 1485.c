#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int compare(long long* a, long long* b) {
	return *a - *b;
}

int main() {
	int T, i, j, cur;
	long long dot[4][2], dis[6];
	scanf("%d", &T);
	while (T) {
		for (i = 0; i < 4; i++)
			scanf("%lld %lld", &dot[i][0], &dot[i][1]);
		cur = 0;
		for (i = 0; i < 4; i++) {
			for (j = i + 1; j < 4; j++) {
				dis[cur] = ((dot[i][0] - dot[j][0]) * (dot[i][0] - dot[j][0])) + ((dot[i][1] - dot[j][1]) * (dot[i][1] - dot[j][1]));
				cur++;
			}
		}
		qsort(dis, 6, sizeof(long long), compare);
		int cnt = 0;
		for (i = 0; i < 5; i++) {
			if (dis[i] != dis[i + 1])
				cnt++;
		}
		if (cnt == 1)
			printf("1\n");
		else
			printf("0\n");
		T--;
	}
	return 0;
}