#include <bits/stdc++.h>
using namespace std;
int sudoku[9][9];
int row[9][10], col[9][10], box[9][10];
// i행에 숫자 j가 있는지 표시
// i열에 숫자 j가 있는지 표시
// i번 박스에 숫자 j가 있는지 표시 (맨 왼쪽 위 박스부터 오른쪽으로 0번 ~ 8번 부여)
string input;
void backtr(int r, int c);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int num, i, j;
	for (i = 0; i < 9; i++) {
		cin >> input;
		for (j = 0; j < 9; j++) {
			num = input[j] - '0';
			sudoku[i][j] = num;
			if (num) {
				row[i][num] = 1;
				col[j][num] = 1;
				// 박스 번호 부여
				int bnum = (i / 3) * 3 + j / 3;
				box[bnum][num] = 1;
			}
		}
	}
	backtr(0, 0);
}

void backtr(int r, int c) {
	int i, j;
	if (r == 8 && c == 9) {
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++)
				cout << sudoku[i][j];
			cout << "\n";
		}
		exit(0);
	}
	if (c == 9)
		backtr(r + 1, 0);
	else if (!sudoku[r][c]) {
		for (i = 1; i <= 9; i++) {
			int bnum = (r / 3) * 3 + c / 3;
			if (!(row[r][i] || col[c][i] || box[bnum][i])) {
				sudoku[r][c] = i;
				row[r][i] = 1;
				col[c][i] = 1;
				box[bnum][i] = 1;
				backtr(r, c + 1);
				sudoku[r][c] = 0;
				row[r][i] = 0;
				col[c][i] = 0;
				box[bnum][i] = 0;
			}
		}
	}
	else if (sudoku[r][c])
		backtr(r, c + 1);
}