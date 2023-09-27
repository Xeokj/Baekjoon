#include <bits/stdc++.h>
using namespace std;
// 백준 1759번: 암호 만들기 (골드 5)
int L, C;
vector<char> alpha;
char ans[15];
void backtr(int cur, int n, int vowel, int conso);
// cur: alpha에서 가리키고 있는 커서, n: ans에 저장된 개수
// vowel: ans에 저장된 모음의 개수, conso: ans에 저장된 자음의 개수

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		char a;
		cin >> a;
		alpha.push_back(a);
	}
	// 입력받은 알파벳들을 오름차순 정렬
	sort(alpha.begin(), alpha.end());
	backtr(0, 0, 0, 0);
}

void backtr(int cur, int n, int vowel, int conso) {
	// 일단 L개의 문자열을 만든 후 조건에 부합하면 출력
	if (n == L) {
		if (!vowel || conso < 2)
			return;	// 모음과 자음의 최소 개수를 부합하지 않은 경우
		for (int i = 0; i < L; i++)
			cout << ans[i];
		cout << "\n";
		return;
	}
	for (int i = cur; i < C; i++) {
		ans[n] = alpha[i];
		if (alpha[i] == 'a' || alpha[i] == 'e' || alpha[i] == 'i' || alpha[i] == 'o' || alpha[i] == 'u')
			backtr(i + 1, n + 1, vowel + 1, conso);	// 모음일 때
		else
			backtr(i + 1, n + 1, vowel, conso + 1);	// 자음일 때
	}
}