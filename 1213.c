#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	char arr[51];
	int* alpha = (int*)calloc(26, sizeof(int));
	scanf("%s", &arr);
	int len = strlen(arr);

	int i, j, check = 0, n;	// check: 홀수 개인 알파벳이 있을 때, n: 각 알파벳의 개수
	for (i = 0; i < len; i++)
		alpha[arr[i] - 'A']++;

	if (len % 2 == 0) {	// 길이가 짝수일 때
		for (i = 0; i < 26; i++) {
			if (alpha[i] % 2 != 0) {
				check = 1;
				break;
			}
		}
		if (!check) {
			for (i = 0; i < 26; i++) {
				n = alpha[i];
				for (j = 0; j < n / 2; j++)
					printf("%c", i + 'A');
				alpha[i] /= 2;
			}
			// 나머지 절반 출력
			for (i = 25; i >= 0; i--) {
				n = alpha[i];
				for (j = 0; j < n; j++)
					printf("%c", i + 'A');
			}
		}
		else
			printf("I'm Sorry Hansoo");
	}
	else {	// 길이가 홀수일 때
		int loc = -1;	// 홀수 개인 알파벳 하나의 위치
		for (i = 0; i < 26; i++) {
			if (alpha[i] % 2 != 0) {
				loc = i;
				check++;
				continue;
			}
		}
		// 홀수 개인 알파벳이 하나만 나와서 출력 가능할 때
		if (check == 1) {
			for (i = 0; i < 26; i++) {
				n = alpha[i];
				for (j = 0; j < n / 2; j++)
					printf("%c", i + 'A');
				alpha[i] /= 2;
				if (i == loc)	// 홀수 개인 알파벳일 때
					alpha[i]++;
			}
			// 홀수 개인 알파벳을 가운데에 하나 출력함
			printf("%c", loc + 'A');
			alpha[loc]--;
			// 나머지 출력
			for (i = 25; i >= 0; i--) {
				n = alpha[i];
				for (j = 0; j < n; j++)
					printf("%c", i + 'A');
			}
		}
		// 홀수 개인 알파벳이 여러 개일 때
		else
			printf("I'm Sorry Hansoo");
	}
	free(alpha);
	return 0;
}