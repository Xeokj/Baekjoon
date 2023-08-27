#include <bits/stdc++.h>
using namespace std;
int A, B;
int board[101][101], robot[101][3];
// robot: �� �κ��� ����(0��: ����, 1���� 2��: ��ǥ)
int dy[4] = { -1,0,1,0 }, dx[4] = { 0,1,0,-1 };
// �ϵ����� ����
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
		// ��� ����ϴ� ��ǥ��� ��ȯ�ؼ� ����
		// �� ���� ���� (1,1), �� ������ �Ʒ��� (B, A)
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
			num = comm[i].first.first;	// ����� �ϴ��� �κ� ��ȣ
			comnum = comm[i].first.second;	// L, R, F �� �ϳ�
			if (comnum == 1) {
				// L �������� ȸ��
				robot[num][0]--;
				if (robot[num][0] == -1)
					robot[num][0] = 3;
			}
			else if (comnum == 2) {
				// R �������� ȸ��
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
					// ��(��輱)�� �ε��� ���
					cout << "Robot " << num << " crashes into the wall";
					flg = 1;
					break;
				}
				else if (board[ny][nx]) {
					// �ٸ� �κ��� �ε��� ���
					cout << "Robot " << num << " crashes into robot " << board[ny][nx];
					flg = 1;
					break;
				}
				else {
					// �̵��ϱ�
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