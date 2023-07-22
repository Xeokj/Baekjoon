#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

int city[50][50];
vector<pair<int, int>> home;	// �� ��ǥ ����
vector<pair<int, int>> chicken;	// ġŲ�� ��ǥ ����
int comb[13];	// ���� ���� �迭
int N, M;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int i, j, tmp;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1)
				home.push_back(make_pair(i, j));
			else if (city[i][j] == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	int ch = chicken.size();	// ġŲ�� ����
	int hm = home.size();	// �� ����

	// ġŲ�� ���� ����
	i = ch - 1;
	tmp = M;
	while (tmp--) {
		comb[i--] = 1;
	}
	
	int dist = 0, ans = 10000;
	do {
		dist = 0;
		for (i = 0; i < hm; i++) {
			// �� ������ ������� ���� ġŲ �� �� ���� ����� ������ �Ÿ� ���� 
			int Min = 100;	// ������� ���� ġŲ�� �� ���� ����� ������ �Ÿ�
			for (j = 0; j < ch; j++) {
				if (comb[j]) {
					Min = min(Min, abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second));
				}
			}
			dist += Min;
		}
		// ��� ������ ������� �ʴ� ġŲ������ �ּ� �Ÿ��� ���� �� ���� ���� �ɷ� ��
		if (dist < ans)
			ans = dist;
	} while (next_permutation(comb, comb + ch));
	cout << ans;
}