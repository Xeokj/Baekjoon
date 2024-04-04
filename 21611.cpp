#include <bits/stdc++.h>
using namespace std;
// 백준 21611번: 마법사 상어와 블리자드 (골드 1)

int N, M, d, s;
int ans1, ans2, ans3;
int board[49][49];
int dy[4] = { 1,0,-1,0 };	// 문제에 제시된 위,아래,왼쪽,오른쪽 방향 순서로
int dx[4] = { 0,1,0,-1 };
vector<pair<int, int>> arr;	// 2차원 배열을 1차원으로 저장
vector<pair<int, int>> order;	// 명령어를 저장
void blizzard(int cur);	// 블리자드 마법
bool blast();	// 폭발
void transform();	// 구슬 변화

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

	arr.push_back({ 0,0 });	// index = 0은 (0,0)으로 채움
	int r = N / 2;
	int length = 2;
	int cy = N / 2, cx = N / 2;	// 시작점
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
	arr.push_back({ 0,0 });	// 마지막은 (0,0)을 넣어줌
	for (int cur = 0; cur < M; cur++) {
		blizzard(cur);
		while (blast());	// 더이상 폭발하는 구슬이 없을 때까지 반복
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
	bool flg = 0;	// 폭발을 안 한다고 가정
	int num = 0, top = 0;
	arr[1].second = 1;
	for (int i = 1; i <= N * N; i++) {
		if (arr[i].first == 0 && i != N * N)
			continue;
		if (arr[i].first == arr[top].first)
			arr[i].second = arr[top].second + 1;
		else {
			// arr[i].first와 다른 것이 나올 때까지 stack에서 pop함
			if (arr[top].second >= 4) {
				// top의 second가 4 이상일 때 (폭발할 수 있을 때)
				if (arr[top].first == 1)
					ans1 += arr[top].second;
				else if (arr[top].first == 2)
					ans2 += arr[top].second;
				else if (arr[top].first == 3)
					ans3 += arr[top].second;
				top = top - arr[top].second;
				// top에서 top의 second 만큼 빼서 top 위치를 되돌림 (폭발)
				flg = 1;	// 폭발을 함으로 표시
			}
			else
				arr[i].second = 1;	// top의 second가 4보다 작아서 폭발 불가할 때
		}
		top++;	// top을 한 칸 증가
		arr[top].first = arr[i].first;	// top의 위치에 값을 옮김
		arr[top].second = arr[i].second;	// top의 위치에 값을 옮김
	}
	for (int i = top + 1; i <= N * N; i++) {
		// 위의 for문에서 top이 N * N 번째 칸까지 도달하지 못했을 때 그 남은 칸들을 0으로 채워줌
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