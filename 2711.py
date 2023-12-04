T = int(input())
while T:
    N, s = input().split()
    ans = ''
    for i in range(len(s)):
        if i == (int(N) - 1):
            continue
        ans += s[i]
    print(ans)
    T -= 1