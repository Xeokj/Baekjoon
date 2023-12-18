# 1012.py
import sys
input = sys.stdin.readline
from collections import deque
T = int(input())
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]
while T:
    M, N, K = map(int, input().split())
    board = [[0] * M for _ in range(N)]
    while K:
        c, r = map(int, input().split())
        board[r][c] = 1
        K -= 1
    ans = 0
    for i in range(N):
        for j in range(M):
            if board[i][j] == 1:
                ans += 1
                q = deque()
                q.append((i, j))
                board[i][j] = 0
                while q:
                    cr, cc = q.pop()
                    for dir in range(4):
                        nr = cr + dr[dir]
                        nc = cc + dc[dir]
                        if nr < 0 or nr >= N or nc < 0 or nc >= M:
                            continue
                        if board[nr][nc]:
                            q.append((nr, nc))
                            board[nr][nc] = 0
    print(ans)
    T -= 1