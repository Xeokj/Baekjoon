# 2210.py
import sys
input = sys.stdin.readline

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]
nums = set()
def dfs(cr, cc, x, depth):
    if depth == 6:
        nums.add(int(x))
        return
    for dir in range(4):
        nr = cr + dr[dir]
        nc = cc + dc[dir]
        if nr < 0 or nr >= 5 or nc < 0 or nc >= 5:
            continue
        dfs(nr, nc, x+board[nr][nc], depth + 1)

board = [input().split() for _ in range(5)]
for i in range(5):
    for j in range(5):
        dfs(i, j, board[i][j], 1)
print(len(nums))