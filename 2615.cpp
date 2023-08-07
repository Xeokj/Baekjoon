#include <bits/stdc++.h>
#define MAX 19
using namespace std;
int board[MAX][MAX];
int vert(int y, int x, int num);
int horz(int y, int x, int num);
int diagr(int y, int x, int num);
int diagl(int y, int x, int num);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j, num;
	for (i = 0; i < MAX; i++)
		for (j = 0; j < MAX; j++)
			cin >> board[i][j];
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			if (board[i][j]) {
				num = board[i][j];
				if (vert(i, j, num)) {
					cout << num << "\n" << i + 1 << ' ' << j + 1;
					return 0;
				}
				if (horz(i, j, num)) {
					cout << num << "\n" << i + 1 << ' ' << j + 1;
					return 0;
				}
				if (diagr(i, j, num)) {
					cout << num << "\n" << i + 1 << ' ' << j + 1;
					return 0;
				}
				if (diagl(i, j, num)) {
					cout << num << "\n" << i + 5 << ' ' << j - 3;
					return 0;
				}
			}
		}
	}
	cout << 0;
}

int vert(int y, int x, int num) {
	int ny = y - 1, cnt = 1;
	while (ny >= 0) {
		if (board[ny][x] == num) {
			cnt++;
			ny--;
		}
		else
			break;
	}
	ny = y + 1;
	while (ny < MAX) {
		if (board[ny][x] == num) {
			cnt++;
			ny++;
		}
		else
			break;
	}
	if (cnt == 5)
		return 1;
	else
		return 0;
}

int horz(int y, int x, int num) {
	int nx = x - 1, cnt = 1;
	while (nx >= 0) {
		if (board[y][nx] == num) {
			cnt++;
			nx--;
		}
		else
			break;
	}
	nx = x + 1;
	while (nx < MAX) {
		if (board[y][nx] == num) {
			cnt++;
			nx++;
		}
		else
			break;
	}
	if (cnt == 5)
		return 1;
	else
		return 0;
}

int diagr(int y, int x, int num) {
	int ny = y - 1, nx = x - 1, cnt = 1;
	while (ny >= 0 && nx >= 0) {
		if (board[ny][nx] == num) {
			cnt++;
			ny--;
			nx--;
		}
		else
			break;
	}
	ny = y + 1;
	nx = x + 1;
	while (ny < MAX && nx < MAX) {
		if (board[ny][nx] == num) {
			cnt++;
			ny++;
			nx++;
		}
		else
			break;
	}
	if (cnt == 5)
		return 1;
	else
		return 0;
}

int diagl(int y, int x, int num) {
	int ny = y - 1, nx = x + 1, cnt = 1;
	while (ny >= 0 && nx < MAX) {
		if (board[ny][nx] == num) {
			cnt++;
			ny--;
			nx++;
		}
		else
			break;
	}
	ny = y + 1;
	nx = x - 1;
	while (ny < MAX && nx >= 0) {
		if (board[ny][nx] == num) {
			cnt++;
			ny++;
			nx--;
		}
		else
			break;
	}
	if (cnt == 5)
		return 1;
	else
		return 0;
}