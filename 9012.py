# 9012.py
import sys
input = sys.stdin.readline
def checking(p):
    stack = list()
    for i in p:
        if i == '(':
            stack.append('(')
        else:
            if len(stack):
                stack.pop()
            else:
                print("NO")
                return
    if len(stack):
        print("NO")
    else: print("YES")

T = int(input())
while T:
    p = input().strip()
    T -= 1
    checking(p)