#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, i;
	cin >> N;
	string str, input;
	cin >> str;
	int slen = str.size();
	for (i = 0; i < slen; i++) {
		if (str[i] == '*') {
			break;
		}
	}
	int flen = i, rlen = slen - i - 1;
	// flen: '*'앞 부분 길이, rlen: '*'뒷 부분 길이
	while (N--) {
		cin >> input;
		int ilen = input.size(), flag = 0;
		// flag가 0이어야 패턴과 일치함
		if (ilen < flen + rlen)
			flag = 1;	// '*'앞의 길이와 '*'뒤의 길이보다 길거나 같아야 하므로
		else if (ilen >= flen) {
			// '*'앞 부분 비교
			for (i = 0; i < flen; i++) {
				if (input[i] != str[i])
					flag = 1;
			}
			// '*'뒷 부분 비교
			for (i = 0; i < rlen; i++) {
				if (input[ilen - i - 1] != str[slen - i - 1])
					flag = 1;
			}
		}
		if (flag)
			cout << "NE\n";
		else
			cout << "DA\n";
	}
}