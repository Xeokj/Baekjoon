N = int(input())
s = set()
flg = 0
for i in range(1, N):
    tmp = i
    num = i
    while tmp:  # tmp가 0보다 클 때
        num += tmp % 10
        tmp = int(tmp / 10)
    if num == N:
        print(i)
        exit(0)
print(0)