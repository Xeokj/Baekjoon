# 15686.py
import sys
input = sys.stdin.readline
from itertools import combinations

N, M = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]
chicken = list()
house = list()
cn, hn = 0, 0   # 치킨집의 개수, 집의 개수
for i in range(N):
    for j in range(N):
        if board[i][j] == 1:
            house.append((i, j))
            hn += 1
        elif board[i][j] == 2:
            chicken.append((i, j))
            cn += 1

coms = list(combinations(chicken, M))
ans = 10000
# 살아남은 치킨집
for serv in coms:
    sum = 0
    for hh in house:
        dist = 100
        hy, hx = hh
        for i in serv:
            # 치킨집의 y, x 좌표
            y, x = i
            dist = min(dist, abs(y - hy) + abs(x - hx))
        sum += dist
    if sum < ans:
        ans = sum
print(ans)