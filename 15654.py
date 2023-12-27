# 15654.py
import sys
input = sys.stdin.readline

def backtr(dpt, M, N):
    if dpt == M:
        print(*ans)
        return
    for i in range(N):
        if isused[i] == 0:
            isused[i] = 1
            ans.append(nums[i])
            backtr(dpt + 1, M, N)
            ans.pop()
            isused[i] = 0

N, M = map(int, input().split())
nums = list(map(int, input().split()))
nums.sort()
isused = [0] * N
ans = list()
backtr(0, M, N)