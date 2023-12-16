import sys
input = sys.stdin.readline
from collections import deque
# 7576.py
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

M, N = map(int, input().split())
box = [[0] * M for _ in range(N)]
vacant = 0
q = deque()
for i in range(N):
    box[i] = list(map(int, input().split()))
    for j in range(M):
        if box[i][j] == 0:
            vacant += 1
        elif box[i][j] == 1:
            q.append((i,j))
ans = 0
while q:
    cr, cc = q.popleft()
    for dir in range(4):
        nr = cr + dr[dir]
        nc = cc + dc[dir]
        if nr < 0 or nr >= N or nc < 0 or nc >= M:
            continue
        if box[nr][nc] == 0:
            box[nr][nc] = box[cr][cc] + 1
            vacant -= 1
            ans = box[nr][nc] - 1
            q.append((nr, nc))
if vacant:
    print(-1)
else:
    print(ans)