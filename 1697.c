#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100001

typedef struct _LOC {
	int loc;
	int order;
} LOC;

LOC q[MAX];
int visited[MAX];

int main() {
	int N, K;
	scanf("%d %d", &N, &K);

	int front = 0, rear = 0;
	q[rear].loc = N;
	q[rear].order = 0;
	visited[N] = 1;

	while (q[front].loc != K) {
		int newloc;
		if (q[front].loc > 0) {
			newloc = q[front].loc - 1;
			if (!visited[newloc]) {
				rear++;
				q[rear].loc = newloc;
				q[rear].order = q[front].order + 1;
				visited[newloc] = 1;
			}
		}
		if (q[front].loc < K) {
			newloc = q[front].loc + 1;
			if (!visited[newloc]) {
				rear++;
				q[rear].loc = newloc;
				q[rear].order = q[front].order + 1;
				visited[newloc] = 1;
			}
		}
		if (q[front].loc * 2 <= K + 1) {
			newloc = q[front].loc * 2;
			if (!visited[newloc]) {
				rear++;
				q[rear].loc = newloc;
				q[rear].order = q[front].order + 1;
				visited[newloc] = 1;
			}
		}
		front++;
	}
	printf("%d", q[front].order);
	return 0;
}