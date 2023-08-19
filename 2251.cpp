#include <bits/stdc++.h>
using namespace std;
int oA, oB, oC;
bool visited[201][201];
bool ans[201];
queue<pair<int, int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> oA >> oB >> oC;
	q.push({ 0,0 });
	while (!q.empty()) {
		int A = q.front().first;
		int B = q.front().second;
		int C = oC - A - B;
		q.pop();
		if (visited[A][B])
			continue;
		visited[A][B] = 1;
		if (!A)
			ans[C] = 1;
		// A���� B��
		if (A + B <= oB)
			q.push({ 0,A + B });
		else
			q.push({ A + B - oB,oB });
		// A���� C��
		if (A + C <= oC)
			q.push({ 0,B });
		else
			q.push({ A + C - oC,B });
		// B���� A��
		if (A + B <= oA)
			q.push({ A + B,0 });
		else
			q.push({ oA,A + B - oA });
		// B���� C��
		if (B + C <= oC)
			q.push({ A,0 });
		else
			q.push({ A,B + C - oC });
		// C���� A��
		if (A + C <= oA)
			q.push({ A + C,B });
		else
			q.push({ oA,B });
		// C���� B��
		if (B + C <= oB)
			q.push({ A,B + C });
		else
			q.push({ A, oB });
	}
	for (int i = 0; i < 201; i++)
		if (ans[i])
			cout << i << ' ';
}