#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#define MAX_SIZE 10001

int queue[MAX_SIZE];
int head = -1;
int rear = -1;
int qsize = 0;

void push(int num);
int pop();
int size();
int empty();
int front();
int back();

int main() {
	int N, i;
	scanf("%d", &N);
	char command[6];
	int num;

	for (i = 0; i < N; i++) {
		scanf("%s", &command);
		if (!strcmp(command, "push")) {
			scanf("%d", &num);
			push(num);
		}
		else if (!strcmp(command, "pop"))
			printf("%d\n", pop());
		else if (!strcmp(command, "size"))
			printf("%d\n", size());
		else if (!strcmp(command, "empty"))
			printf("%d\n", empty());
		else if (!strcmp(command, "front"))
			printf("%d\n", front());
		else if (!strcmp(command, "back"))
			printf("%d\n", back());
	}
	return 0;
}

void push(int num) {
	queue[++rear] = num;
	qsize++;
}

int pop() {
	if (!qsize)
		return -1;
	else {
		qsize--;
		return queue[++head];
	}
}

int size() {
	return qsize;
}

int empty() {
	if (qsize)
		return 0;
	else
		return 1;
}

int front() {
	if (!qsize)
		return -1;
	else
		return queue[head + 1];
}

int back() {
	if (!qsize)
		return -1;
	else
		return queue[rear];
}