#include <bits/stdc++.h>
using namespace std;
int N, K, zero, cnt;
// zero: 내구도가 0인 곳의 개수, cnt: 현재 단계
int A[200], robot[100];
// A: 내구도, robot: 로봇 위치(해당 칸에 로봇이 있으면 1, 없으면 0)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int i, tmp;
	for (i = 0; i < 2 * N; i++)
		cin >> A[i];
	while (zero < K) {
		/* 회전 */
		tmp = A[2 * N - 1];
		for (i = 2 * N - 1; i > 0; i--)
			A[i] = A[i - 1];	// 벨트 회전
		A[0] = tmp;
		for (i = N - 1; i > 0; i--)
			robot[i] = robot[i - 1];	// 로봇 회전
		robot[0] = 0;
		robot[N - 1] = 0;
		// N번 위치에 로봇이 있다면 내려줌

		/* 로봇 옮기기 */
		for (i = N - 2; i >= 0; i--) {
			if (robot[i] && !robot[i + 1] && A[i + 1]) {
				// 로봇을 옮기려면 다음 칸에 로봇이 없어야 하고,
				// 다음 칸의 내구도가 1 이상이어야 함
				robot[i] = 0;
				robot[i + 1] = 1;
				A[i + 1]--;		// 내구도 1 감소
				if (A[i + 1] == 0)
					zero++;	// 옮긴 위치의 내구도가 0이 되는 경우
			}
		}
		robot[N - 1] = 0;
		// N번 위치에 로봇이 있다면 내려줌

		/* 맨 앞 칸에 로봇 올리기 */
		if (A[0]) {
			// 내구도가 1 이상일 때 올림
			robot[0] = 1;
			A[0]--;
			if (A[0] == 0)
				zero++;	// 올린 후 내구도가 0이 되는 경우
		}
		cnt++;
	}
	cout << cnt;
}