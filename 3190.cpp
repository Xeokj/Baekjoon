#include <bits/stdc++.h>
using namespace std;
int board[101][101], dir[101][101];
// board: 현재 뱀의 몸을 표시, dir: head가 이동한 방향을 나타냄
// head는 dir에 이동한 방향을 그리며 이동

struct _Head {
	int stat;	// head의 이동 방향
	int hy;	// head의 y좌표
	int hx;	// head의 x좌표
} H;
// stat = 1이면 오른쪽, 2이면 아래, 3이면 왼쪽, 4이면 위로 이동

struct _Tail {
	int ty;	// tail의 y좌표
	int tx;	// tail의 x좌표
} T;

int N, K, L, t = 1;	// t: time
bool br;	// 벽을 만나거나 자기 자신과 부딪혔을 때 1
vector<pair<int, char>> ch;
void travel();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, y, x;
	cin >> N >> K;
	while (K--) {
		cin >> y >> x;
		board[y][x] = -1;	// 사과는 -1로 표시
	}
	cin >> L;
	int X;
	char C;
	for (i = 0; i < L; i++) {
		cin >> X >> C;
		ch.push_back(make_pair(X, C));
	}
	// 초기화
	board[1][1] = 1;	dir[1][1] = 1;
	H.hy = 1;	H.hx = 1;	H.stat = 1;
	T.ty = 1;	T.tx = 1;
	for (i = 0; i < L; i++) {
		while (t <= ch[i].first) {
			travel();
			if (br == 1)
				break;
		}
		if (br == 1)
			break;
		// 위의 반복문을 돌고나면 t > X가 됨
		if (ch[i].second == 'D') {
			// 오른쪽으로 회전
			H.stat++;
			if (H.stat == 5)
				H.stat = 1;
		}
		else if (ch[i].second == 'L') {
			// 왼쪽으로 회전
			H.stat--;
			if (H.stat == 0)
				H.stat = 4;
		}
		dir[H.hy][H.hx] = H.stat;	// 바뀐 head의 상태로 갱신
	}
	while (!br)
		travel();
	cout << t;
}

void travel() {
	int ny = H.hy, nx = H.hx;
	// head의 방향에 따라 이동시켜줌
	if (H.stat == 1)	nx++;
	else if (H.stat == 2)	ny++;
	else if (H.stat == 3)	nx--;
	else if (H.stat == 4)	ny--;
	if (ny <= 0 || ny > N || nx <= 0 || nx > N) {
		// 벽에 부딪혔을 때
		br = 1;
		return;
	}
	if (board[ny][nx] == 1) {
		// 자기 자신에게 부딪혔을 때
		br = 1;
		return;
	}
	// 앞으로 나아갈 수 있을 때
	dir[ny][nx] = H.stat;	// 이동할 위치에 현재 head의 방향을 표시
	H.hy = ny;	// head y좌표 업데이트
	H.hx = nx;	// head x좌표 업데이트
	t++;	// 1초 증가
	if (board[ny][nx] == -1) {
		// 이동할 위치에 사과가 있다면 head만 이동시켜주고 return
		board[ny][nx] = 1;
		return;
	}
	board[ny][nx] = 1;	// head의 바뀐 위치 표시
	int cury = T.ty, curx = T.tx;	// 현재 tail의 위치
	// 앞서 head가 그렸던 방향으로 tail 이동시켜줌
	if (dir[T.ty][T.tx] == 1)	T.tx++;
	else if (dir[T.ty][T.tx] == 2)	T.ty++;
	else if (dir[T.ty][T.tx] == 3)	T.tx--;
	else if (dir[T.ty][T.tx] == 4)	T.ty--;
	dir[cury][curx] = 0;	// tail 부분 지워줌
	board[cury][curx] = 0;	// tail 부분 지워줌	
}