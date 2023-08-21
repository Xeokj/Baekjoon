#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T, K, num;
	cin >> T;
	while (T--) {
		cin >> K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		for (int i = 0; i < K; i++) {
			cin >> num;
			pq.push(num);
		}
		long long sum = 0, tmp1, tmp2;
		while (pq.size() != 1) {
			tmp1 = pq.top();
			pq.pop();
			tmp2 = pq.top();
			pq.pop();
			sum += (tmp1 + tmp2);
			pq.push(tmp1 + tmp2);
		}
		cout << sum << "\n";
	}
}