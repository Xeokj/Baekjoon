#include <bits/stdc++.h>
using namespace std;
int N, M;
int city[201][201], parent[201];
void merge(int p, int root);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int num, i, j;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			cin >> city[i][j];
		}
		parent[i] = i;	// �θ� �ڱ� �ڽ����� �ʱ�ȭ
	}
	for (i = 1; i <= N; i++) {
		// �θ� �ڱ� �ڽ��� ���� root�� �Ͽ� DFS�� �ڽĵ��� �θ� root�� ����
		if (parent[i] == i)
			merge(i, i);
	}
	int start, flag = 0;
	cin >> start;
	for (i = 1; i < M; i++) {
		cin >> num;
		if (parent[num] != parent[start])
			flag = 1;
	}
	if (flag)
		cout << "NO";
	else
		cout << "YES";
}

void merge(int p, int root) {
	for (int i = 1; i <= N; i++) {
		// root�� ����� ��� ������ �θ� root�� �����
		if (city[p][i] && parent[i] == i) {
			parent[i] = root;
			merge(i, root);
		}
	}
}