#include <bits/stdc++.h>
using namespace std;
int board[101][101], dir[101][101];
// board: ���� ���� ���� ǥ��, dir: head�� �̵��� ������ ��Ÿ��
// head�� dir�� �̵��� ������ �׸��� �̵�

struct _Head {
	int stat;	// head�� �̵� ����
	int hy;	// head�� y��ǥ
	int hx;	// head�� x��ǥ
} H;
// stat = 1�̸� ������, 2�̸� �Ʒ�, 3�̸� ����, 4�̸� ���� �̵�

struct _Tail {
	int ty;	// tail�� y��ǥ
	int tx;	// tail�� x��ǥ
} T;

int N, K, L, t = 1;	// t: time
bool br;	// ���� �����ų� �ڱ� �ڽŰ� �ε����� �� 1
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
		board[y][x] = -1;	// ����� -1�� ǥ��
	}
	cin >> L;
	int X;
	char C;
	for (i = 0; i < L; i++) {
		cin >> X >> C;
		ch.push_back(make_pair(X, C));
	}
	// �ʱ�ȭ
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
		// ���� �ݺ����� ������ t > X�� ��
		if (ch[i].second == 'D') {
			// ���������� ȸ��
			H.stat++;
			if (H.stat == 5)
				H.stat = 1;
		}
		else if (ch[i].second == 'L') {
			// �������� ȸ��
			H.stat--;
			if (H.stat == 0)
				H.stat = 4;
		}
		dir[H.hy][H.hx] = H.stat;	// �ٲ� head�� ���·� ����
	}
	while (!br)
		travel();
	cout << t;
}

void travel() {
	int ny = H.hy, nx = H.hx;
	// head�� ���⿡ ���� �̵�������
	if (H.stat == 1)	nx++;
	else if (H.stat == 2)	ny++;
	else if (H.stat == 3)	nx--;
	else if (H.stat == 4)	ny--;
	if (ny <= 0 || ny > N || nx <= 0 || nx > N) {
		// ���� �ε����� ��
		br = 1;
		return;
	}
	if (board[ny][nx] == 1) {
		// �ڱ� �ڽſ��� �ε����� ��
		br = 1;
		return;
	}
	// ������ ���ư� �� ���� ��
	dir[ny][nx] = H.stat;	// �̵��� ��ġ�� ���� head�� ������ ǥ��
	H.hy = ny;	// head y��ǥ ������Ʈ
	H.hx = nx;	// head x��ǥ ������Ʈ
	t++;	// 1�� ����
	if (board[ny][nx] == -1) {
		// �̵��� ��ġ�� ����� �ִٸ� head�� �̵������ְ� return
		board[ny][nx] = 1;
		return;
	}
	board[ny][nx] = 1;	// head�� �ٲ� ��ġ ǥ��
	int cury = T.ty, curx = T.tx;	// ���� tail�� ��ġ
	// �ռ� head�� �׷ȴ� �������� tail �̵�������
	if (dir[T.ty][T.tx] == 1)	T.tx++;
	else if (dir[T.ty][T.tx] == 2)	T.ty++;
	else if (dir[T.ty][T.tx] == 3)	T.tx--;
	else if (dir[T.ty][T.tx] == 4)	T.ty--;
	dir[cury][curx] = 0;	// tail �κ� ������
	board[cury][curx] = 0;	// tail �κ� ������	
}