#include <bits/stdc++.h>
#define MAX 51
using namespace std;

char S[MAX];
int len[MAX], K[MAX];
// len: ���� ���� ���� �迭, K: ��ȣ �� ����
// �� ���� ��ȣ������ ���� index ����
// ��ȣ�� ���Ե��� ���� ���� �ٱ� ���ڸ� index = 0, �� ���� ��ȣ �ȿ� �ִ� ���� index = 1, ...  

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> S;
	int i, cur = 0, num = 0, size = strlen(S);
	for (i = 0; i < size; i++) {
		if (S[i] == '(') {
			len[cur]--;	// ��ȣ ���� K�� ���̿� ���Խ�Ű�� �����Ƿ�
			cur++;
			K[cur] = num;	// �Ʒ� else ������ ������ ���ڸ� ��ȣ �� ���ڷ� Ȯ��
		}
		else if (S[i] == ')') {
			int temp = len[cur] * K[cur];
			len[cur] = 0;	// �ش� ��ȣ�� �������Ƿ� 0���� �ʱ�ȭ
			cur--;
			len[cur] += temp;
		}
		else {
			len[cur]++;
			num = S[i] - '0';	// ��ȣ �� ������ �� �����Ƿ� �ϴ� ����
		}
	}
	cout << len[0];
}