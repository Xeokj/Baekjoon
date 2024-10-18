#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
// 백준 1022번: 소용돌이 예쁘게 출력하기 (골드 3)

int arr[50][5];
int dr[4] = { 0,-1,0,1 };
int dc[4] = { 1,0,-1,0 };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int m = max({ abs(r1),abs(c1),abs(r2),abs(c2) });
	r1 += m;
	c1 += m;
	r2 += m;
	c2 += m;
	// 가상의 (2m+1)*(2m+1)짜리 소용돌이 생성
	// 1,오,1,위,2,왼,2,아,3,오,3,위,4,왼,4,아,5,오,5,위,6,왼,6, ... 순서
	int num = 1, cnt = 1, dir = 0;
	// num: 소용돌이에 쓸 숫자, cnt: 이동 횟수, dir: 방향
	int r = m, c = m;		// 가상의 (m, m)에서 시작
	while (num <= (2 * m + 1) * (2 * m + 1)) {
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < cnt; j++) {
				// j를 사용해서 1칸 만큼, 2칸 만큼, 3칸 만큼, ... 이렇게 증가해야함
				// 범위 내의 숫자만 배열에 저장함
				if (r >= r1 && r <= r2 && c >= c1 && c <= c2)
					arr[r - r1][c - c1] = num;
				num++;	// 다음 숫자
				r += dr[dir];
				c += dc[dir];
			}
			dir = (dir + 1) % 4;
		}
		cnt++;
	}
	int l = max({ arr[0][0],arr[r2 - r1][0],arr[0][c2 - c1],arr[r2 - r1][c2 - c1] });
	int w = 0;	// w: 자릿수
	while (l) {
		w++;
		l /= 10;
	}
	// (r1+m, c1+m)부터 (r2+m, c2+m)까지 출력하기
	for (int i = 0; i <= r2 - r1; i++) {
		for (int j = 0; j <= c2 - c1; j++) {
			cout << setw(w) << arr[i][j] << " ";
		}
		cout << "\n";
	}

	// 참고
	// 가장 큰숫자의 자릿수를 digit, 출력해야하는 수를 num이라고 하면,
	// printf("%*d ",digit, num);으로 출력하면 됩니다.
	return 0;
}
