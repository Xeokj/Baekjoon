#define INF (~0U>>2)
#include <bits/stdc++.h>
using namespace std;
int dist[200001];
deque<int> dq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, K;
	fill(dist, dist + 200001, INF);
	cin >> N >> K;
	dq.push_back(N);
	dist[N] = 0;
	while (!dq.empty()) {
		int cur = dq.front();
		int d = dist[cur];
		if (cur == K)
			break;
		dq.pop_front();
		if (cur > 0 && dist[cur - 1] > d + 1) {
			dq.push_back(cur - 1);
			dist[cur - 1] = d + 1;
		}
		if (cur + 1 < 200000 && dist[cur + 1] > d + 1) {
			dq.push_back(cur + 1);
			dist[cur + 1] = d + 1;
		}
		if (cur * 2 < 200000 && dist[cur * 2] > d) {
			dq.push_front(cur * 2);
			dist[cur * 2] = d;
		}
	}
	cout << dist[K];
}