import sys
input = sys.stdin.readline

K, N = map(int, input().split())
arr = list()
Max = 0
for i in range(K):
    arr.append(int(input()))
    if arr[i] > Max:
        Max = arr[i]
left, right = 1, Max
ans = 0     # 0으로 가정
while left <= right:
    mid = (left + right) // 2
    cnt = 0
    for i in range(K):
        cnt += (arr[i] // mid)
    # cnt가 K보다 크면 일단 만들 수 있는 범위에는 들어오는 것
    if cnt >= N:
        if ans < mid:
            ans = mid
        left = mid + 1  # 길이를 늘려봄
    else:
        right = mid - 1
print(f'{ans}')