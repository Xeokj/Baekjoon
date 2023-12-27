# 10971.py
import sys
input = sys.stdin.readline

def backtr(st, cur, depth, sum):
    global ans, N
    if depth == N:
        if W[cur][st] != 0 and sum + W[cur][st] < ans:
            ans = sum + W[cur][st]
        return
    if sum > ans:
        return
    for i in range(N):
        if W[cur][i] != 0 and visited[i] == 0:
            visited[i] = 1
            backtr(st, i, depth + 1, sum + W[cur][i])
            visited[i] = 0

N = int(input())
W = [list(map(int, input().split())) for _ in range(N)]
visited = [0] * N
ans = 10000000
for i in range(N):
    visited[i] = 1
    backtr(i, i, 1, 0)
    visited[i] = 0
print(ans)