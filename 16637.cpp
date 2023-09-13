#include <bits/stdc++.h>
using namespace std;
// 백준 16637번: 괄호 추가하기 (골드 3)
int N, ans = INT_MIN;
string s;
void cal(int cur, int res);
// cur은 s에서 현재 가리키는 index를 의미
// cur + 2 < N이면 s[cur]를 기점으로 하는 괄호를 만들 수 있음
// 1) s[cur]를 기점으로 괄호를 만들 수 있다면 먼저 괄호를 만들어 계산
// 2) 그 후 s[cur]를 괄호에 포함하지 않는 경우로 계산

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	cal(0, 0);
	cout << ans;
}

void cal(int cur, int res) {
	if (cur > N) {
		if (res > ans)
			ans = res;
		return;
	}
	if (cur + 2 < N) {
		// 괄호를 만들 수 있을 때
		int tmp1, tmp2, tres;
		// tmp1: 만들 괄호 안에서 첫 번째 수
		// tmp2: 만들 괄호 안에서 두 번째 수
		// tres: 괄호를 계산한 결과
		tmp1 = (s[cur] - '0');
		tmp2 = (s[cur + 2] - '0');
		if (s[cur + 1] == '+')
			tres = tmp1 + tmp2;
		else if (s[cur + 1] == '-')
			tres = tmp1 - tmp2;
		else if (s[cur + 1] == '*')
			tres = tmp1 * tmp2;
		if (cur == 0)
			cal(4, tres);	// cur = 0이면 s[cur]앞에 아무 연산자도 없으므로
		else {
			// cur > 0일 때
			if (s[cur - 1] == '+')
				cal(cur + 4, res + tres);
			else if (s[cur - 1] == '-')
				cal(cur + 4, res - tres);
			else if (s[cur - 1] == '*')
				cal(cur + 4, res * tres);
		}	
	}
	// 괄호를 만들지 않는 경우
	int num = s[cur] - '0';
	if (cur == 0)
		cal(2, num);
	else {
		if (s[cur - 1] == '+')
			cal(cur + 2, res + num);
		else if (s[cur - 1] == '-')
			cal(cur + 2, res - num);
		else if (s[cur - 1] == '*')
			cal(cur + 2, res * num);
	}
}