#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, flag = 0, red = 0, blue = 0;
	cin >> N;
	string str;
	cin >> str;

	int st_R = 0, st_B = 0, en_R = 0, en_B = 0;
	if (str[0] == 'R') {
		red++;	st_R++;
	}
	else {
		blue++;	st_B++;
	}

	for (int i = 1; i < N; i++) {
		if (!flag) {
			// ù ���� �������� ���ݱ��� ���� �ٲ��� �ʾ��� ���
			if (str[i] == str[0] && st_R) {
				// �������� ��
				red++;	st_R++;
			}
			else if (str[i] == str[0] && st_B) {
				// �Ķ����� ��
				blue++;	st_B++;
			}
			else {
				// ���� �ٲ� ���
				if (str[i] == 'R') {
					en_R++;	red++;
				}
				else {
					en_B++; blue++;
				}
				flag = 1;
			}
		}
		else {
			if (str[i] == 'R') {
				en_B = 0;
				en_R++;	red++;
			}
			else {
				en_R = 0;
				en_B++;	blue++;
			}
		}
	}
	int min = red - st_R;	// �� ������ R�� �� �ű�� ���
	if (blue - st_B < min)	// �� ������ B�� �� �ű�� ���
		min = blue - st_B;
	if (red - en_R < min)	// �� �ڷ� R�� �� �ű�� ���
		min = red - en_R;
	if (blue - en_B < min)	// �� �ڷ� B�� �� �ű�� ���
		min = blue - en_B;
	cout << min;
}