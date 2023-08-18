#include <bits/stdc++.h>
using namespace std;
int Max[3], Min[3], tmp1[3], tmp2[3];
int FMaxx(int arr[]);
int FMinn(int arr[]);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, num, i;
	cin >> N;
	for (i = 0; i < 3; i++) {
		cin >> Max[i];
		Min[i] = Max[i];
	}
	N--;
	while (N--) {
		for (i = 0; i < 3; i++) {
			tmp1[i] = Max[i];
			tmp2[i] = Min[i];
		}
		Max[0] = max(tmp1[0], tmp1[1]);
		Max[1] = FMaxx(tmp1);
		Max[2] = max(tmp1[1], tmp1[2]);
		Min[0] = min(tmp2[0], tmp2[1]);
		Min[1] = FMinn(tmp2);
		Min[2] = min(tmp2[1], tmp2[2]);
		for (i = 0; i < 3; i++) {
			cin >> num;
			Max[i] += num;
			Min[i] += num;
		}
	}
	int maxx = FMaxx(Max), minn = FMinn(Min);
	cout << maxx << ' ' << minn;
}

int FMaxx(int arr[]) {
	int Maxx = arr[0];
	if (arr[1] > Maxx)
		Maxx = arr[1];
	if (arr[2] > Maxx)
		Maxx = arr[2];
	return Maxx;
}

int FMinn(int arr[]) {
	int Minn = arr[0];
	if (arr[1] < Minn)
		Minn = arr[1];
	if (arr[2] < Minn)
		Minn = arr[2];
	return Minn;
}