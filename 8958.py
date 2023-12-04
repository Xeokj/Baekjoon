T = int(input())
while T:
    s = input()
    stack = 0
    ans = 0
    for i in range(len(s)):
        if s[i] == 'O':
            stack += 1
            ans += stack
        else: stack = 0
    print(ans)
    T -= 1