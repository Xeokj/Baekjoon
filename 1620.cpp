#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> PM;
string name[100001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M, i;
	cin >> N >> M;
	for (i = 1; i <= N; i++) {
		cin >> name[i];
		PM[name[i]] = i;
	}
	while (M--) {
		string quest;
		cin >> quest;
		if (isdigit(quest[0]))
			cout << name[stoi(quest)] << "\n";
		else
			cout << PM[quest] << "\n";
	}
}