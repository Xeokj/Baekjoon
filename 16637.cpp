#include <bits/stdc++.h>
using namespace std;
// ���� 16637��: ��ȣ �߰��ϱ� (��� 3)
int N, ans = INT_MIN;
string s;
void cal(int cur, int res);
// cur�� s���� ���� ����Ű�� index�� �ǹ�
// cur + 2 < N�̸� s[cur]�� �������� �ϴ� ��ȣ�� ���� �� ����
// 1) s[cur]�� �������� ��ȣ�� ���� �� �ִٸ� ���� ��ȣ�� ����� ���
// 2) �� �� s[cur]�� ��ȣ�� �������� �ʴ� ���� ���

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
		// ��ȣ�� ���� �� ���� ��
		int tmp1, tmp2, tres;
		// tmp1: ���� ��ȣ �ȿ��� ù ��° ��
		// tmp2: ���� ��ȣ �ȿ��� �� ��° ��
		// tres: ��ȣ�� ����� ���
		tmp1 = (s[cur] - '0');
		tmp2 = (s[cur + 2] - '0');
		if (s[cur + 1] == '+')
			tres = tmp1 + tmp2;
		else if (s[cur + 1] == '-')
			tres = tmp1 - tmp2;
		else if (s[cur + 1] == '*')
			tres = tmp1 * tmp2;
		if (cur == 0)
			cal(4, tres);	// cur = 0�̸� s[cur]�տ� �ƹ� �����ڵ� �����Ƿ�
		else {
			// cur > 0�� ��
			if (s[cur - 1] == '+')
				cal(cur + 4, res + tres);
			else if (s[cur - 1] == '-')
				cal(cur + 4, res - tres);
			else if (s[cur - 1] == '*')
				cal(cur + 4, res * tres);
		}	
	}
	// ��ȣ�� ������ �ʴ� ���
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