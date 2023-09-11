#include <bits/stdc++.h>
using namespace std;
// virus: 입력으로 들어오는 바이러스의 좌표 저장
// vacant: 입력으로 들어오는 0인 부분 좌표 저장
/*
	[벽을 세우는 매커니즘]
	마지막 3개의 항을 제외한 모든 항이 0이고 마지막 3개 항은 1인 permu라는 배열을
	next_permutation 함수에 돌려서 permu[i] = 1인 i를 골라 vacant[i]에서 좌표를 뽑음
	(해당 좌표는 배열 wall에 저장함)
	그럼 vacant에서 3개의 좌표가 뽑히므로 해당 좌표 자리에 벽을 세움
*/
vector<pair<int, int>> virus, vacant;
int board[8][8], temp[8][8], permu[64], wall[3][2];
// temp: board 배열 복사본
int dy[4] = { 1,0,-1,0 }, dx[4] = { 0,1,0,-1 };
int N, M, v, empt, ans;
// v: 입력으로 들어오는 바이러스의 개수
// empt: 입력으로 들어오는 0의 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j, y, x;
	cin >> N >> M;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			cin >> board[i][j];
			if (!board[i][j]) {
				// 0인 좌표 저장
				vacant.push_back({ i,j });
				empt++;	// 0의 개수 1 증가
			}
			if (board[i][j] == 2) {
				// 바이러스 좌표 저장
				virus.push_back({ i,j });
				v++;	// 바이러스 개수 1 증가
			}
		}
	// next_permutation에 돌릴 배열 만들기 (끝 3개만 1로 만듦)
	for (i = 1; i <= 3; i++)
		permu[empt - i] = 1;
	// next_permutation 함수 돌리기
	do {
		// 원본 내용 복사
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				temp[i][j] = board[i][j];
		int idx = 0, e = 0;
		while (e < 3) {
			if (permu[idx]) {
				// 뽑힌 세 곳 좌표 적기
				wall[e][0] = vacant[idx].first;
				wall[e][1] = vacant[idx].second;
				e++;
			}
			idx++;
		}
		// 뽑힌 세 곳에 벽 세우기
		for (e = 0; e < 3; e++)
			temp[wall[e][0]][wall[e][1]] = 1;
		int safe = empt - 3;	// 현재 0인 영역의 개수
		// BFS 과정
		queue<pair<int, int>> q;
		for (i = 0; i < v; i++)
			q.push(virus[i]);	// 바이러스의 좌표 queue에 넣음
		while (!q.empty()) {
			y = q.front().first;
			x = q.front().second;
			q.pop();
			for (i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || ny >= N || nx < 0 || nx >= M)
					continue;
				if (!temp[ny][nx]) {
					// 0인 부분으로 바이러스 전파
					temp[ny][nx] = 2;
					q.push({ ny,nx });
					safe--;	// 안전영역 개수 1 감소
				}
			}
		}
		if (safe > ans)
			ans = safe;
	} while (next_permutation(permu, permu + empt));
	cout << ans;
}