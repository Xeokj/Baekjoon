#include <bits/stdc++.h>
using namespace std;
int A, B;
int board[101][101], robot[101][3];
// robot: 각 로봇의 상태(0열: 방향, 1열과 2열: 좌표)
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
// 북동남서 순서
vector<pair<pair<int, int>, int>> comm;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i;
	cin >> A >> B >> N >> M;
	int x, y;
	char status;
	for (i = 1; i <= N; i++) {
		cin >> x >> y >> status;
		// 평소 사용하는 좌표계로 변환해서 저장
		// 맨 왼쪽 위가 (1,1), 맨 오른쪽 아래가 (B, A)
		board[B - y + 1][x] = i;
		robot[i][1] = B - y + 1;
		robot[i][2] = x;
		if (status == 'N')
			robot[i][0] = 0;
		else if (status == 'E')
			robot[i][0] = 1;
		else if (status == 'S')
			robot[i][0] = 2;
		else if (status == 'W')
			robot[i][0] = 3;
	}
	int num, comnum, rep;
	char command;
	for (i = 0; i < M; i++) {
		cin >> num >> command >> rep;
		if (command == 'L')
			comnum = 1;
		else if (command == 'R')
			comnum = 2;
		else if (command == 'F')
			comnum = 3;
		comm.push_back({ {num,comnum},rep });
	}
	bool flg = 0;
	for (i = 0; i < M; i++) {
		while (comm[i].second) {
			num = comm[i].first.first;	// 명령을 하달할 로봇 번호
			comnum = comm[i].first.second;	// L, R, F 중 하나
			if (comnum == 1) {
				// L 방향으로 회전
				robot[num][0]--;
				if (robot[num][0] == -1)
					robot[num][0] = 3;
			}
			else if (comnum == 2) {
				// R 방향으로 회전
				robot[num][0]++;
				if (robot[num][0] == 4)
					robot[num][0] = 0;
			}
			else if (comnum == 3) {
				int cury = robot[num][1];
				int curx = robot[num][2];
				int ny = cury + dy[robot[num][0]];
				int nx = curx + dx[robot[num][0]];
				if (ny <= 0 || ny > B || nx <= 0 || nx > A) {
					// 벽(경계선)과 부딪힌 경우
					cout << "Robot " << num << " crashes into the wall";
					flg = 1;
					break;
				}
				else if (board[ny][nx]) {
					// 다른 로봇과 부딪힌 경우
					cout << "Robot " << num << " crashes into robot " << board[ny][nx];
					flg = 1;
					break;
				}
				else {
					// 이동하기
					board[cury][curx] = 0;
					board[ny][nx] = num;
					robot[num][1] = ny;
					robot[num][2] = nx;
				}
			}
			comm[i].second--;
		}
		if (flg)
			break;
	}
	if (!flg)
		cout << "OK";
}