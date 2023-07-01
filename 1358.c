#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int main() {
	int W, H, X, Y, P, R, cnt = 0;
	scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);
	R = H / 2;
	while (P--) {
		int x, y;
		scanf("%d %d", &x, &y);
		int dist1 = (x - X) * (x - X) + (y - Y - R) * (y - Y - R);
		int dist2 = (x - X - W) * (x - X - W) + (y - Y - R) * (y - Y - R);
		if (dist1 <= R * R || dist2 <= R * R)
			cnt++;
		else if (x >= X && x <= X + W && y >= Y && y <= Y + H)
			cnt++;
	}
	printf("%d", cnt);
	return 0;
}