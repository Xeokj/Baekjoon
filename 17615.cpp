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
			// 첫 공을 기준으로 지금까지 색이 바뀌지 않았을 경우
			if (str[i] == str[0] && st_R) {
				// 빨간색일 때
				red++;	st_R++;
			}
			else if (str[i] == str[0] && st_B) {
				// 파란색일 때
				blue++;	st_B++;
			}
			else {
				// 색이 바뀐 경우
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
	int min = red - st_R;	// 맨 앞으로 R을 다 옮기는 경우
	if (blue - st_B < min)	// 맨 앞으로 B를 다 옮기는 경우
		min = blue - st_B;
	if (red - en_R < min)	// 맨 뒤로 R을 다 옮기는 경우
		min = red - en_R;
	if (blue - en_B < min)	// 맨 뒤로 B를 다 옮기는 경우
		min = blue - en_B;
	cout << min;
}