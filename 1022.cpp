#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
// ���� 1022��: �ҿ뵹�� ���ڰ� ����ϱ� (��� 3)

int arr[50][5];
int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int m = max({ abs(r1),abs(c1),abs(r2),abs(c2) });
	r1 += m;
	c1 += m;
	r2 += m;
	c2 += m;
	// ������ (2m+1)*(2m+1)¥�� �ҿ뵹�� ����
	// 1,��,1,��,2,��,2,��,3,��,3,��,4,��,4,��,5,��,5,��,6,��,6, ... ����
	int num = 1, cnt = 1, dir = 0;
	// num: �ҿ뵹�̿� �� ����, cnt: �̵� Ƚ��, dir: ����
	int r = m, c = m;		// ������ (m, m)���� ����
	while (num <= (2 * m + 1) * (2 * m + 1)) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < cnt; j++) {
				// j�� ����ؼ� 1ĭ ��ŭ, 2ĭ ��ŭ, 3ĭ ��ŭ, ... �̷��� �����ؾ���
				// ���� ���� ���ڸ� �迭�� ������
				if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
					arr[r - r1][c - c1] = num;
				num++;	// ���� ����
				r += dr[dir];
				c += dc[dir];
			}
			dir = (dir + 1) % 4;
		}
		cnt++;
	}
	int l = max({ arr[0][0],arr[r2 - r1][0],arr[0][c2 - c1],arr[r2 - r1][c2 - c1] });
	int w = 0;	// w: �ڸ���
	while (l) {
		w++;
		l /= 10;
	}
	// (r1+m, c1+m)���� (r2+m, c2+m)���� ����ϱ�
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			cout << setw(w) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	// ����
	// ���� ū������ �ڸ����� digit, ����ؾ��ϴ� ���� num�̶�� �ϸ�,
	// printf("%*d ",digit, num);���� ����ϸ� �˴ϴ�.
	return 0;
}
