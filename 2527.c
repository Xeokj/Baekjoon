#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int test = 4, x1, y1, p1, q1, x2, y2, p2, q2;
	while (test--) {
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &p1, &q1, &x2, &y2, &p2, &q2);
		if (x1 > p2 || y1 > q2 || x2 > p1 || y2 > q1)
			printf("d\n");
		else if ((x1 == p2 && y1 == q2) || (x2 == p1 && y2 == q1) || (x1 == p2 && q1 == y2) || (x2 == p1 && q2 == y1))
			printf("c\n");
		else if (x1 == p2 || y1 == q2 || x2 == p1 || y2 == q1)
			printf("b\n");
		else
			printf("a\n");
	}
	return 0;
}