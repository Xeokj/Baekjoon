#include <bits/stdc++.h>
using namespace std;
// ���� 1138��: �� �ٷ� ���� (�ǹ� 2)
int arr[10];
vector<int> line;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	for (i = n - 1; i >= 0; i--)
		line.insert(line.begin() + arr[i], i + 1);
	for (i = 0; i < n; i++)
		cout << line[i] << ' ';
}