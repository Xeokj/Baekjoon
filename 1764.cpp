#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, i, j;
	cin >> n >> m;

	vector<string> hear;
	vector<string> see;
	string name;
	for (i = 0; i < n; i++) {
		cin >> name;
		hear.push_back(name);
	}
	for (i = 0; i < m; i++) {
		cin >> name;
		see.push_back(name);
	}

	sort(hear.begin(), hear.end());
	sort(see.begin(), see.end());

	i = 0; j = 0;
	vector<string> ans;
	while (i < n && j < m) {
		int cmp = hear[i].compare(see[j]);
		if (!cmp) {
			ans.push_back(hear[i]);
			i++;
			j++;
		}
		else if (cmp > 0)
			j++;
		else
			i++;
	}
	int size = ans.size();
	cout << size << "\n";
	for (i = 0; i < size; i++)
		cout << ans[i] << "\n";
}