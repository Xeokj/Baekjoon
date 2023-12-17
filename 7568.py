# 7568.py
import sys
input = sys.stdin.readline
N = int(input())
info = list()
for _ in range(N):
    h, w = map(int, input().split())
    info.append((h, w))
ranking = list()
ans = list()
for i in range(N):
    h, w = info[i]
    cnt = 1
    for j in range(N):
        hh, ww = info[j]
        if hh > h and ww > w:
            cnt += 1
    ans.append(cnt)
print(*ans)