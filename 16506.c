#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

char opcode[7];
int ML[16];
void toBinary(int* ML, int idx, int num);

int main() {
	int N, i, j;
	scanf("%d", &N);
	int rD, rA, rB, flag = 0;
	while (N) {
		scanf("%s %d %d %d", &opcode, &rD, &rA, &rB);
		if (!strcmp(opcode, "ADD")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "ADDC")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "SUB")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 1;

		}
		else if (!strcmp(opcode, "SUBC")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "MOV")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "MOVC")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "AND")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "ANDC")) {
			ML[0] = 0;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "OR")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 0;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "ORC")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 0;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "NOT")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 0;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "MULT")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 1;
			ML[3] = 0;

		}
		else if (!strcmp(opcode, "MULTC")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 1;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "LSFTL")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 1;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "LSFTLC")) {
			ML[0] = 0;
			ML[1] = 1;
			ML[2] = 1;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "LSFTR")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "LSFTRC")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "ASFTR")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "ASFTRC")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 0;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "RL")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "RLC")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 0;
		}
		else if (!strcmp(opcode, "RR")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 1;
		}
		else if (!strcmp(opcode, "RRC")) {
			ML[0] = 1;
			ML[1] = 0;
			ML[2] = 1;
			ML[3] = 1;
		}
		int len = strlen(opcode);
		if (opcode[len - 1] == 'C') {
			flag = 1;
			ML[4] = 1;
		}
		else ML[4] = 0;
		ML[5] = 0;
		toBinary(ML, 8, rD);
		if (strncmp(opcode, "MOV", 3) && strncmp(opcode, "NOT", 3)) {
			toBinary(ML, 11, rA);
		}
		if (flag)
			toBinary(ML, 15, rB);
		else
			toBinary(ML, 14, rB);
		for (i = 0; i < 16; i++)
			printf("%d", ML[i]);
		printf("\n");
		memset(ML, 0, sizeof(int) * 16);
		flag = 0;
		N--;
	}
	return 0;
}

void toBinary(int* ML, int idx, int num) {
	while (num) {
		if (num % 2)
			ML[idx] = 1;
		else
			ML[idx] = 0;
		num /= 2;
		idx--;
	}
}