#include <bits/stdc++.h>
#define MAX_H 256
using namespace std;
int board[MAX_H + 1], lower[MAX_H + 1], higher[MAX_H + 1];
// lower[i]: ���̸� i�� ���� �� ä���� �� ����� ����
// higher[i]: ���̸� i�� ���� �� �����ؾ� �� ����� ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, B, num, i;
	cin >> N >> M >> B;
	for (i = 0; i < N * M; i++) {
		cin >> num;
		board[num]++;
	}
	int low = board[0];	// low: ���� ���̺��� �� ���� ��ġ�� ����
	for (i = 1; i <= 256; i++) {
		lower[i] = lower[i - 1] + low;
		low += board[i];
	}
	int high = board[MAX_H];	// high: ���� ���̺��� �� ���� ��ġ�� ����
	for (i = MAX_H - 1; i >= 0; i--) {
		higher[i] = higher[i + 1] + high;
		high += board[i];
	}
	int ans_t = higher[0] * 2, ans_h = 0;
	for (i = 1; i <= MAX_H; i++) {
		if (lower[i] <= B + higher[i]) {
			// ä�����ϴ� ����� ������ ���� ���� �ִ� ��� �������� �� ���ų� ���ƾ� ��
			int t = higher[i] * 2 + lower[i];
			if (t <= ans_t) {
				ans_t = t;
				ans_h = i;
			}
		}
		else
			break;
	}
	cout << ans_t << ' ' << ans_h;
}