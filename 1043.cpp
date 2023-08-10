#include <bits/stdc++.h>
using namespace std;
int N, M, t, ans;
int truth[51];
vector<int> party[51];
int check();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int member, num, i, j;
	cin >> N >> M >> t;
	for (i = 0; i < t; i++) {
		cin >> member;
		truth[member] = 1;
	}
	ans = M;
	for (i = 0; i < M; i++) {
		cin >> num;
		int flag = 0;
		party[i].push_back(0);
		for (j = 0; j < num; j++) {
			cin >> member;
			party[i].push_back(member);
			if (truth[member])
				party[i][0] = 1;
		}
		if (party[i][0]) {
			for (j = 1; j <= num; j++)
				truth[party[i][j]] = 1;
			ans--;
		}
	}
	while (check());
	cout << ans;
}

int check() {
	int flag = 0, i, j;
	for (i = 0; i < M; i++) {
		if (!party[i][0]) {
			for (j = 1; j < party[i].size(); j++) {
				if (truth[party[i][j]])
					party[i][0] = 1;
			}
			if (party[i][0]) {
				for (j = 1; j < party[i].size(); j++)
					truth[party[i][j]] = 1;
				flag = 1;
				ans--;
			}
		}
	}
	return flag;
}