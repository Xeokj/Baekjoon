#include <bits/stdc++.h>
using namespace std;
// ���� 1759��: ��ȣ ����� (��� 5)
int L, C;
vector<char> alpha;
char ans[15];
void backtr(int cur, int n, int vowel, int conso);
// cur: alpha���� ����Ű�� �ִ� Ŀ��, n: ans�� ����� ����
// vowel: ans�� ����� ������ ����, conso: ans�� ����� ������ ����

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		alpha.push_back(a);
	}
	// �Է¹��� ���ĺ����� �������� ����
	sort(alpha.begin(), alpha.end());
	backtr(0, 0, 0, 0);
}

void backtr(int cur, int n, int vowel, int conso) {
	// �ϴ� L���� ���ڿ��� ���� �� ���ǿ� �����ϸ� ���
	if (n == L) {
		if (!vowel || conso < 2)
			return;	// ������ ������ �ּ� ������ �������� ���� ���
		for (int i = 0; i < L; i++)
			cout << ans[i];
		cout << "\n";
		return;
	}
	for (int i = cur; i < C; i++) {
		ans[n] = alpha[i];
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
			backtr(i + 1, n + 1, vowel + 1, conso);	// ������ ��
		else
			backtr(i + 1, n + 1, vowel, conso + 1);	// ������ ��
	}
}