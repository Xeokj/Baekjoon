import sys
input = sys.stdin.readline
from collections import deque
# 3184.py
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

def bfs(rst, cst):
    global o, v
    oo, vv = 0, 0   # 현재 영역 내(울타리 안)에서의 양과 늑대의 마릿수
    q = deque()
    q.append((rst, cst))
    visited[rst][cst] = 1
    while q:
        cr, cc = q.popleft()
        if board[cr][cc] == 'o':
            oo += 1     # 큐에서 꺼낸 것이 양이면 양의 마릿수 1 증가
        elif board[cr][cc] == 'v':
            vv += 1     # 큐에서 꺼낸 것이 늑대면 늑대의 마릿수 1 증가
        for dir in range(4):
            nr = cr + dr[dir]
            nc = cc + dc[dir]
            # index 범위 밖이거나 이미 방문한 곳은 패스
            if nr < 0 or nr >= R or nc < 0 or nc >= C or visited[nr][nc]:
                continue
            # 울타리면 패스
            if board[nr][nc] == '#':
                continue
            q.append((nr, nc))
            visited[nr][nc] = 1
    if oo > vv:
        v -= vv # 양이 더 많으므로 늑대의 총 마릿수에서 현재 영역의 늑대 수 차감
    else:
        o -= oo # 양의 총 마릿수에서 현재 영역의 양 마릿수 차감

R, C = map(int, input().split())
board = [list(input().rstrip()) for _ in range(R)]
visited = [[0] * C for _ in range(R)]
o, v = 0, 0 # 각각 양과 늑대의 총 마릿수
for i in range(R):
    for j in range(C):
        if board[i][j] == 'o':
            o += 1  # 양의 마릿수 1 증가
        elif board[i][j] == 'v':
            v += 1  # 늑대의 마릿수 1 증가
for i in range(R):
    for j in range(C):
        # 울타리가 아니면서 아직 방문하지 않은 곳일 때
        if board[i][j] != '#' and visited[i][j] == 0:
            bfs(i, j)
print(f'{o} {v}')