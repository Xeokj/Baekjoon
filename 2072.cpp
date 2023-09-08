#include <bits/stdc++.h>
using namespace std;
int board[20][20];
// B는 1, W는 2로 표시
int solution(int color);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int N, y, x, result, color, ans = -1;
    bool flg = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> y >> x;
        if (i % 2)
            color = 1;
        else
            color = 2;
        board[y][x] = color;
        result = solution(color);
        if (!flg && result) {
            ans = i;
            flg = 1;
        }
    }
    cout << ans;
}

int solution(int color) {
    int i, j, cnt;
    bool flg = 0;
    // 가로 방향 체크
    for (i = 1; i <= 19; i++) {
        cnt = 0;
        for (j = 1; j <= 19; j++) {
            if (board[i][j] == color) {
                cnt++;
                if (cnt == 5)
                    flg = 1;
                else if (cnt > 5)
                    flg = 0;
            }
            else
                cnt = 0;
        }
        if (flg)
            return 1;
    }
    // 세로 방향 체크
    for (j = 1; j <= 19; j++) {
        cnt = 0;
        for (i = 1; i <= 19; i++) {
            if (board[i][j] == color) {
                cnt++;
                if (cnt == 5)
                    flg = 1;
                else if (cnt > 5)
                    flg = 0;
            }
            else {
                cnt = 0;
            }
        }
        if (flg)
            return 1;
    }
    int row, col;
    // 대각선 1-1 (\ 방향)
    for (col = 1; col <= 15; col++) {
        cnt = 0;
        for (i = 1, j = col; j <= 19; i++, j++) {
            if (board[i][j] == color) {
                cnt++;
                if (cnt == 5)
                    flg = 1;
                else if (cnt > 5)
                    flg = 0;
            }
            else
                cnt = 0;
        }
        if (flg)
            return 1;
    }
    // 대각선 1-2 (\ 방향)
    for (row = 2; row <= 15; row++) {
        cnt = 0;
        for (i = row, j = 1; i <= 19; i++, j++) {
            if (board[i][j] == color) {
                cnt++;
                if (cnt == 5)
                    flg = 1;
                else if (cnt > 5)
                    flg = 0;
            }
            else
                cnt = 0;
        }
        if (flg)
            return 1;
    }
    // 대각선 2-1 (/ 방향)
    for (col = 5; col <= 19; col++) {
        cnt = 0;
        for (i = 1, j = col; i <= col; i++, j--) {
            if (board[i][j] == color) {
                cnt++;
                if (cnt == 5)
                    flg = 1;
                else if (cnt > 5)
                    flg = 0;
            }
            else
                cnt = 0;
        }
        if (flg)
            return 1;
    }
    // 대각선 2-2 (/ 방향)
    for (row = 2; row <= 15; row++) {
        cnt = 0;
        for (i = row, j = 19; i <= 19; i++, j--) {
            if (board[i][j] == color) {
                cnt++;
                if (cnt == 5)
                    flg = 1;
                else if (cnt > 5)
                    flg = 0;
            }
            else
                cnt = 0;
        }
        if (flg)
            return 1;
    }
    return 0;
}