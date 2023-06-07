#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int N, i, j;
	char word[101];
	scanf("%d", &N);
	while (N) {
		scanf("%s", &word);
		int len = strlen(word);
		int cnt = 0;
		char* res = (char*)calloc(len + 1, sizeof(char));

		for (i = 0, j = 0; i < len; i++, j++) {
			if (word[i] == '@') {
				res[j] = 'a';
				cnt++;
			}
			else if (word[i] == '[') {
				res[j] = 'c';
				cnt++;
			}
			else if (word[i] == '!') {
				res[j] = 'i';
				cnt++;
			}
			else if (word[i] == ';') {
				res[j] = 'j';
				cnt++;
			}
			else if (word[i] == '^') {
				res[j] = 'n';
				cnt++;
			}
			else if (word[i] == '0') {
				res[j] = 'o';
				cnt++;
			}
			else if (word[i] == '7') {
				res[j] = 't';
				cnt++;
			}
			else if (word[i] == '\\') {
				// v인지 확인
				if (i + 1 < len) {
					if (word[i + 1] == '\'') {
						res[j] = 'v';
						cnt++;
						i++;
						continue;
					}
				}
				// w인지 확인
				if (i + 2 < len) {
					if (word[i + 1] == '\\' && word[i + 2] == '\'') {
						res[j] = 'w';
						cnt++;
						i += 2;
					}
				}
			}
			else
				res[j] = word[i];
		}

		int res_len = strlen(res);
		if (res_len % 2 == 0 && cnt >= res_len / 2)
			printf("I don't understand\n");
		else if (cnt > res_len / 2)
			printf("I don't understand\n");
		else
			printf("%s\n", res);
		free(res);
		N--;
	}
	return 0;
}