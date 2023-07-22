#include <bits/stdc++.h>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

int city[50][50];
vector<pair<int, int>> home;	// 집 좌표 저장
vector<pair<int, int>> chicken;	// 치킨집 좌표 저장
int comb[13];	// 조합 만들 배열
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
	int ch = chicken.size();	// 치킨집 개수
	int hm = home.size();	// 집 개수

	// 치킨집 조합 생성
	i = ch - 1;
	tmp = M;
	while (tmp--) {
		comb[i--] = 1;
	}
	
	int dist = 0, ans = 10000;
	do {
		dist = 0;
		for (i = 0; i < hm; i++) {
			// 각 집마다 폐업되지 않은 치킨 집 중 가장 가까운 곳과의 거리 구함 
			int Min = 100;	// 폐업되지 않은 치킨집 중 가장 가까운 곳과의 거리
			for (j = 0; j < ch; j++) {
				if (comb[j]) {
					Min = min(Min, abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second));
				}
			}
			dist += Min;
		}
		// 모든 집에서 폐업되지 않는 치킨집과의 최소 거리를 구한 후 가장 작은 걸로 고름
		if (dist < ans)
			ans = dist;
	} while (next_permutation(comb, comb + ch));
	cout << ans;
}