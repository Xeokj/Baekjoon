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
	// flen: '*'�� �κ� ����, rlen: '*'�� �κ� ����
	while (N--) {
		cin >> input;
		int ilen = input.size(), flag = 0;
		// flag�� 0�̾�� ���ϰ� ��ġ��
		if (ilen < flen + rlen)
			flag = 1;	// '*'���� ���̿� '*'���� ���̺��� ��ų� ���ƾ� �ϹǷ�
		else if (ilen >= flen) {
			// '*'�� �κ� ��
			for (i = 0; i < flen; i++) {
				if (input[i] != str[i])
					flag = 1;
			}
			// '*'�� �κ� ��
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