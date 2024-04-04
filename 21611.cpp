#include <bits/stdc++.h>
using namespace std;
// ���� 21611��: ������ ���� ���ڵ� (��� 1)

int N, M, d, s;
int ans1, ans2, ans3;
int board[49][49];
int dy[4] = { 1,0,-1,0 };	// ������ ���õ� ��,�Ʒ�,����,������ ���� ������
int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> arr;	// 2���� �迭�� 1�������� ����
vector<pair<int, int>> order;	// ��ɾ ����
void blizzard(int cur);	// ���ڵ� ����
bool blast();	// ����
void transform();	// ���� ��ȭ

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> board[i][j];
	for (i = 0; i < M; i++) {
		cin >> d >> s;
		order.push_back({ d,s });
	}

	arr.push_back({ 0,0 });	// index = 0�� (0,0)���� ä��
	int r = N / 2;
	int length = 2;
	int cy = N / 2, cx = N / 2;	// ������
	while (length < N) {
		cy--;
		cx--;
		for (int dir = 0; dir < 4; dir++) {
			for (i = 0; i < length; i++) {
				cy += dy[dir];
				cx += dx[dir];
				arr.push_back({ board[cy][cx], 0 });
			}
		}
		length += 2;
	}
	arr.push_back({ 0,0 });	// �������� (0,0)�� �־���
	for (int cur = 0; cur < M; cur++) {
		blizzard(cur);
		while (blast());	// ���̻� �����ϴ� ������ ���� ������ �ݺ�
		transform();
	}
	cout << ans1 + 2 * ans2 + 3 * ans3;
	return 0;
}

void blizzard(int cur) {
	int k;
	if (order[cur].first == 1) {
		for (k = 1; k <= order[cur].second; k++) {
			arr[4 * k * k + 3 * k].first = 0;
			arr[4 * k * k + 3 * k].second = 0;
		}
	}
	else if (order[cur].first == 2) {
		for (k = 1; k <= order[cur].second; k++) {
			arr[4 * k * k - k].first = 0;
			arr[4 * k * k - k].second = 0;
		}
	}
	else if (order[cur].first == 3) {
		for (k = 1; k <= order[cur].second; k++) {
			arr[4 * k * k - 3 * k].first = 0;
			arr[4 * k * k - 3 * k].second = 0;
		}
	}
	else if (order[cur].first == 4) {
		for (k = 1; k <= order[cur].second; k++) {
			arr[4 * k * k + k].first = 0;
			arr[4 * k * k + k].second = 0;
		}
	}
}

bool blast() {
	bool flg = 0;	// ������ �� �Ѵٰ� ����
	int num = 0, top = 0;
	arr[1].second = 1;
	for (int i = 1; i <= N * N; i++) {
		if (arr[i].first == 0 && i != N * N)
			continue;
		if (arr[i].first == arr[top].first)
			arr[i].second = arr[top].second + 1;
		else {
			// arr[i].first�� �ٸ� ���� ���� ������ stack���� pop��
			if (arr[top].second >= 4) {
				// top�� second�� 4 �̻��� �� (������ �� ���� ��)
				if (arr[top].first == 1)
					ans1 += arr[top].second;
				else if (arr[top].first == 2)
					ans2 += arr[top].second;
				else if (arr[top].first == 3)
					ans3 += arr[top].second;
				top = top - arr[top].second;
				// top���� top�� second ��ŭ ���� top ��ġ�� �ǵ��� (����)
				flg = 1;	// ������ ������ ǥ��
			}
			else
				arr[i].second = 1;	// top�� second�� 4���� �۾Ƽ� ���� �Ұ��� ��
		}
		top++;	// top�� �� ĭ ����
		arr[top].first = arr[i].first;	// top�� ��ġ�� ���� �ű�
		arr[top].second = arr[i].second;	// top�� ��ġ�� ���� �ű�
	}
	for (int i = top + 1; i <= N * N; i++) {
		// ���� for������ top�� N * N ��° ĭ���� �������� ������ �� �� ���� ĭ���� 0���� ä����
		arr[i].first = 0;
		arr[i].second = 0;
	}
	return flg;
}

void transform() {
	int* temp = (int*)calloc(N * N + 2, sizeof(int));
	int cur = 1;
	for (int i = 1; i < N * N; i++) {
		if (arr[i].first != arr[i + 1].first) {
			temp[cur] = arr[i].second;
			cur++;
			if (cur >= N * N)
				break;
			temp[cur] = arr[i].first;
			cur++;
			if (cur > N * N)
				break;
		}
	}
	arr.clear();
	arr.push_back({ 0,0 });
	for (int i = 1; i < N * N; i++)
		arr.push_back({ temp[i],0 });
	arr.push_back({ 0,0 });
	free(temp);
}