#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

typedef struct _Coord {
	int x;		// 입력 받은 값
	int loc;	// 입력 받은 순서(위치)
	int compress;	// 순서 (압축된 좌표 값)
} Coord;

int flag;	// flag가 1이면 위치를 

int compare(const void* a, const void* b) {
	Coord A = *(Coord*)a;
	Coord B = *(Coord*)b;
	// 값 정렬
	if (!flag) {
		if (A.x > B.x)
			return 1;
		else if (A.x < B.x)
			return -1;
		else
			return 0;
	}
	else {	// 위치 번호 정렬
		if (A.loc > B.loc)
			return 1;
		else if (A.loc < B.loc)
			return -1;
		else
			return 0;
	}
}

int main() {
	int N, i;
	scanf("%d", &N);
	Coord* coord = (Coord*)calloc(N, sizeof(Coord));
	for (i = 0; i < N; i++) {
		scanf("%d", &coord[i].x);
		coord[i].loc = i;
	}
	// 값(x)을 기준으로 정렬
	qsort(coord, N, sizeof(Coord), compare);

	// 순서 배정
	for (i = 1; i < N; i++) {
		if (coord[i].x == coord[i - 1].x)
			coord[i].compress = coord[i - 1].compress;
		else
			coord[i].compress = coord[i - 1].compress + 1;
	}
	flag = 1;
	// 기존 순서로 돌리기 위해 위치를 기준으로 정렬
	qsort(coord, N, sizeof(Coord), compare);

	for (i = 0; i < N; i++)
		printf("%d ", coord[i].compress);
	return 0;
}