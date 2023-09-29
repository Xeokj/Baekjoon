#include <bits/stdc++.h>
using namespace std;
// ¹éÁØ 1111¹ø: IQ TEST (°ñµå 3)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, i;
	int arr[50];
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> arr[i];
	if (N == 1)
		cout << 'A';
	else if (N == 2 && (arr[0] == arr[1]))
		cout << arr[0];
	else if (N == 2)
		cout << 'A';
	else {
		a = 0;
		if(arr[0] != arr[1])
			a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
		b = arr[1] - arr[0] * a;
		for (i = 0; i < N - 1; i++) {
			if (arr[i + 1] != arr[i] * a + b)
				break;
		}
		if (i == N - 1)
			cout << a * arr[N - 1] + b;
		else
			cout << 'B';
	}
}