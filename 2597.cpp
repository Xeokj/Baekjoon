#include <bits/stdc++.h>
using namespace std;
// ���� 2597��: �������� (�ǹ� 3)

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	double L, ra, rb, ba, bb, ya, yb;
	cin >> L >> ra >> rb >> ba >> bb >> ya >> yb;
	double mid = (ra + rb) / 2;
	L = max(L - mid, mid);
	ba = abs(mid - ba);
	bb = abs(mid - bb);
	ya = abs(mid - ya);
	yb = abs(mid - yb);
	if (ba != bb) {
		mid = (ba + bb) / 2;
		ya = abs(mid - ya);
		yb = abs(mid - yb);
		L = max(L - mid, mid);
	}
	if (ya != yb) {
		mid = (ya + yb) / 2;
		L = max(L - mid, mid);
	}
	// �Ҽ��� �Ʒ� �� �ڸ��� ����� �������� ������ ����
	L *= 10;
	L = floor(L);
	L /= 10;
	// �Ҽ��� �Ʒ� �� �ڸ��� ����ϵ��� �ϴ� ����
	cout << fixed;
	cout.precision(1);
	// L ���
	cout << L;
}