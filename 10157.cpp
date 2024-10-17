#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
using namespace std;
// 백준 10157번: 자리배정 (실버 3)

bool seat[1000][1000];
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };
// 문제와 다르게 (0,0)에서 출발해 반시계방향으로 이동

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r, c, k;
	cin >> c >> r >> k;
	if (k == 1)
		cout << 1 << " " << 1;
	else if (r * c < k)
		cout << 0;
	else {
		int cr = 0, cc = 0;	// 출발 지점
		int cnt = 1;
		int dir = 0;
		seat[cr][cc] = 1;
		while (1) {
			if (cr + dr[dir] < 0 || cr + dr[dir] >= r || cc + dc[dir] < 0 || cc + dc[dir] >= c)
				dir = (dir + 1) % 4;	// 범위 초과할 때
			else if (seat[cr + dr[dir]][cc + dc[dir]])
				dir = (dir + 1) % 4;	// 이미 방문한 곳일 때
			cr += dr[dir];
			cc += dc[dir];
			cnt++;
			seat[cr][cc] = 1;
			if (cnt == k) {
				cout << cc + 1 << " " << cr + 1;
				break;
			}
		}
	}
	return 0;
}
