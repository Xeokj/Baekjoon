#define _CRT_SECURE_NO_WARNINGS
#define INF (~0U>>2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
// 백준 12852번: 1로 만들기 2 (실버 1)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	vector<int> parent(n + 1, 0);

	queue<int> q;
	// n에서 1을 만들기 위한 연산 결과
	q.push(n);
	while (!q.empty()) {
		int num = q.front();
		q.pop();
		if (num % 3 == 0 && dp[num / 3] == 0 || dp[num / 3] > dp[num] + 1) {
			q.push(num / 3);
			dp[num / 3] = dp[num] + 1;
			parent[num / 3] = num;
			if (num / 3 == 1)
				break;
		}
		if (num % 2 == 0 && dp[num / 2] == 0 || dp[num / 2] > dp[num] + 1) {
			q.push(num / 2);
			dp[num / 2] = dp[num] + 1;
			parent[num / 2] = num;
			if (num / 2 == 1)
				break;
		}
		if (num > 0 && dp[num - 1] == 0 || dp[num - 1] > dp[num] + 1) {
			q.push(num - 1);
			dp[num - 1] = dp[num] + 1;
			parent[num - 1] = num;
			if (num - 1 == 1)
				break;
		}
	}
	// 경로 추적
	int i = 1;
	vector<int> path;
	path.push_back(1);
	while (i != n) {
		i = parent[i];
		path.push_back(i);
	}
	reverse(path.begin(), path.end());
	cout << dp[1] << "\n";
	for (i = 0; i < path.size(); i++)
		cout << path[i] << " ";
	return 0;
}
