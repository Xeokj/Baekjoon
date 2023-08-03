//#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

char input[10];
int used[10], Min[10], Max[10];
int k, range;
void FindMax();
void FindMin();

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int i, j;
	cin >> k;
	for (i = 0; i < k; i++)
		cin >> input[i];
	FindMax();
	memset(used, 0, sizeof(used));
	FindMin();
	for (i = 0; i <= k; i++)
		cout << Max[i];
	cout << "\n";
	for (i = 0; i <= k; i++)
		cout << Min[i];
}

void FindMax() {
	int i, j, cur;
	range = 9;
	for (i = 0; i < k; i++) {
		while (used[range])
			range--;	// 최대값 찾기
		if (input[i] == '<') {
			j = i;
			int cnt = 0;
			while (input[j] == '<') {
				cnt++;
				j++;
			}
			// '<'의 개수만큼 작은 수부터 시작
			cur = range - cnt;
			while (cur < range) {
				Max[i++] = cur;
				used[cur] = 1;
				cur++;
			}
			i--; // for문에서 i++ 할 때 index를 맞춰주기 위해
		}
		else {
			Max[i] = range;
			used[range] = 1;
			range--;
		}
	}
	while (used[range])
		range--;
	Max[k] = range;
}

void FindMin() {
	// FindMax의 반대
	int i, j, cur;
	range = 0;
	for (i = 0; i < k; i++) {
		while (used[range])
			range++;	// 최소값 찾기
		if (input[i] == '>') {
			j = i;
			int cnt = 0;
			while (input[j] == '>') {
				cnt++;
				j++;
			}
			cur = range + cnt;
			while (cur > range) {
				Min[i++] = cur;
				used[cur] = 1;
				cur--;
			}
			i--;
		}
		else {
			Min[i] = range;
			used[range] = 1;
			range++;
		}
	}
	while (used[range])
		range++;
	Min[k] = range;
}