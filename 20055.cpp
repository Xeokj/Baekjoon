#include <bits/stdc++.h>
using namespace std;
int N, K, zero, cnt;
// zero: �������� 0�� ���� ����, cnt: ���� �ܰ�
int A[200], robot[100];
// A: ������, robot: �κ� ��ġ(�ش� ĭ�� �κ��� ������ 1, ������ 0)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K;
	int i, tmp;
	for (i = 0; i < 2 * N; i++)
		cin >> A[i];
	while (zero < K) {
		/* ȸ�� */
		tmp = A[2 * N - 1];
		for (i = 2 * N - 1; i > 0; i--)
			A[i] = A[i - 1];	// ��Ʈ ȸ��
		A[0] = tmp;
		for (i = N - 1; i > 0; i--)
			robot[i] = robot[i - 1];	// �κ� ȸ��
		robot[0] = 0;
		robot[N - 1] = 0;
		// N�� ��ġ�� �κ��� �ִٸ� ������

		/* �κ� �ű�� */
		for (i = N - 2; i >= 0; i--) {
			if (robot[i] && !robot[i + 1] && A[i + 1]) {
				// �κ��� �ű���� ���� ĭ�� �κ��� ����� �ϰ�,
				// ���� ĭ�� �������� 1 �̻��̾�� ��
				robot[i] = 0;
				robot[i + 1] = 1;
				A[i + 1]--;		// ������ 1 ����
				if (A[i + 1] == 0)
					zero++;	// �ű� ��ġ�� �������� 0�� �Ǵ� ���
			}
		}
		robot[N - 1] = 0;
		// N�� ��ġ�� �κ��� �ִٸ� ������

		/* �� �� ĭ�� �κ� �ø��� */
		if (A[0]) {
			// �������� 1 �̻��� �� �ø�
			robot[0] = 1;
			A[0]--;
			if (A[0] == 0)
				zero++;	// �ø� �� �������� 0�� �Ǵ� ���
		}
		cnt++;
	}
	cout << cnt;
}