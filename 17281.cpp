#include <bits/stdc++.h>
using namespace std;
int order[9], inning[9], field[4], input[50][10];
int permu[8] = { 2,3,4,5,6,7,8,9 };
/*
	- permu: next_permutaion 함수 돌리는 용도 (순서 배치용)
	- order: index=0~2는 permu의 index=0~2로 배치,
		index=4~8은 permu의 index=4~8로 배치하고, index=3은 1로 고정함
		(index[i]번의 타자는 i+1번째 순서를 뜻함)
		Ex. order : 2 1 5 4 8 9 7 6 3
			2번 = 첫 번째 순서, 1번 = 두 번째 순서, 5번 = 세 번째 순서, ...
	- inning: Permutation 함수를 돌려서 배치된 순서에 따른 현재 이닝의 결과
	- field: 각 루에 사람이 있는지 0과 1로 표시(Ex. field[1] = 1은 1루에 사람이 있음을 뜻함)
*/

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, ans = 0, i, j, k;
	cin >> N;
	order[3] = 1;	// 4번째 순서는 무조건 1번으로 고정
	for (i = 0; i < N; i++)
		for (j = 1; j <= 9; j++)
			cin >> input[i][j];
	// next_permutation 함수를 이용해 순서 배정
	do {
		// index=3을 제외하고 order에 순서 배치
		for (i = 0; i < 3; i++)
			order[i] = permu[i];
		for (i = 3; i < 8; i++)
			order[i + 1] = permu[i];

		int score = 0, zero, idx = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < 9; j++)
				inning[j] = input[i][order[j]];
			zero = 0;
			// 0이 3번이면 다음 이닝으로 넘어가므로
			while (zero < 3) {
				if (inning[idx] == 1) {
					// 안타
					if (field[3]) {
						score++;
						field[3] = 0;	// 3루를 비워줌
					}
					for (k = 2; k > 0; k--) {
						// 1루와 2루는 한 칸씩 옮겨줌
						if (field[k]) {
							field[k] = 0;
							field[k + 1] = 1;
						}
					}
					field[1] = 1;	// 1루를 채워줌
				}
				else if (inning[idx] == 2) {
					// 2루타
					if (field[3]) {
						score++;
						field[3] = 0;	// 3루를 비워줌
					}
					if (field[2]) {
						// 2루수까지 홈에 들어오므로 2루도 비워줌
						score++;
						field[2] = 0;
					}
					if (field[1]) {
						//	1루에 있는 선수는 3루로 이동
						field[1] = 0;
						field[3] = 1;
					}
					field[2] = 1;	// 2루를 채워줌
				}
				else if (inning[idx] == 3) {
					// 3루타
					for (k = 3; k > 0; k--) {
						/* 1루부터 3루까지 모두 홈으로 들어올 수 있으므로
						점수를 1씩 올리고 해당 루를 비워줌 */
						if (field[k]) {
							score++;
							field[k] = 0;
						}
						field[3] = 1;	// 3루를 채워줌
					}
				}
				else if (inning[idx] == 4) {
					// 홈런
					for (k = 3; k > 0; k--) {
						// 모든 루에 있는 사람만큼 점수를 올리고 해당 루를 비움
						if (field[k]) {
							score++;
							field[k] = 0;
						}
					}
					score++;	// 홈런친 선수가 홈으로 들어오는 점수
				}
				else
					zero++;	// 아웃일 때
				idx = (idx + 1) % 9;	// idx를 1씩 증가시켜주고 8을 넘으면 다시 0부터 시작
			}
			// 한 이닝이 끝나면 field 초기화
			for (k = 1; k < 4; k++)
				field[k] = 0;
		}
		if (score > ans)
			ans = score;
	} while (next_permutation(permu, permu + 8));
	cout << ans;
}